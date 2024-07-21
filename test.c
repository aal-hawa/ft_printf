#include "ft_printf.h"


int main()
{
	int nmb = 255;
	char *str = "cdfwsfcv";
	printf("\t\t%d\n", printf("%10u", 949675u));
	printf("\t\t%d\n",ft_printf("%10u", 949675u));
    // printf("The unsigned number is: %u\n", 4294962095U);
    // ft_printf("The unsigned number is: %u\n", 4294962095U);
	return (0);
}
