#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../../../ex07/ft_advanced_sort_string_tab.c"
#include "../../../utils/constants.h"

typedef struct s_test
{
    char *desc;
    char **tab;
    int size;
    int (*cmp)(char *, char *);
    char **expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "Sort array in ascending order",
            .tab = (char *[]){"apple", "banana", "cherry", "date", NULL},
            .size = 4,
            .cmp = &strcmp,
            .expected = (char *[]){"apple", "banana", "cherry", "date", NULL},
        },
        {
            .desc = "Sort array in descending order",
            .tab = (char *[]){"apple", "banana", "cherry", "date", NULL},
            .size = 4,
            .cmp = &rstrcmp,
            .expected = (char *[]){"date", "cherry", "banana", "apple", NULL},
        },
        {
            .desc = "Sort array ignoring case",
            .tab = (char *[]){"Apple", "banana", "Cherry", "Date", NULL},
            .size = 4,
            .cmp = &strcasecmp,
            .expected = (char *[]){"Apple", "banana", "Cherry", "Date", NULL},
        },
        {
            .desc = "Sort array by string length",
            .tab = (char *[]){"apple", "banana", "cherry", "date", NULL},
            .size = 4,
            .cmp = &strlengthcmp,
            .expected = (char *[]){"date", "apple", "cherry", "banana", NULL},
        },
        {
            .desc = "Sort empty array",
            .tab = (char *[]){NULL},
            .size = 0,
            .cmp = &strcmp,
            .expected = (char *[]){NULL},
        },
        {
            .desc = "Sort array with one element",
            .tab = (char *[]){"apple", NULL},
            .size = 1,
            .cmp = &strcmp,
            .expected = (char *[]){"apple", NULL},
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
        // Copy the original array so we can sort it
        char **tab = malloc(sizeof(char *) * (tests[i].size + 1));
        for (j = 0; j < tests[i].size; j++)
        {
            tab[j] = strdup(tests[i].tab[j]);
        }
        tab[j] = NULL;

        // Sort the array
        ft_advanced_sort_string_tab(tab, tests[i].cmp);

        // Check the result
        for (j = 0; j < tests[i].size; j++)
        {
            if (strcmp(tab[j], tests[i].expected[j]) != 0)
            {
                printf("    " RED "[%d] %s Failed\n" DEFAULT, i + 1, tests[i].desc);
                printf("        Expected: \"%s\"\n", tests[i].expected[j]);
printf(" Got: "%s"\n", tab[j]);
error--;
}
else
{
printf(" " GREEN CHECKMARK GREY " [%d] %s Passed\n" DEFAULT, i + 1, tests[i].desc);
}
free(tab[j]);
}    free(tab);
}

return error;
}

int rstrcmp(const char *s1, const char *s2)
{
return -strcmp(s1, s2);
}

int strlengthcmp(const char *s1, const char *s2)
{
size_t len1 = strlen(s1);
size_t len2 = strlen(s2);
if (len1 < len2)
{
    return -1;
}
else if (len1 > len2)
{
    return 1;
}
else
{
    return strcmp(s1, s2);
}
}
