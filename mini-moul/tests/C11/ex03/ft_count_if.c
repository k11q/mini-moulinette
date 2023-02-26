#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex03/ft_count_if.c"
#include "../../../utils/constants.h"

typedef struct s_test
{
    char *desc;
    char **tab;
    int length;
    int expected;
} t_test;

int ft_starts_with_t(char *str)
{
    return *str == 't';
}

int ft_has_digit(char *str)
{
    while (*str)
    {
        if (*str >= '0' && *str <= '9')
            return 1;
        str++;
    }
    return 0;
}

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "Empty array should return 0",
            .tab = (char*[]){NULL},
            .length = 0,
            .expected = 0,
        },
        {
            .desc = "Array of all empty strings should return 0",
            .tab = (char*[]){ "", "", "", NULL },
            .length = 3,
            .expected = 0,
        },
        {
            .desc = "Array with one string starting with t",
            .tab = (char*[]){ "test", "hi", "world", NULL },
            .length = 3,
            .expected = 1,
        },
        {
            .desc = "Array with one string with digit",
            .tab = (char*[]){ "hello", "3", "world", NULL },
            .length = 3,
            .expected = 0,
        },
        {
            .desc = "Array with no strings starting with t or with digits",
            .tab = (char*[]){ "hello", "world", "foo", "bar", NULL },
            .length = 4,
            .expected = 0,
        },
        {
            .desc = "Array with all strings starting with t",
            .tab = (char*[]){ "test", "true", "Turing", "TARDIS", NULL },
            .length = 4,
            .expected = 2,
        },
        {
            .desc = "Array with all strings with digits",
            .tab = (char*[]){ "123", "456", "7890", NULL },
            .length = 3,
            .expected = 0,
        },
        {
            .desc = "Array with all strings starting with t and with digits",
            .tab = (char*[]){ "test", "textbook", "2010", "twenty-two", NULL },
            .length = 4,
            .expected = 3,
        },
    };
    int count = sizeof(tests) / sizeof(tests[0]);

    return run_tests(tests, count);
}

int run_tests(t_test *tests, int count)
{
    int i;
    int error = 0;

    for (i = 0; i < count; i++)
    {
        int result = ft_count_if(tests[i].tab, tests[i].length, &ft_starts_with_t);

        if (result != tests[i].expected)
        {
            printf("    " RED "[%d] %s Expected %d, got %d\n", i + 1, tests[i].desc, tests[i].expected, result);
            error -= 1;
        }
        else
        {
            printf("  " GREEN CHECKMARK GREY " [%d] %s Expected %d, got %d\n" DEFAULT, i + 1, tests[i].desc, tests[i].expected, result);
        }
    }

    return error;
}

