/**
 * DEFINIMI
 */

#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include<stddef.h>

typedef struct vector_s vector_t;

/**
 * Vektori
 */
typedef struct vector_s {
	void 	*items;

	size_t 	count;
	size_t 	capacity;
	size_t 	data_size;
	
	void *(*front)(vector_t *self);
	void *(*back)(vector_t *self);
	void *(*at)(vector_t *self, size_t i);
	void *(*pop_f)(vector_t *self);
	void *(*pop_b)(vector_t *self);
	void (*push_f)(vector_t *self, void *value);
	void (*push_b)(vector_t *self, void *value);
} vector_t;

vector_t 	new_vector(size_t data_size); // 1 per char etj...
void		free_vector(vector_t *v);

#endif

/**
 * IMPLEMENTIMI
 */

#ifdef DYNAMIC_ARRAY_IMPLEMENTATION

#include<stdlib.h>
#include<string.h>
#include<stdio.h> // fshije qita ma von

/**
 * Metodat
 */
void* v_front(vector_t *self) {
	printf("v_front");

	if (!self || self->count == 0)
		return NULL;

	return (unsigned char*)self->items;
}

void* v_back(vector_t *self) {
	printf("v_back");

	if (!self || self->count == 0)
		return NULL;
	
	return (unsigned char*) 
		self->items + (self->count - 1) * self->data_size;
}

void* v_at(vector_t *self, size_t i) {
	printf("v_at");
	
	if (!self || self->count == 0)
		return NULL;

	return (unsigned char*)self->items + i * self->data_size;
}

void* v_pop_f(vector_t *self) {
	printf("v_pop_front");

	if (!self || self->count == 0)
		return NULL;
	
	self->count--;
	return (unsigned char*)self->items;
}

void* v_pop_b(vector_t *self) {
	printf("v_pop_back");
		
	if (!self || self->count == 0)
		return NULL;
		
	return (unsigned char*)self->items + --self->count * self->data_size;
}

void v_push_f(vector_t *self, void *value) {
	(void)self;
	(void)value;
	printf("push_front sosht i implementum.");
}

void v_push_b(vector_t *self, void *value) {
	printf("v_push_back");

	if (!self) return;

	if (self->capacity == 0){
		self->capacity = 256;
	} else if (self->count >= self->capacity){
		self->capacity *= 2;
	}

	if (self->items == NULL){
		self->items = malloc(self->capacity * self->data_size);
	} else if (self->count >= self->capacity){
		void *tmp = realloc(self->items, self->capacity * self->data_size);
		if (!tmp) {
			perror("v_push_b");
			return;
		}
		self->items = tmp;
	}

	memcpy((unsigned char*)(self->items + self->count++ * self->data_size),
			value,
			self->data_size
		);

}

/**
 * Konstruktor
 */
vector_t new_vector(size_t data_size){
	vector_t v = {0};

	v.data_size = data_size;
	
	v.front = v_front;
	v.back = v_back;
	v.at = v_at;
	v.pop_f = v_pop_f;
	v.pop_b = v_pop_b;
	v.push_f = v_push_f;
	v.push_b = v_push_b;

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
