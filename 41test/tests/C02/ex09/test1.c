#include <stdio.h>
#include "../../../../ex05/ft_str_is_uppercase.c"

int	main(void)
{
	if (ft_str_is_uppercase("ABCDEFGH") != 1)
		printf("ft_str_is_uppercase(\"ABCDEFGH\") doesn\'t output 1\n");
	if (ft_str_is_uppercase("ABCDEFGHaI") != 0)
		printf("ft_str_is_uppercase(\"ABCDEFGHaI\") doesn\'t output 0\n");
	if (ft_str_is_uppercase("-_134556ABCDEFGaH67") != 0)
		printf("ft_str_is_uppercase(\"-_134556ABCDEFGaH67\") doesn\'t output 0\n");
	if (ft_str_is_uppercase("ABCDEFGH") != 1 || ft_str_is_uppercase("ABCDEFGHaI") != 0 || ft_str_is_uppercase("-_134556ABCDEFGaH67") != 0 )
		return (-1);
	return (0);
}