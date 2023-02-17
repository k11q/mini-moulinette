#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex02/ft_str_is_alpha.c"
#include "../../../utils/constants.h"

int	test1(void)
{
	if (ft_str_is_alpha("abcdefghijkl") != 1)
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
	if (ft_str_is_alpha("abcdefghijk2l") != 0)
	{
		printf("    "RED"[1] ft_str_is_uppercase(\"ABCDEFGH\") doesn\'t output 1\n");
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_str_is_uppercase(\"ABCDEFGH\") output 1\n"DEFAULT);
	return (0);
}

int	test3(void)
{
	if (ft_str_is_alpha("23adsaffq") != 0)
	{
		printf("    "RED"[1] ft_str_is_uppercase(\"ABCDEFGH\") doesn\'t output 1\n");
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_str_is_uppercase(\"ABCDEFGH\") output 1\n"DEFAULT);
	return (0);
}

int	main(void)
{
	if (test1()+test2()+test3()!=0)
		return (-1);
	return (0);
}