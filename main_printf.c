#include "main.h"

void print_b2uffer(char lim[], int *j);

/**
 * _printf2 - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf2(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, j = 0;
	va_list fargs;
	char lim[1024];

	if (format == NULL)
		return (-1);

	va_start(fargs, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			lim[j++] = format[i];
			if (j == 1024)
				print_b2uffer(lim, &j);
			printed_chars++;
		}
		else
		{
			print_b2uffer(lim, &j);
			flags = check_flags1(format, &i);
			width = check_width1(format, &i, fargs);
			precision = check_precision1(format, &i, fargs);
			size = check_size1(format, &i);
			++i;
			printed = flag_handler12(format, &i, fargs, lim,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_b2uffer(lim, &j);
	va_end(fargs);

	return (printed_chars);
}

/**
 * print_b2uffer - Prints the contents of the lim if it exist
 * @lim: Array of chars
 * @j: Index at which to add next char, represents the length.
 */
void print_b2uffer(char lim[], int *j)
{
	if (*j > 0)
		write(1, &lim[0], *j);

	*j = 0;
}
