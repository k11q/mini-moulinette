#include <stdio.h>
#include "../../../../ex03/ft_point.h"
#include "../../../utils/constants.h"

void set_point(t_point *point)
{
        point->x = 42;
        point->y = 21;
}
int main(void)
{
        t_point point;
        set_point(&point);
        printf("  " GREEN CHECKMARK GREY " File was able to compile.\n" DEFAULT);
        return (0);
}