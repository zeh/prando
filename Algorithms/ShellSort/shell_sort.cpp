#include <iostream>

using std::cout;

void insertion_sort(int a[], int a_size) {
    int i = 0;
    while (i < a_size) {
        int j = i;
        while (j > 0 && a[j-1] > a[j]) {
            // swap
            int temp = a[j-1];
            a[j-1] = a[j];
            a[j] = temp;
            j--;
        }
        i++;
    }

    cout << "After insertion sort: ";
    for (int i = 0; i < a_size; i++) {
        cout << a[i] << " ";
    }
    cout << std:: endl;
}

void shell_sort(int a[], int a_size) {
    int gap = 1;
    while (gap < a_size/3) {
        gap = gap * 3 + 1; //calcutale biggest gap to start with.
    }

    while (gap > 0) {
        for (int i = 0; i < a_size - gap; i++) {
            if (a[i] > a[i + gap]) {
                // swap
                int temp = a[i];
                a[i] = a[i +  gap];
                a[i + gap] = temp;
            }
        }
        gap = (gap - 1) / 3;
    }

    cout << "After shell sort: ";
    for (int i = 0; i < a_size; i++) {
        cout << a[i] << " ";
    }
    cout << std:: endl;

    insertion_sort(a, a_size);
}

int main(void) {
    int a[8] = {3, 7, 4, 9, 5, 2, 6, 1};
    int a_size = sizeof(a) / sizeof(a[0]);

    shell_sort(a, a_size);

    for (int i = 0; i < a_size; i++) {
        cout << a[i] << " ";
    }
}
