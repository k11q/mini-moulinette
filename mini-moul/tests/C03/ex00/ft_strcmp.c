#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex00/ft_strcmp.c"
#include "../../../utils/constants.h"

typedef struct s_test
{
    char *desc;
    char *s1;
    char *s2;
    int expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "Compare two equal strings",
            .s1 = "Hello",
            .s2 = "Hello",
            .expected = 0,
        },
        {
            .desc = "Compare two different strings of equal length",
            .s1 = "Hello",
            .s2 = "He",
            .expected = 108,
        },
        {
            .desc = "Compare two different strings of different length",
            .s1 = "Hello",
            .s2 = "Hello1",
            .expected = -49,
        },
        {
            .desc = "Compare two empty strings",
            .s1 = "",
            .s2 = "",
            .expected = 0,
        },
        {
            .desc = "Compare a string with an empty string",
            .s1 = "Hello",
            .s2 = "",
            .expected = 72,
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
        int result = ft_strcmp(tests[i].s1, tests[i].s2);

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