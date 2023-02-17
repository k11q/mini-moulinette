#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex02/ft_strcat.c"
#include "../../../utils/constants.h"

int test1(void)
{
	char src[] = "Network";
	char dest[] = "42 ";
	char *result;

	result = ft_strcat(dest, src);
	
	if (strcmp(result, "42 Network") != 0)
	{
		printf("    " RED "[1] ft_strcat(dest, src) output %s\n" DEFAULT, result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strcat(dest, src) output \"%s\"\n" DEFAULT, result);
	return (0);
}

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}
