#include <stdio.h>
#define MAX 200
 
/* Inetrpolation search function */
int interpolation_search(int a[], int bottom, int top, int item)
{
    int mid;
    while (bottom <= top) {
        mid = bottom + (top - bottom) * ((item - a[bottom]) / (a[top] - a[bottom]));
        if (item == a[mid])
            return mid + 1;   
        if (item < a[mid])
            top = mid - 1;    
        else        
            bottom = mid + 1; 
    }     
    return -1;
}
/* End of interpolation_search() */
 
/* The main() begins */
int main()
{
    int arr[MAX];
    int i, num;
    int item, pos;
    printf("\nEnter total elements (num< %d) : ", MAX); 
    scanf("%d", &num);
    printf("Enter %d Elements in ascending order: ", num); 
    for (i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    printf("\nSearch For : ");
    scanf("%d", &item);
    pos = interpolation_search(&arr[0], 0, num - 1, item);
    if (pos == -1)
        printf("\nElement %d not found\n", item);
    else
        printf("\nElement %d found at position %d\n", item, pos);
    return 0;
}
