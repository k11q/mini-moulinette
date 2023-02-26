#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex06/ft_sort_string_tab.c"
#include "../../../utils/constants.h"

typedef struct s_test
{
    char *desc;
    char **tab;
    int len;
    char **expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "Sort empty tab",
            .tab = (char *[]){"", NULL},
            .len = 0,
            .expected = (char *[]){"", NULL},
        },
        {
            .desc = "Sort tab with one element",
            .tab = (char *[]){"hello", NULL},
            .len = 1,
            .expected = (char *[]){"hello", NULL},
        },
        {
            .desc = "Sort tab with multiple elements",
            .tab = (char *[]){"hello", "world", "how", "are", "you", NULL},
            .len = 5,
            .expected = (char *[]){"are", "hello", "how", "world", "you", NULL},
        },
        {
            .desc = "Sort tab with multiple elements in descending order",
            .tab = (char *[]){"you", "world", "how", "hello", "are", NULL},
            .len = 5,
            .expected = (char *[]){"are", "hello", "how", "world", "you", NULL},
        },
        {
            .desc = "Sort tab with duplicate elements",
            .tab = (char *[]){"hello", "world", "how", "are", "hello", NULL},
            .len = 4,
            .expected = (char *[]){"are", "hello", "hello", "how", "world", NULL},
        },
        {
            .desc = "Sort tab with empty strings",
            .tab = (char *[]){"", "hello", "world", "", "how", "", "are", "", "you", NULL},
            .len = 8,
            .expected = (char *[]){"", "", "", "", "are", "hello", "how", "world", "you", NULL},
        },
    };

    int count = sizeof(tests) / sizeof(t_test);

    return run_tests(tests, count);
}

int run_tests(t_test *tests, int count)
{
    int i, j;
    int error = 0;

    for (i = 0; i < count; i++)
    {
        char **tab = (char **)malloc(sizeof(char *) * (tests[i].len + 1));
        for (j = 0; j < tests[i].len; j++)
        {
            tab[j] = strdup(tests[i].tab[j]);
        }
        tab[j] = NULL;

        ft_sort_string_tab(tab);

        for (j = 0; j < tests[i].len + 1; j++)
        {
            if (strcmp(tab[j], tests[i].expected[j]) != 0)
            {
                printf("    " RED "[%d] %s\n", i + 1, tests[i].desc);
                printf("        Expected: \"%s\"\n", tests[i].expected[j]);
                printf("        Got:      \"%s\"\n", tab[j]);
                error -= 1;
            }
        }

        free(tab);
    }

    return error;
}

