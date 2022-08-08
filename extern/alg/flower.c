#include <stdlib.h>
#include <stdio.h>

#include "flower.h"

#define FLOWER_DEFAULT_PETALS 4

typedef enum flower_colors {red, blue, green};

char* flower_color_str[] = { [red] = "red", [blue] = "blue", [green] = "green"};
char* flower_petal_count_str[] = {[0] = "zero", [1] = "one", [2] = "two", [3] = "three", [4] = "four"};

void flower_init(flower_t* flower)
{
    flower->color = red;
    flower->petals_count = FLOWER_DEFAULT_PETALS;
}

void flower_print(flower_t* flower)
{
    if(flower->petals_count == 0)
    {
        printf("%s %s petal flower;\n", flower_color_str[flower->color], flower_petal_count_str[flower->petals_count]);
        return;
    }
    printf("%d petals %s flower;\n", flower->petals_count, flower_color_str[flower->color]);
}

void flower_set_petals(flower_t* flower, int petals)
{
    flower->petals_count = petals;
}

int flower_get_petals(flower_t* flower)
{
    return flower->petals_count;
}

void flower_drop_petal(flower_t* flower)
{
    if(flower->petals_count == 0) return;
    flower->petals_count--;
}

void flower_bloom(flower_t* flower)
{
    flower->petals_count = FLOWER_DEFAULT_PETALS ;
}
