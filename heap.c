#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

void insertElement(int a[], int* n, int value) {
    if (*n < MAX_SIZE) {
        a[*n] = value;
        int i = *n;
        while (i > 0 && a[(i - 1) / 2] < a[i]) {
            int temp = a[i];
            a[i] = a[(i - 1) / 2];
            a[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
        (*n)++;
        printf("Element %d inserted.\n", value);
    } else {
        printf("Array is full. Cannot insert.\n");
    }
}

int deleteMax(int a[], int* n) {
    if (*n <= 0) {
        printf("Heap is empty. Cannot delete.\n");
        return -1; 
    }

    int deletedValue = a[0];
    (*n)--;
    a[0] = a[*n];
    heapify(a, *n, 0);

    return deletedValue;
}

void deleteAll(int a[], int* n) {
    printf("Deleted values:\n");
    int deletedValue;
    while (*n > 0) {
        deletedValue = deleteMax(a, n);
        if (deletedValue != -1) {
            printf("%d ", deletedValue);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the initial size of the array: ");
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0) {
        printf("Invalid array size. Exiting...\n");
        return 1; // Exit with an error code
    }

    int arr[MAX_SIZE];

    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    int value;

    do {
        printf("\nMenu:\n");
        printf("1. Heap Sort (bottom-up)\n");
        printf("2. Insert Element\n");
        printf("3. Delete Max Element\n");
        printf("4. Delete All Elements and Display\n");
        printf("5. Print Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                heapSort(arr, n);
                printf("Sorted Array using Heap Sort:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 2:
                if (n < MAX_SIZE) {
                    printf("Enter the element to insert: ");
                    scanf("%d", &value);
                    insertElement(arr, &n, value);
                } else {
                    printf("Array is full. Cannot insert.\n");
                }
                break;
            case 3:
                int deletedValue = deleteMax(arr, &n);
                if (deletedValue != -1) {
                    printf("Deleted value: %d\n", deletedValue);
                }
                break;
            case 4:
                deleteAll(arr, &n);
                break;
            case 5:
                printf("Array: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
