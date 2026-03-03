#include <stdio.h>
#include "../ft_printf.h"

int main(void)
{
    char *s = NULL;
    int ret1;
    int ret2;

    ret1 = ft_printf("%s\n", s);
    ret2 = printf("%s\n", s);

    printf("ft_printf devuelve: %d\n", ret1);
    printf("printf devuelve:    %d\n", ret2);

    return (0);
}
