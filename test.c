#include "ft_printf.h"

int main()
{
	int nmb = 42949;
	char *str = NULL;
	char c = 'a';
	char *jhj = "my %s%c bad";
	printf("\t\t%d\n", printf(jhj, str, c));
	printf("\t\t%d\n", ft_printf(jhj ,str, c));
	return (0);
}