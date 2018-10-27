#include <iostream>

using std::cout;

void quick_sort(int a[], int left, int right) {
    int i = left, j = right;
    int pivot = a[right];

    while (i <= j) {
        while (a[i] < pivot)
            i++; //carry on, this part already sorted
        while (a[j] > pivot)
            j--; //carry on, this part already sorted
        if (i <= j) { // a[i]>=pivot and a[j]<=pivot
        //swap a[i] with a[j]
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        quick_sort(a, left, j);
    if (i < right)
        quick_sort(a, i, right);
}

int main(void) {
    int a[10] = { 10, 7, 9, 4, 6, 2, 5, 6, 84, 12};
    int a_size = sizeof(a)/sizeof(a[0]);

    quick_sort(a, 0, a_size-1);

    for (int i = 0; i < a_size; i++) {
        cout << a[i] << " ";
    }
}
