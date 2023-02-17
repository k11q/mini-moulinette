#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex03/ft_atoi.c"

#define GREEN "\033[38;5;84m"
#define RED "\033[31m"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"
#define CHECKMARK "\xE2\x9C\x93"

int test1(void)
{
	if (ft_atoi("   ---+--+01234506789ab567") != -1234506789)
	{
		printf("    " RED "[1] Expected output, got %d\n", ft_atoi("   ---+--+01234506789ab567"));
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_atoi(\"   ---+--+01234506789ab567\") output %d\n" DEFAULT, ft_atoi("   ---+--+01234506789ab567"));
	return (0);
}

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}
