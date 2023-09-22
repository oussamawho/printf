#include "main.h"


/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars
 */
int print_unsigned(va_list types, char buffer[], int flags,
	int width, int precision, int size);

/**
 * print_octal - Prints an unsigned number in octal
 * @types: Lista of arguments
 * @buffer: Buffer array
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars
 */
int print_octal(va_list types, char buffer[], int flags,
	int width, int precision, int size);

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags,
	int width, int precision, int size);

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number
 */
int print_hexa_upper(va_list types, char buffer[], int flags,
	int width, int precision, int size);

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values
 * @buffer: Buffer array
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
if (format == NULL)
return (-1);
int printed_chars = 0;
int buff_ind = 0;
char buffer[BUFF_SIZE];
va_list list;
va_start(list, format);
for (int i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
{
print_buffer(buffer, &buff_ind);
}
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
int flags, width, precision, size;
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
i++;
int printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array of chars
 * @buff_ind: Index at which to add the next char
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
{
write(1, buffer, *buff_ind);
}
*buff_ind = 0;
}
