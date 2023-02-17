#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex01/ft_strncpy.c"
#include "../../../utils/constants.h"

int	test1(void)
{
	char src[] = "Hello";
	char dest[] = "World1";

	if (strcmp(ft_strncpy(dest, src, 3), "Helld1") != 0)
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
	char src[] = "Hello";
	char dest[] = "World1";

	if (strcmp(ft_strncpy(dest, src, 5), "Hello1") != 0)
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
	char src[] = "Hello";
	char dest[] = "World1";

	if (strcmp(ft_strncpy(dest, src, 7), "Hello") != 0)
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