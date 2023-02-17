#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex07/ft_strupcase.c"
#include "../../../utils/constants.h"

int	test1(void)
{
	char	str[10] = "abcdefghj";
	
	if (strcmp(ft_strupcase(str), "ABCDEFGHJ") != 0)
	{
		printf("    "RED"[1] ft_strupcase(\"abcdefghj\") doesn\'t output \"ABCDEFGHJ\"\n");
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_strupcase(\"abcdefghj\") output \"ABCDEFGHJ\"\n"DEFAULT);
	return (0);
}

int	main(void)
{
	if (test1()!=0)
		return (-1);
	return (0);
}