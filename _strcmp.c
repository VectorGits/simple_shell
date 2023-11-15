#include "shell.h"

/**
 * _strcmp - compares strings
 * @str1: string to be measured
 * @str2: string to be  compared to
 * Return: ASCII val diff if unequal, 0 if equal
 */

int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0')
			return (0);
		i++;
	}
	return (str1[i] - str2[i]);
}
