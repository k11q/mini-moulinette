#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex00/ft_strcmp.c"
#include "../../../utils/constants.h"

int test1(void)
{
	if (ft_strcmp("Hello", "Hello1") >= 0)
	{
		printf("    " RED "[1] ft_strcmp(\"Hello\", \"Hello1\") Expected -49, got %d\n"DEFAULT, ft_strcmp("Hello", "Hello1"));
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strcmp(\"Hello\", \"Hello1\") Expected -49, got %d\n"DEFAULT, ft_strcmp("Hello", "Hello1"));
	return (0);
}

int test2(void)
{
	if (ft_strcmp("Hello", "He") <= 0)
	{
		printf("    " RED "[2] ft_strcmp(\"Hello\", \"He\") Expected 108, got %d\n" DEFAULT, ft_strcmp("Hello", "He"));
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [2] ft_strcmp(\"Hello\", \"He\") output %d\n" DEFAULT, ft_strcmp("Hello", "He"));
	return (0);
}

int test3(void)
{
	if (ft_strcmp("Hello", "Hello") != 0)
	{
		printf("    " RED "[3] ft_strcmp(\"Hello\", \"Hello\") Expected 0, got %d\n"DEFAULT, ft_strcmp("Hello", "Hello"));
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [3] ft_strcmp(\"Hello\", \"Hello\") Expected 0, got %d\n"DEFAULT, ft_strcmp("Hello", "Hello"));
	return (0);
}

int main(void)
{
	if (test1() + test2() + test3() != 0)
		return (-1);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex00/ft_strcmp.c"
#include "../../../utils/constants.h"

typedef struct	s_test
{
	char	*desc;
	char	*src;
	char	*expected;
}		t_test;

int	run_tests(t_test *tests, int count);

int	main(void)
{
	t_test tests[] = {
		{
			.desc = "ft_strcmp(\"ABCDEFGHIJK\")",
			.src = "ABCDEFGHIJK",
			.expected = "abcdefghijk"
		},
		{
			.desc = "ft_strcmp(\"agsKofnkFgbsdv\")",
			.src = "agsKofnkFgbsdv",
			.expected = "agskofnkfgbsdv"
		},
		{
			.desc = "ft_strcmp(\"23_-3FREWG4WVFSD4\")",
			.src = "23_-3FREWG4WVFSD4",
			.expected = "23_-3frewg4wvfsd4"
		},
	};
	int count = sizeof(tests) / sizeof(tests[0]);
	
	return (run_tests(tests, count));
}

int	run_tests(t_test *tests, int count)
{
    int i;
    int error = 0;

    for (i = 0; i < count; i++)
    {
        char *result = malloc(sizeof(char) * (strlen(tests[i].src) + 1));
        if (result == NULL)
        {
            perror("Error: malloc failed");
            exit(EXIT_FAILURE);
        }

        strcpy(result, tests[i].src);
        ft_strcmp(result);

        if (ft_strcmp(result, tests[i].expected) != 0)
        {
            printf("    " RED "[%d] %s Expected \"%s\", got \"%s\"\n", i + 1, tests[i].desc, tests[i].expected, result);
            error -= 1;
        }
        else
            printf("  " GREEN CHECKMARK GREY " [%d] %s Expected \"%s\", got \"%s\"\n" DEFAULT, i + 1, tests[i].desc, tests[i].expected, result);

        free(result);
    }

    return (error);
}
