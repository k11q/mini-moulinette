#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex06/ft_str_is_printable.c"
#include "../../../utils/constants.h"

int	test1(void)
{
	int result;

	result = ft_str_is_printable("ABDELKFSCO");
	if (result != 1)
	{
		printf("    " RED "[1] ft_str_is_printable(\"ABDELKFSCO\") Expected 1, got %d\n"DEFAULT, result);
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_str_is_printable(\"ABDELKFSCO\") Expected 1, got %d\n"DEFAULT, result);
	return (0);
}

int	test2(void)
{
	int result;

	result = ft_str_is_printable("\n\t\v\f");
	if (result != 0)
	{
		printf("    " RED "[2] ft_str_is_printable(\\\"\\n\\t\\v\\f\\\") Expected 0, got %d\n"DEFAULT, result);
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [2] ft_str_is_printable(\\\"\\n\\t\\v\\f\\\") Expected 0, got %d\n"DEFAULT, result);
	return (0);
}

int	main(void)
{
	if (test1()+test2()!=0)
		return (-1);
	return (0);
}