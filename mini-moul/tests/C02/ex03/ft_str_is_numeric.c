#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex03/ft_str_is_numeric.c"
#include "../../../utils/constants.h"

int	test1(void)
{
	int result;

	result = ft_str_is_numeric("01948987493");
	if (result != 1)
	{
		printf("    " RED "[1] ft_str_is_numeric(\"01948987493\") Expected 1, got %d\n"DEFAULT, result);
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_str_is_numeric(\"01948987493\") Expected 1, got %d\n"DEFAULT, result);
	return (0);
}

int	test2(void)
{
	int result;

	result = ft_str_is_numeric("0484882j8995489");
	if (result != 0)
	{
		printf("    " RED "[2] ft_str_is_numeric(\"0484882j8995489\") Expected 0, got %d\n"DEFAULT, result);
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [2] ft_str_is_numeric(\"0484882j8995489\") Expected 0, got %d\n"DEFAULT, result);
	return (0);
}

int	test3(void)
{
	int result;

	result = ft_str_is_numeric("-_jsdsdc67sdlkc,");
	if (result != 0)
	{
		printf("    " RED "[3] ft_str_is_numeric(\"-_jsdsdc67sdlkc,\") Expected 0, got %d\n"DEFAULT, result);
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [3] ft_str_is_numeric(\"-_jsdsdc67sdlkc,\") Expected 0, got %d\n"DEFAULT, result);
	return (0);
}

int	main(void)
{
	if (test1()+test2()+test3()!=0)
		return (-1);
	return (0);
}