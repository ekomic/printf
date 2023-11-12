#include "main.h"
/**
 * flag_handler2 - Prints an argument based on its type
 * @typ: Formatted string in which to print the arguments.
 * @fargs: List of arguments to be printed.
 * @ind: ind.
 * @lim: lim array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: 1 or 2;
 */
int flag_handler2(const char *typ, int *ind, va_list fargs, char lim[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	typ_t typ_types[] = {
		{'c', print_c1}, {'s', print_s3}, {'%', print_percent3},
		{'i', print_i_d1}, {'d', print_i_d1}, {'b', print_b1},
		{'u', print_u}, {'o', print_o1}, {'x', print_x1},
		{'X', print_X1}, {'p', print_p1}, {'S', print_S2},
		{'r', print_r1}, {'R', print_R1}, {'\0', NULL}
	};
	for (i = 0; typ_types[i].typ != '\0'; i++)
		if (typ[*ind] == typ_types[i].typ)
			return (typ_types[i].fa(fargs, lim, flags, width, precision, size));

	if (typ_types[i].typ == '\0')
	{
		if (typ[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (typ[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (typ[*ind] != ' ' && typ[*ind] != '%')
				--(*ind);
			if (typ[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &typ[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
