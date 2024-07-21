#include "ft_printf.h"


int main()
{
	int nmb = 255;
	char *str = "cdfwsfcv";
	printf("\t\t%d\n", printf("%#X%x", 42, 42));
	printf("\t\t%d\n",ft_printf("%#X%x", 42, 42));
    // printf("The unsigned number is: %u\n", 4294962095U);
    // ft_printf("The unsigned number is: %u\n", 4294962095U);
	return (0);
}
