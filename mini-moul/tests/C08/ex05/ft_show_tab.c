#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "resources/ft_strs_to_tab.c"
#include "resources/ft_stock_str.h"
#include "../../../../ex05/ft_show_tab.c"
#include "../../../utils/constants.h"


int	main(int argc, char **argv)
{
	ft_show_tab(ft_strs_to_tab(argc, argv));
    printf("  " GREEN CHECKMARK GREY " File was able to compile.\n" DEFAULT);
}