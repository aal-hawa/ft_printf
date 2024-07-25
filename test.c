#include "ft_printf.h"


int main()
{
	int nmb = 42949;
	char *str = "hi";
	char c = 'a';
	char *jhj = "%i";
	printf("\t\t%d\n", printf(jhj, nmb));
	printf("\t\t%d\n",ft_printf(jhj,nmb));
	return (0);
}
