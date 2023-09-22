#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{

	int size = 0;
	int i = *i + 1;

	if (format[i] == 'l')
		s = S_LONG;
	else if (format[i] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = i - 1;
	else
		*i = i;

	return (s);
}
