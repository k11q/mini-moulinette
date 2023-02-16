#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex09/ft_strcapitalize.c"

#define GREEN "\033[38;5;84m"
#define RED "\033[31m"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"
#define CHECKMARK "\xE2\x9C\x93"

int	test1(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	
	if (strcmp(ft_strcapitalize(str), "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un") != 0)
	{
		printf("    "RED"[1] ft_strcapitalize(\"salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un\") doesn\'t output \"Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un\"\n");
		return (-1);
	}
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_strcapitalize(\"salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un\") output \"Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un\"\n"DEFAULT);
	return (0);
}

int	main(void)
{
	if (test1()!=0)
		return (-1);
	return (0);
}