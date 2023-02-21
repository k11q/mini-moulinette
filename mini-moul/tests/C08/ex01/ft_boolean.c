#include <stdio.h>
#include "../../../../ex01/ft_boolean.h"
#include "../../../utils/constants.h"

void ft_putstr(char *str)
{
        while (*str)
                write(1, str++, 1);
}
t_bool ft_is_even(int nbr)
{
        return ((EVEN(nbr)) ? TRUE : FALSE);
}
int main(int argc, char **argv)
{
        (void)argv;
        if (ft_is_even(argc - 1) == TRUE)
                ft_putstr(EVEN_MSG);
        else
                ft_putstr(ODD_MSG);
        printf("  " GREEN CHECKMARK GREY " File was able to compile.\n" DEFAULT);
        return (SUCCESS);
}