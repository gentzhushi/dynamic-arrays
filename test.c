#include <stdio.h>

#define DYNAMIC_ARRAYS_IMPLEMENTATION
#include "da.h"

int main(void)
{
        float *farr = NULL;

        for (int i = 0; i < 300; i++)
                da_append(farr, (float)i);

        for (int i = 0; i < da_len(farr); i++)
                printf("%f\n", farr[i]);

        da_free(farr);
        return 0;
}
