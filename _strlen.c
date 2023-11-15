#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: string
 * Return: length of string
 */

size_t _strlen(const char *str)
{
	size_t l = 0;

	while (*str != '\0')
	{
		l++;
		str++;
	}
	return (l);
}
