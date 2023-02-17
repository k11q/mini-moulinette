#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex05/ft_str_is_uppercase.c"
#include "../../../utils/constants.h"

int	test1(void)
{
	if (ft_str_is_uppercase("ABCDEFGH") != 1)
	{
		printf("    "RED"[1] ft_str_is_uppercase(\"ABCDEFGH\") doesn\'t output 1\n");
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_str_is_uppercase(\"ABCDEFGH\") output 1\n"DEFAULT);
	return (0);
}

int	test2(void)
{
	if (ft_str_is_uppercase("ABCDEFGHaI") != 0)
	{
		printf("    "RED"[1] ft_str_is_uppercase(\"ABCDEFGHaI\") doesn\'t output 0\n");
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_str_is_uppercase(\"ABCDEFGHaI\") output 0\n"DEFAULT);
	return (0);
}

int	test3(void)
{
	if (ft_str_is_uppercase("-_134556ABCDEFGaH67") != 0)
	{
		printf("    "RED"[1] ft_str_is_uppercase(\"-_134556ABCDEFGaH67\") doesn\'t output 0\n");
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_str_is_uppercase(\"-_134556ABCDEFGaH67\") output 0\n"DEFAULT);
	return (0);
}

int	main(void)
{
	if (test1()+test2()+test3()!=0)
		return (-1);
	return (0);
}