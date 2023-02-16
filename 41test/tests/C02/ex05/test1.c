#include <stdio.h>
#include "../../../../ex05/ft_str_is_uppercase.c"

#define GREEN "\033[38;5;84m"
#define RED "\033[31m"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"
#define CHECKMARK "\xE2\x9C\x93"

int	main(void)
{
	if (ft_str_is_uppercase("ABCDEFGH") != 1)
		printf("    "RED"[1] ft_str_is_uppercase(\"ABCDEFGH\") doesn\'t output 1\n");
	else
		printf("  "GREEN CHECKMARK GREY" [1] ft_str_is_uppercase(\"ABCDEFGH\") output 1\n"DEFAULT);
	if (ft_str_is_uppercase("ABCDEFGHaI") != 0)
		printf("    "RED"[2] ft_str_is_uppercase(\"ABCDEFGHaI\") doesn\'t output 0\n"DEFAULT);
	else
		printf("  "GREEN CHECKMARK GREY" [2] ft_str_is_uppercase(\"ABCDEFGHaI\") output 0\n"DEFAULT);
	if (ft_str_is_uppercase("-_134556ABCDEFGaH67") != 0)
		printf("    "RED"[3] ft_str_is_uppercase(\"-_134556ABCDEFGaH67\") doesn\'t output 0\n"DEFAULT);
	else
		printf("  "GREEN CHECKMARK GREY" [3] ft_str_is_uppercase(\"-_134556ABCDEFGaH67\") output 0\n"DEFAULT);
	if (ft_str_is_uppercase("ABCDEFGH") != 1 || ft_str_is_uppercase("ABCDEFGHaI") != 0 || ft_str_is_uppercase("-_134556ABCDEFGaH67") != 0 )
		return (-1);
	return (0);
}