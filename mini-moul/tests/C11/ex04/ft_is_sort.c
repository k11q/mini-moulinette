#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex04/ft_is_sort.c"
#include "../../../utils/constants.h"

typedef struct s_test
{
    char *desc;
    int *tab;
    int length;
    int(*f)(int, int);
    int expected;
} t_test;

int run_tests(t_test *tests, int count);

int compare(int a, int b)
{
    return a - b;
}

int main(void)
{
    t_test tests[] = {
        {
            .desc = "Empty array",
            .tab = NULL,
            .length = 0,
            .f = compare,
            .expected = 1,
        },
        {
            .desc = "Array with single element",
            .tab = (int[]){1},
            .length = 1,
            .f = compare,
            .expected = 1,
        },
        {
            .desc = "Array sorted in ascending order",
            .tab = (int[]){1, 2, 3, 4, 5},
            .length = 5,
            .f = compare,
            .expected = 1,
        },
        {
            .desc = "Array sorted in descending order",
            .tab = (int[]){5, 4, 3, 2, 1},
            .length = 5,
            .f = compare,
            .expected = 1,
        },
        {
            .desc = "Array not sorted",
            .tab = (int[]){1, 3, 2, 5, 4},
            .length = 5,
            .f = compare,
            .expected = 0,
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
        int result = ft_is_sort(tests[i].tab, tests[i].length, tests[i].f);

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

