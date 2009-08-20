#ifndef __A_ARRAY__
#define __A_ARRAY__

typedef struct 
{
	unsigned int num_items;

	// Tells how many items can be stored in array without realloc.
	unsigned int allocated;
	char **values;
} a_array;

a_array array_init();
void array_add( a_array *arr, char *value );
void array_free( a_array *arr );
unsigned int array_count( a_array arr );

#endif
