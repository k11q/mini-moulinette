#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex00/ft_strcpy.c"
#include "../../../utils/constants.h"

int test1(void)
{
	char dest[12];
	char ex[12] = "FGccjqWCcYr";
	char *result;
	
	result = ft_strcpy(dest, ex);

	if (strcmp(result, "FGccjqWCcYr") != 0)
	{
		printf("    " RED "[1] ft_strcpy(dest[12], \"FGccjqWCcYr\") Expected \"FGccjqWCcYr\", got %s\n", result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY "[1] ft_strcpy(dest[12], \"FGccjqWCcYr\") Expected \"FGccjqWCcYr\", got %s\n" DEFAULT, result);
	return (0);
}

int test2(void)
{
	char dest2[40];
	char ex2[40] = "gVepWWXynLOXqCHCscGrowUZSebdZIfy";
	char *result;

	result = ft_strcpy(dest2, ex2);

	if (strcmp(result, "gVepWWXynLOXqCHCscGrowUZSebdZIfy") != 0)
	{
		printf("    " RED "[2] ft_strcpy(dest[12], \"gVepWWXynLOXqCHCscGrowUZSebdZIfy\") Expected \"gVepWWXynLOXqCHCscGrowUZSebdZIfy\", got %s\n", result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY "[2] ft_strcpy(dest[12], \"gVepWWXynLOXqCHCscGrowUZSebdZIfy\") Expected \"gVepWWXynLOXqCHCscGrowUZSebdZIfy\", got %s\n" DEFAULT, result);
	return (0);
}

int test3(void)
{
	char dest3[5];
	char ex3[5] = "TcXF";
	char *result;

	result = ft_strcpy(dest3, ex3);
	if (strcmp(result, "TcXF") != 0)
	{
		printf("    " RED "[3] ft_strcpy(dest[12], \"TcXF\") Expected \"TcXF\", got %s\n", result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY "[3] ft_strcpy(dest[12], \"TcXF\") Expected \"TcXF\", got %s\n" DEFAULT, result);
	return (0);
}

int main(void)
{
	if (test1() + test2() + test3() != 0)
		return (-1);
	return (0);
}
