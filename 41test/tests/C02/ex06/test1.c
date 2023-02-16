#include <stdio.h>
#include "../../../../ex06/ft_str_is_printable.c"

#define GREEN "\033[38;5;84m"
#define RED "\033[31m"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"
#define CHECKMARK "\xE2\x9C\x93"

int	main(void)
{
	if (ft_str_is_printable("ABDELKFSCO?I340990%") != 1)
		printf("ft_str_is_printable(\"ABDELKFSCO?I340990%\") doesn\'t output 1\n");
	else
		printf("  "GREEN CHECKMARK GREY" [1] Test 1 passed\n"DEFAULT);
	if (ft_str_is_printable("\n\t\v\f") != 0)
		printf("    "RED"[2] ft_str_is_printable(\\\"\\n\\\\t\\v\\f\\\") doesn\'t output 0\n"DEFAULT);
	else
		printf("  "GREEN CHECKMARK GREY" [2] Test 2 passed\n"DEFAULT);
	if (ft_str_is_printable("ABCDEFGH") != 1 || ft_str_is_printable("\n\t\v\f") != 0)
		return (-1);
	return (0);
}