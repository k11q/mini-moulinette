#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex04/ft_strstr.c"
#include "../../../utils/constants.h"

int test1(void)
{
	char str[] = "42 1337 Network 2021 piscine Benguerir Khouribga";
	char find[] = "piscine";

	if (strcmp(ft_strstr(str, find), "piscine Benguerir Khouribga") != 0)
	{
		printf("    " RED "[1] ft_strstr(str, find) output %s\n" DEFAULT, ft_strstr(str, find));
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strstr(str, find) output %s\n" DEFAULT, ft_strstr(str, find));
	return (0);
}

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}
