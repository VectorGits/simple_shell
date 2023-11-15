#include "shell.h"

/**
 * error_printer - Print an error message when a command is not found.
 * @command: The command that was not found.
 * @dataptr: Pointer to the shell_t structure.
 */
void error_printer(char *command, shell_t *dataptr)
{
	int num_digits = 0, temp_count = dataptr->line_count;
	char *buffer, *buffer_ptr;

	do {
		num_digits++;
		temp_count /= 10;
	} while (temp_count > 0);

	buffer = malloc(num_digits + 1);
	if (!buffer)
	{
		perror("Malloc failed");
		exit(1);
	}

	buffer[num_digits] = '\0';
	temp_count = dataptr->line_count;
	buffer_ptr = buffer + num_digits - 1;

	while (temp_count > 0)
	{
		*buffer_ptr-- = (temp_count % 10) + '0';
		temp_count /= 10;
	}

	write(STDERR_FILENO,
	      dataptr->program_name, strlen(dataptr->program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buffer, strlen(buffer));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);

	free(buffer);
	exit(127);
}
