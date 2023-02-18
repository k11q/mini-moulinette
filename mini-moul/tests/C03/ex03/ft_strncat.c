#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex03/ft_strncat.c"
#include "../../../utils/constants.h"

int test1(void)
{
	char src[] = "Network";
	char dest[] = "42 ";
	char *result;
	char *expected_output;

	result = ft_strncat(dest, src, 7);
	expected_output = "42 Network";
	if (strcmp(result, expected_output) != 0)
	{
		printf("    " RED "[1] ft_strncat(\"42\", \"Network\", 7) Expected output \"%s\", got \"%s\"\n" DEFAULT,  expected_output, result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strncat(\"42\", \"Network\", 7) Expected output \"%s\", got \"%s\"\n" DEFAULT,  expected_output, result);
	return (0);
}

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}
