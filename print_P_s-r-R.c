#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_p1 - Prints the value of a pointer variable
 * @args: List a of arguments
 * @lim: lim array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_p1(va_list args, char lim[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = 1024 - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	NO(width);
	NO(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	lim[1024 - 1] = '\0';
	NO(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		lim[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & C_ZERO) && !(flags & C_MINUS))
		padd = '0';
	if (flags & C_PLUS)
		extra_c = '+', length++;
	else if (flags & C_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &lim[i], 1024 - i - 1));*/
	return (write_p1(lim, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_S2 - Prints ascii codes in hexa of non printable chars
 * @args: Lista of arguments
 * @lim: lim array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_S2(va_list args, char lim[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	NO(flags);
	NO(width);
	NO(precision);
	NO(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (can_print4(str[i]))
			lim[i + offset] = str[i];
		else
			offset += add_hexa_code2(str[i], lim, i + offset);

		i++;
	}

	lim[i + offset] = '\0';

	return (write(1, lim, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_r1 - Prints reverse string.
 * @args: Lista of arguments
 * @lim: lim array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_r1(va_list args, char lim[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	NO(lim);
	NO(flags);
	NO(width);
	NO(size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		NO(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_R1 - Print a string in rot13.
 * @args: Lista of arguments
 * @lim: lim array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_R1(va_list args, char lim[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	NO(lim);
	NO(flags);
	NO(width);
	NO(precision);
	NO(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
