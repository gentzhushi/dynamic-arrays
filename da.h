#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include<stddef.h>

typedef struct vector_s vector_t;

typedef struct v_methods_s {
	void 	*(*front)	(vector_t* self);
	void 	*(*back)	(vector_t* self);

	void 	*(*at)		(vector_t* self, size_t i);
	
	void 	*(*pop_f)	(vector_t* self);
	void 	*(*pop_b)	(vector_t* self);
	
	int 	(*push_f)	(vector_t* self, void* value);
	int 	(*push_b)	(vector_t* self, void* value);
} vector_methods;

typedef struct vector_s {
	void 		*items;

	size_t 		count;
	size_t 		capacity;
	size_t 		elem_size;
	
	vector_methods 	*methods;
} vector_t;


#endif
