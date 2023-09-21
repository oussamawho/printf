#include "main.h"
/**
* puts - prints a string with newline
* @str: the string to print
* Return: void
*/
int _puts (char *str)
{
char *x = str;
while (*str)
__putchar (*str++);
return (stra - x);
}
/**
* _putchar - writes the character c to stdout
*@c: character
*
*Return: On success 1.
* on error, -1 is returned, and errno is set appropriately.
*/
int putchar (int c)
{
static int x;
static char buf [OUTPUT_BUF_SIZE];
if (c == BUF_FLUSH || x >= OUTPUT_BUF_SIZE)
{
write (1, buf, x);
x = 0;
}
if (c != BUF_FLUSH)
buf[x++] = c;
return (1);
}
