#include "shell.h"

/**
 * prompt_user - Display a shell prompt for interactive mode.
 * @interactive: Flag indicating whether the shell is in interactive mode.
 */
void prompt_user(int interactive)
{
	if (interactive)
	{
		write(STDOUT_FILENO, "#SimpleShell$ ", 14);
		fflush(stdout);
	}
}

/**
 * handle_exit - Handle the 'exit' command with optional exit status.
 * @line: User input containing the 'exit' command and optional status.
 *
 * Return: The exit status provided in the 'exit' command.
 */
int handle_exit(char *line)
{
	int exit_status = 0;
	char *exit_arg = _strtok(line, " \n");

	exit_arg = _strtok(NULL, " \n");
	if (exit_arg != NULL)
	{
		exit_status = _atoi(exit_arg);
	}
	return (exit_status);
}

/**
 * parse_input - Tokenize input line into an array of arguments.
 * @line: User input to tokenize.
 * @arg_count: Maximum number of arguments to allocate space for.
 *
 * Return: An array of pointers to argument strings.
 */
char **parse_input(char *line, int arg_count)
{
	int i = 0;
	char *token;
	char **args = malloc(arg_count * sizeof(char *));

	if (args == NULL)
	{
		perror("Unable to allocate memory for args");
		free(line);
		exit(1);
	}

	token = _strtok(line, " \n");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = _strtok(NULL, " \n");
	}
	args[i] = NULL;

	return (args);
}

/**
 * search_path - Search for the full path of a command in the PATH environment.
 * @command: The command to search for.
 * @dataptr: Pointer to the shell_t structure.
 *
 * Return: The full path of the command if found, or NULL if not found.
 */
char *search_path(char *command, shell_t *dataptr)
{
	char *path_copy;
	char *tok;
	char *full_path;

	if (_strchr(command, '/') != NULL && access(command, X_OK) == 0)
		return (strdup(command));
	if (dataptr->path == NULL)
		return (NULL);
	path_copy = strdup(dataptr->path);
	if (!path_copy)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	full_path = NULL;
	tok = _strtok(path_copy, ":");
	while (tok != NULL)
	{
		full_path = malloc(_strlen(tok) + _strlen(command) + 2);
		if (!full_path)
		{
			perror("Memory allocation failed");
			free(path_copy);
			return (NULL);
		}
		_strcpy(full_path, tok);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		tok = _strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * setup_shell - Initialize shell_t structure and set up signal handler.
 * @dataptr: Pointer to the shell_t structure to initialize.
 * @argv: Command-line arguments.
 */
void setup_shell(shell_t *dataptr, char **argv)
{
	dataptr->program_name = argv[0];
	dataptr->line_count = 0;
	dataptr->path = getenv("PATH");
	signal(SIGINT, sigint_handler);
}
