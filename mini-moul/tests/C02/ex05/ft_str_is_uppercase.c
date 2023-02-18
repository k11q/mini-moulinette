#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex05/ft_str_is_uppercase.c"
#include "../../../utils/constants.h"

int	test1(void)
{
	int result;

	result = ft_str_is_uppercase("ABCDEFGH");
	if (result != 1)
	{
		printf("    " RED "[1] ft_str_is_uppercase(\"ABCDEFGH\") Expected 1, got %d\n"DEFAULT, result);
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_str_is_uppercase(\"ABCDEFGH\") Expected 1, got %d\n"DEFAULT, result);
	return (0);
}

int	test2(void)
{
	int result;

	result = ft_str_is_uppercase("ABCDEFGHaI");
	if (result != 0)
	{
		printf("    " RED "[2] ft_str_is_uppercase(\"ABCDEFGHaI\") Expected 0, got %d\n"DEFAULT, result);
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [2] ft_str_is_uppercase(\"ABCDEFGHaI\") Expected 0, got %d\n"DEFAULT, result);
	return (0);
}

int	test3(void)
{
	int result;

	result = ft_str_is_uppercase("-_134556ABCDEFGaH67");
	if (result != 0)
	{
		printf("    " RED "[3] ft_str_is_uppercase(\"-_134556ABCDEFGaH67\") Expected 0, got %d\n"DEFAULT, result);
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [3] ft_str_is_uppercase(\"-_134556ABCDEFGaH67\") Expected 0, got %d\n"DEFAULT, result);
	return (0);
}

int	main(void)
{
	if (test1()+test2()+test3()!=0)
		return (-1);
	return (0);
}