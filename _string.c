#include "main.h"
/**
* get_precision - gets the precision from the format string
* @p: string
* @params: the parameters struct
* @ap: pointer
*
* Return: pointer
*/
char *get_precision (char *p, params_t *params, va_list ap)
{
int t = 0;
if (*p != '.')
return (p);
p++;
if (*p == '*')
{
t = va_arg (ap, int);
p++;
}
else
{
while (_isdigit(*p))
t = t * 10 + (*p++ - '0');
}

params->precision = t;
return (p);
}
