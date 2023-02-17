#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex08/ft_strlowcase.c"
#include "../../../utils/constants.h"

int	test1(void)
{
	char	str[10] = "ABCDEFGHJ";
	
	if (strcmp(ft_strlowcase(str), "abcdefghj") != 0)
	{
		printf("    "RED"[1] ft_strlowcase(\"ABCDEFGHJ\") doesn\'t output \"abcdefghj\"\n");
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_strlowcase(\"ABCDEFGHJ\") output \"abcdefghj\"\n"DEFAULT);
	return (0);
}

int	main(void)
{
	if (test1()!=0)
		return (-1);
	return (0);
}