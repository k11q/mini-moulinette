#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex06/ft_str_is_printable.c"
#include "../../../utils/constants.h"

int	test1(void)
{
	if (ft_str_is_printable("ABDELKFSCO?I340990%") != 1)
	{
		printf("    "RED"[1] ft_str_is_printable(\"ABDELKFSCO?I340990%\") doesn\'t output 1\n");
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_str_is_printable(\"ABDELKFSCO?I340990%\") output 1\n"DEFAULT);
	return (0);
}

int	test2(void)
{
	if (ft_str_is_printable("\n\t\v\f") != 0)
	{
		printf("    "RED"[1] ft_str_is_printable(\"\\n\\t\\v\\f\\\") doesn\'t output 0\n");
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_str_is_printable(\"\\n\\t\\v\\f\\\") output 0\n"DEFAULT);
	return (0);
}

int	main(void)
{
	if (test1()+test2()!=0)
		return (-1);
	return (0);
}