# Vargje me gjatësi Dinamike në C

Kjo librari gjendet krejt në ***veç 1 header file***.

D.m.th. për me përdorë:
```c
#define DYNAMIC_ARRAY_IMPLEMENTATION
#include "da.h"

int main(void){
	vector_t v = new_vector(1); // madhësia në bajta, 1 bajt për char ...
	
	printf("Tu insertu: { ");
	for (int i = 0; i < 5; i++) {
		if (i == 4) printf("%d", i);
		else printf("%d, ", i);

		v.push_b(&v, &(x[i])); // push back
	}
	printf(" }\n");
	
	while (v.count){
		printf("vector.pop_back(): %d\n", *((unsigned char*)v.pop_b(&v))); // pop back
	}

	free_vector(&v); // mos harro me thirr destruktorin
}
```

Libraria përndryshe është shum e mangët. Nuk e kisha miratu përdorimin (sidomos të implementimit) të saj.

Kjo është veç si proof-of-concept, për arsye rekreacionale.

Gjithashtu është e shkrume me paragimën e OOP-së.

Nëse doni me shkrujt implementimin e sajna vet, muni veq me hjekë rreshtin `#define DYNAMIC_ARRAY_IMPLEMENTATION`. Tani muni me i implementu vet.

<img width="100%" height="auto" alt="Screenshot 2026-02-04 at 14 35 36" src="https://github.com/user-attachments/assets/860ff5d4-aadc-4089-900e-0e567b21a9d5" />
