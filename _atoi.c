#include "shell.h"

/**
 * _atoi - Converts a string to an integer.
 * @nptr: The string to be converted.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(const char *nptr)
{
	int i = 0;
	int result = 0;
	int sign = 1;

	if (nptr == NULL)
	{
		return (0);
	}

	while (nptr[i] == ' ')
	{
		i++;
	}

	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign = -1;
		}
		i++;
	}

	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}

	return (sign * result);
}
