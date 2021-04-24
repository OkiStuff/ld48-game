#pragma once
#include <stdio.h>
#include <stdlib.h>

void ld_free(void *ptr)
{
    free(ptr);
    ptr = NULL;
}