#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex04/ft_strstr.c"
#include "../../../utils/constants.h"

int test1(void)
{
	char str[] = "42 1337 Network 2021 piscine Benguerir Khouribga";
	char find[] = "piscine";
	char *expected_output = "piscine Benguerir Khouribga";
	char *result;

	result = ft_strstr(str, find);
	if (strcmp(result, expected_output) != 0)
	{
		printf("    " RED "[1] ft_strstr(\"42 1337 Network 2021 piscine Benguerir Khouribga\", \"piscine\", 7) Expected output \"%s\", got \"%s\"\n" DEFAULT,  expected_output, result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strstr(\"42 1337 Network 2021 piscine Benguerir Khouribga\", \"piscine\", 7) Expected output \"%s\", got \"%s\"\n" DEFAULT,  expected_output, result);
	return (0);
}

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}
