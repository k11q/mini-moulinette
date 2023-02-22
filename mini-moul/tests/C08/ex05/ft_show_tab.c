#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_stock_str.h"
#include "../../../../ex05/ft_show_tab.c"
#include "../../../utils/constants.h"

int main(void)
{
    char *strings[] = {
        "Hello",
        "World",
        "",
        NULL
    };
    int size = 4;
    t_stock_str *stock_str = ft_strs_to_tab(size, strings);
    ft_show_tab(stock_str);

    printf("  " GREEN CHECKMARK GREY " File was able to compile.\n" DEFAULT);

    for (int i = 0; i < size; i++)
    {
        free(stock_str[i].copy);
    }
    free(stock_str);

    return 0;
}