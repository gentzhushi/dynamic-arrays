#include <stdio.h>

#define DYNAMIC_ARRAYS_IMPLEMENTATION
#include "da.h"

int main(void)
{
        char *alphabet = NULL;

        for (int i = 0; i < 26; i++)
                da_append(alphabet, i + 'A');

        for (int i = 0; i < da_len(alphabet); i++)
                printf("%c ", alphabet[i]);
        printf("\n\n");

        da_free(alphabet);
}
