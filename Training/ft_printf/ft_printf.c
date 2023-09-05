#include <unistd.h>
#include <stdarg.h>

void    print_num(long long num, int base, int *len)
{
    char *hexa = "0123456789abcdef";

    if(num < 0)
    {
        num *= -1;
        write(1, "-", 1);
    }

    if(num >= base)
        print_num(num / base, base, len);
    *len += write(1, &hexa[num % base], 1);
}

void    print_str(char *str, int *len)
{
    int i = 0;

    if(!str)
        str = "(null)";

    while(str[i])
        *len += write(1, &str[i++], 1);
}

int ft_printf(const char *str, ... )
{
    int i = 0;
    int len = 0;
    va_list ptr;
    va_start(ptr, str);

    while(str[i])
    {
        if(str[i] == '%' && str[i + 1])
        {
            i++;
            if(str[i] == 's')
                print_str(va_arg(ptr, char *), &len);
            else if(str[i] == 'd')
                print_num((long long)va_arg(ptr, int), 10, &len);
            else if(str[i] == 'x')
                print_num((long long)va_arg(ptr, unsigned int), 16, &len);
        }
        else
            len += write(1, &str[i], 1);
        i++;
    }
    return len;
    va_end(ptr);
}

int main()
{
    ft_printf("Magic %s is %d try %x", "number", 42, 16);
    ft_printf("\n%d\n", 34);
    ft_printf("%d\n", -34);
    ft_printf("%x\n", 10);
    ft_printf("%s\n", "salih");
    ft_printf("sancaktar");
}