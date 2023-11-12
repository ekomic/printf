#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

#define NO(f) (void)(f)


/* FLAG OPERATORS AND SPECIALS */
#define C_MINUS 1
#define C_PLUS 2
#define C_ZERO 4
#define C_HASH 8
#define C_SPACE 16

/* DIFFERENT SIZES  */
#define C_LONG 4
#define C_SHORT 3

/**
 * struct typ - Struct op
 * @typ: The format.
 * @fa: The function associated.
 */
struct typ
{
	char typ;
	int (*fa)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct typ typ_t - Struct op
 * @typ: The format.
 * @typ_t: The function associated.
 */
typedef struct typ typ_t;

int _printf(const char *format, ...);
int flag_handler2(const char *, int *, va_list, char[], int, int, int, int);

/* Funtions to print chars and strings */
int print_c1(va_list, char[], int, int, int, int);
int print_s3(va_list, char[], int, int, int, int);
int print_percent3(va_list, char[], int, int, int, int);

/* Functions to print numbers */
int print_i_d1(va_list, char[], int, int, int, int);
int print_b1(va_list, char[], int, int, int, int);
int print_u(va_list, char[], int, int, int, int);
int print_o1(va_list, char[], int, int, int, int);
int print_x1(va_list, char[], int, int, int, int);
int print_X1(va_list, char[], int, int, int, int);
int print_fhex1(va_list, char[], char[], int, char, int, int, int);

/* Function to print non printable characters */
int print_S2(va_list, char[], int, int, int, int);

/* Funcion to print memory address */
int print_p1(va_list, char[], int, int, int, int);

/* Funciotns to handle other specifiers */
int check_flags1(const char *, int *i);
int check_width3(const char *, int *i, va_list);
int check_precision2(const char *, int *, va_list);
int check_size(const char *, int *);

/*Function to print string in reverse*/
int print_r1(va_list, char[], int, int, int, int);

/*Function to print a string in rot 13*/
int print_R1(va_list, char[], int, int, int, int);

/* special write handler */
int write_c2(char, char[], int, int, int, int);
int write_fnumb1(int, int, char[], int, int, int, int);
int write_fnum1(int, char[], int, int, int, int, char, char);
int write_p1(char lim[], int ind, int length, int, int, char, char, int);
int write_u1(int, int, char[], int, int, int, int);

/* Other Special Functions */
int can_print4(char);
int add_hexa_code2(char, char[], int);
int is_digit(char);

long int conv_size_numb2(long int, int);
long int conv_size_un5(unsigned long int, int);

#endif /* MAIN_H */
