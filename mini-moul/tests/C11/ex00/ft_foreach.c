#include <stdio.h>
#include <stdlib.h>
#include "../../../../ex00/ft_foreach.c"
#include "../../../utils/constants.h"

typedef struct s_test
{
    char *desc;
    int *arr;
    int length;
    void (*f)(int);
} t_test;

int run_tests(t_test *tests, int count);

void print_int(int n) {
    printf("%d ", n);
}

void increment(int *n) {
    (*n)++;
}

int main(void)
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {0, -2, 4, -6, 8};
    int arr3[] = {0};

    t_test tests[] = {
        {
            .desc = "Print an array of integers",
            .arr = arr1,
            .length = 5,
            .f = &print_int,
        },
        {
            .desc = "Increment each element of an array of positive integers",
            .arr = arr1,
            .length = 5,
            .f = &increment,
        },
        {
            .desc = "Increment each element of an array of negative and positive integers",
            .arr = arr2,
            .length = 5,
            .f = &increment,
        },
        {
            .desc = "Increment the only element of an array of length 1",
            .arr = arr3,
            .length = 1,
            .f = &increment,
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
        int *arr = malloc(tests[i].length * sizeof(int));
        memcpy(arr, tests[i].arr, tests[i].length * sizeof(int));

        ft_foreach(arr, tests[i].length, tests[i].f);

        printf("  " GREEN CHECKMARK GREY " [%d] %s Output: ", i + 1, tests[i].desc);
        for (int j = 0; j < tests[i].length; j++)
        {
            printf("%d ", arr[j]);
        }
        printf("\n" DEFAULT);

        free(arr);
    }

    return error;
}

