#include <unistd.h>
#include <stdarg.h>
void put_str(char *str, int *len)
{
    int i = 0;
    if (!str)
        str = "(null)";
    while (str[i])
        *len += write(1, &str[i++], 1);
}
void put_num(long long num, int base, int *len)
{
    char *hexa = "0123456789abcdef";
    if (num < 0)
    {
        num *= -1;
        *len += write(1, "-", 1);
    }
    if (num >= base)
        put_num(num/base, base, len);
    *len += write(1, &hexa[num % base], 1);
}
int ft_printf(char *str, ...)
{
    int i = 0;
    int len = 0;
    va_list ptr;
    va_start(ptr, str);
    while (str[i])
    {
        if(str[i] == '%' && str[i + 1])
        {
            i++;
            if (str[i] == 's')
                put_str(va_arg(ptr, char *), &len);
            else if (str[i] == 'd')
                put_num((long long)va_arg(ptr, int), 10, &len);
            else if (str[i] == 'x')
                put_num((long long)va_arg(ptr, int), 16, &len);
        }
        else
            len += write(1, &str[i], 1);
        i++;
    }
    va_end (ptr);
    return (len);
}

// int main()
// {
//     ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// }