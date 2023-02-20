#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex03/ft_atoi.c"
#include "../../../utils/constants.h"

typedef struct s_test
{
    char *desc;
    char *input;
    int expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "Convert positive integer",
            .input = "12345",
            .expected = 12345,
        },
        {
            .desc = "Convert negative integer",
            .input = "-54321",
            .expected = -54321,
        },
        {
            .desc = "Convert integer with leading spaces",
            .input = "    4567",
            .expected = 4567,
        },
        {
            .desc = "Convert integer with leading plus sign",
            .input = "+6789",
            .expected = 6789,
        },
        {
            .desc = "Convert integer with non-numeric suffix",
            .input = "123abc",
            .expected = 123,
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
        int result = ft_atoi(tests[i].input);

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
