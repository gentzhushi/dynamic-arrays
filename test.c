#define DYNAMIC_ARRAY_IMPLEMENTATION
#include "da.h"

int main(void){
	vector_t v = new_vector(1);
	unsigned char x[] = {1, 2, 3, 4, 5};
	
	printf("Tu insertu: { ");
	for (int i = 0; i < 5; i++) {
		if (i == 4) printf("%d", i);
		else printf("%d, ", i);

		v.push_b(&v, &(x[i]));
	}
	printf(" }\n");
	
	while (v.count){
		printf("vector.pop_back(): %d\n", *((unsigned char*)v.pop_b(&v)));
	}

	free_vector(&v);
}
