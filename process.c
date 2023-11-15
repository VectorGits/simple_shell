#include "shell.h"

/**
 * read_line - Read a line of input from the user.
 * @line: A pointer to the buffer for the line.
 * @len: A pointer to the size of the buffer.
 */
void read_line(char **line, size_t *len)
{
	ssize_t nread = getline(line, len, stdin);

	if (nread == -1)
	{
		if (*line)
		{
			free(*line);
			*line = NULL;
		}

		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}

		exit(0);
	}

}

/**
 * check_exit_command - Check if the user entered an "exit" command.
 * @line: The input line to check.
 * Return: 1 if the command is "exit," otherwise 0.
 */
int check_exit_command(char *line)
{
	int exit_status;

	if (_strncmp(line, "exit", 4) == 0)
	{
		exit_status = handle_exit(line);
		free(line);
		exit(exit_status);
	}
	return (0);
}

/**
 * execute_command - Execute a command in a new process.
 * @args: An array of command arguments.
 * @full_path: The full path to the executable.
 */
void execute_command(char **args, char *full_path)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("err");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			exit(exit_status);
		}
	}
}

/**
 * handle_input - Handle user input.
 * @dataptr: A pointer to the shell data.
 * @line: The input line.
 * @arg_count: The maximum number of arguments.
 */
void handle_input(shell_t *dataptr, char *line, int arg_count)
{
	char *full_path;
	char **args = parse_input(line, arg_count);

	if (args[0] == NULL)
	{
		free(args);
		return;
	}

	if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		free(args);
		return;
	}

	full_path = search_path(args[0], dataptr);
	if (full_path != NULL)
	{
		execute_command(args, full_path);
		free(full_path);
	}
	else
	{
		error_printer(args[0], dataptr);
	}

	free(args);
}
