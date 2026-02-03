/**
 * DEFINIMI
 */

#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include<stddef.h>

typedef struct vector_s vector_t;

/**
 * Metodat e Vektorit
 */
typedef struct vm_s {
	void	*(*front)	(vector_t* self);
	void	*(*back)	(vector_t* self);

	void	*(*at)		(vector_t* self, size_t i);
	
	void	*(*pop_f)	(vector_t* self);
	void	*(*pop_b)	(vector_t* self);
	
	void	(*push_f)	(vector_t* self, void* value);
	void	(*push_b)	(vector_t* self, void* value);
} vm_t;

/**
 * Vektori
 */
typedef struct vector_s {
	void 			*items;

	size_t 			count;
	size_t 			capacity;
	size_t 			data_size;
	
	const		vm_t *methods;
} vector_t;

vector_t 	new_vector(size_t data_size); // 1 per char etj...
void		free_vector(vector_t *v);

#endif

/**
 * IMPLEMENTIMI
 */

#ifdef DYNAMIC_ARRAY_IMPLEMENTATION

#include<stdlib.h>
#include<stdio.h> // fshije qita ma von

/**
 * Metodat
 */
static void* v_front(vector_t *self) {
	printf("v_front");
	return NULL;
}

static void* v_back(vector_t *self) {
	printf("v_back");
	return NULL;
}

static void* v_at(vector_t *self, size_t i) {
	printf("v_at");
	return NULL;
}

static void* v_pop_f(vector_t *self) {
	printf("v_pop_front");
	return NULL;
}

static void* v_pop_b(vector_t *self) {
	printf("v_pop_back");
	return NULL;
}

static void v_push_f(vector_t *self, void *value) {
	printf("v_push_front");
}

static void v_push_b(vector_t *self, void *value) {
	printf("v_push_back");
}

/**
 * Konstruktor
 */
vector_t new_vector(size_t data_size){
	vector_t v = {0};

	v.data_size = data_size;

	v.front = v_front,
	v.back = v_back,
	
	v.at = v_at,
	
	v.pop_f = v_pop_f,
	v.pop_b = v_pop_b,

	v.push_f = v_push_f,
	v.push_b = v_push_b,

	return v;
}

/**
 * Destruktor
 */
void free_vector(vector_t *v){
	free(v->items);
	*v = (vector_t){0};
}

#endif
