# STB-style dynamic arrays library in C with generic types

This is a single-file project. In order to use it and its implementations, just copy paste this file to your project, and include it. In order to use the implementation, `#define DYNAMIC_ARRAY_IMPLEMENTATION` before you include it.

**Example usage**
```c
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
```
---
You should see the following output:

<img width="100%" height="auto" alt="Alphabet printed on screen" src="https://github.com/user-attachments/assets/a6c54f49-4834-43b5-a3bd-5c5932622f60" />
