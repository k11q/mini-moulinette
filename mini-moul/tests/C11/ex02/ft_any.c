#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex02/ft_any.c"
#include "../../../utils/constants.h"

typedef struct s_test
{
    char *desc;
    char **tab;
    int(*f)(char *);
    int expected;
} t_test;

int run_tests(t_test *tests, int count);

int starts_with_a(char *str)
{
    return (str[0] == 'a');
}

int main(void)
{
    char *tab1[] = {"apple", "orange", "banana", "pear", NULL};
    char *tab2[] = {"aardvark", "elephant", "giraffe", "lion", NULL};
    char *tab3[] = {"banana", "pear", "cherry", "peach", NULL};
    char *tab4[] = {"", "b", "c", "d", NULL};
    char *tab5[] = {NULL};
    t_test tests[] = {
        {
            .desc = "Any element starts with 'a' in tab1",
            .tab = tab1,
            .f = &starts_with_a,
            .expected = 1,
        },
        {
            .desc = "No element starts with 'a' in tab2",
            .tab = tab2,
            .f = &starts_with_a,
            .expected = 0,
        },
        {
            .desc = "One element starts with 'p' in tab3",
            .tab = tab3,
            .f = &starts_with_a,
            .expected = 0,
        },
        {
            .desc = "Empty string in tab4",
            .tab = tab4,
            .f = &starts_with_a,
            .expected = 0,
        },
        {
            .desc = "Empty array",
            .tab = tab5,
            .f = &starts_with_a,
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
        int result = ft_any(tests[i].tab, tests[i].f);

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

