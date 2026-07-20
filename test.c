#include <stdio.h>

#define DYNAMIC_ARRAYS_IMPLEMENTATION
#include "da.h"

int main(void)
{
        float *farr = NULL;

        fprintf(stderr, "Trying to append...\n");

        for (int i = 0; i < 300; i++)
                da_append(farr, (float)i);

        fprintf(stderr, "Trying to print...\n");

        for (int i = 0; i < da_len(farr); i++)
                fprintf(stderr, "%f\n", farr[i]);

        da_free(farr);
        return 0;
}
