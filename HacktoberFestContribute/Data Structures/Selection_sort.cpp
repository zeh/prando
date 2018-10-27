/* algorithm for selection sorting. Process :-
	1. finds index of max in arr.
	2. swaps it with index 0.
	3. finds max from arr[1] to arr[size].
	4. swaps it with index 1.
	5. and continues it upto finding max from arr[size-2] to arr[size-1].
	NOTE: SORTING IS BEING DONE IN DESCENDING ORDER!! */
int selection_sort(int* arr, int size)
{
	int max, max_ind, i;
	for( i=0 ; i<size ; i++)
	{
		max = arr[i];
		max_ind = i;
		for(int j=i; j<size ; j++ )
		{
			if(arr[j]>max)
			{
				max = arr[j];
				max_ind = j;
			}
		}
		arr[max_ind] = arr[i];
		arr[i] = max;
	}
}

/* HOW TO USE : 1. Copy the snippet in your code.
				2. Call selection_sort(array_name, array_size);
*/
