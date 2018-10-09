#include <stdio.h>
#include <stdlib.h>


void heapsort(int vector[], int size);
void constructHeap(int vector[], int n);
void swap( int *element1Ptr, int *element2Ptr );

int main( void )
{
	int *vector2 = ( int *)malloc(8*sizeof(int ));
    int vector[ 8 ] = { 8, 32, 15, 5, 0, -3, 7, 9 };
    constructHeap( vector, 8 );
    heapsort(vector, 8);
    for ( int i = 0; i < 8; i++ ) printf("%-4d", vector[ i ]);
    puts("");
	vector2 = realloc(vector2, 9*sizeof(int ));
}
 
void constructHeap(int vector[], int n)
{
    int i;
    int count;
    for( count = 1; count < n; count++ )
    {
        i = count;
        while( i > 0 && vector[ i/2 ] < vector[ i ] )
        {
            swap( &vector[ i ], &vector[ i/ 2 ]);
            i /= 2;
        }
    }
}

void heapsort(int vector[], int size)
{
    while( size > 0 )
    {
        swap( &vector[0], &vector[size - 1]);
        constructHeap( vector, --size);
    } 
}

// swap
void swap( int *element1Ptr, int *element2Ptr )
{
	int hold = *element1Ptr; // temp
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}
 

