#ifndef FLOWER_H_INCLUDED
#define FLOWER_H_INCLUDED

typedef struct flower_t
{
    int color;
    int petals_count;
} flower_t;

typedef struct flower_t flower_t;

void flower_init(flower_t* flower);
void flower_print(flower_t* flower);

void flower_set_petals(flower_t* flower, int petals);
int flower_get_petals(flower_t* flower);

#endif // FLOWER_H_INCLUDED
