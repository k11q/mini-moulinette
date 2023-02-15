#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../ex00/ft_strcpy.c"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED	"\033[31m"

int	test1(void)
{
	char	dest[12];
	char	ex[12] = "FGccjqWCcYr";

	if (strcmp(ft_strcpy(dest, ex), "FGccjqWCcYr") != 0)
		return (-1);
	return (1);
}

int	test2(void)
{
	char	dest[40];
	char	ex[40] = "gVepWWXynLOXqCHCscGrowUZSebdZIfy";

	if (strcmp(ft_strcpy(dest, ex), "gVepWWXynLOXqCHCscGrowUZSebdZIfy") != 0)
		return (-1);
	return (1);
}

int	test3(void)
{
	char	dest[5];
	char	ex[5] = "TcXF";

	if (strcmp(ft_strcpy(dest, ex), "TcXF") != 0)
		return (-1);
	return (1);
}

int	main(void)
{
	if (test1() > 0)
		printf(GREEN "Test 1: OK :D\n" RESET);
	else
		printf(RED "Test 1: KO :(\n" RESET);
	if (test2() > 0)
		printf(GREEN "Test 2: OK :D\n" RESET);
	else
		printf(RED "Test 2: KO :(\n" RESET);
	if (test3() > 0)
		printf(GREEN "Test 3: OK :D\n" RESET);
	else
		printf(RED "Test 3: KO :(\n" RESET);
}
