#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "array.h"

a_array array_init()
{
	a_array arr;

	arr.num_items = 0;
	arr.allocated = 100;
	arr.values = malloc( arr.allocated * sizeof( char * ) );

	return arr;
}

void array_add( a_array *arr, char *value )
{
	// Is there enough allocated memory for new item?
	// If not, allocate new memory with realloc
	if( arr->num_items + 1 > arr->allocated )
	{
		printf( "Reallocating!\n" );
		int new_size = ( 2 * arr->num_items ) * sizeof( char * );
		arr->values = (char **) realloc( arr->values, new_size );
		arr->allocated = 2 * arr->num_items;
	}

	// Copy value to array
	arr->values[arr->num_items] = malloc( strlen( value ) +1 );
	strcpy( arr->values[arr->num_items], value );
	arr->num_items++;
}

void array_free( a_array *arr )
{
	int i;

	for( i=0; i < arr->num_items; i++ )
		free( arr->values[i] );

	free( arr->values );
}

unsigned int array_count( a_array arr )
{
	return arr.num_items;
}
