#include "util.h"

void initalize_srand()
{
    time_t t;
    t = time(&t);
    srand((unsigned) t);
}

int randomize(int min, int max)
{
    return ((rand() % max) + min);
}