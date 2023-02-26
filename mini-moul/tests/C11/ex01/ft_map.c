#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex01/ft_map.c"
#include "../../../utils/constants.h"

typedef struct s_test
{
    char *desc;
    int *input;
    int length;
    int (*f)(int);
    int expected[5];
} t_test;

int run_tests(t_test *tests, int count);

int multiply_by_2(int n)
{
    return n * 2;
}

int abs(int n)
{
	if(n < 0)
		return (n * -1);
	return (n);
}

int main(void)
{
    t_test tests[] = {
        {
            .desc = "Apply function to each element of array",
            .input = (int[]){1, 2, 3, 4, 5},
            .length = 5,
            .f = &multiply_by_2,
            .expected = {2, 4, 6, 8, 10},
        },
        {
            .desc = "Apply function to an array of one element",
            .input = (int[]){10},
            .length = 1,
            .f = &multiply_by_2,
            .expected = {20},
        },
        {
            .desc = "Apply function to an empty array",
            .input = (int[]){},
            .length = 0,
            .f = &multiply_by_2,
            .expected = {},
        },
        {
            .desc = "Apply a different function to an array",
            .input = (int[]){1, 2, 3, 4, 5},
            .length = 5,
            .f = &abs,
            .expected = {1, 2, 3, 4, 5},
        },
    };
    int count = sizeof(tests) / sizeof(tests[0]);

    return run_tests(tests, count);
}

int run_tests(t_test *tests, int count)
{
    int i, j;
    int error = 0;

    for (i = 0; i < count; i++)
    {
        int *result = ft_map(tests[i].input, tests[i].length, tests[i].f);

        for (j = 0; j < tests[i].length; j++)
        {
            if (result[j] != tests[i].expected[j])
            {
                printf("    " RED "[%d.%d] %s\n", i + 1, j + 1, tests[i].desc);
                printf("        Expected %d, but got %d\n", tests[i].expected[j], result[j]);
                error--;
            }
            else
            {
                printf("  " GREEN CHECKMARK GREY " [%d.%d] %s\n", i + 1, j + 1, tests[i].desc);
            }
        }

        free(result);
    }

    return error;
}

