#include <stdio.h>
#include <stdlib.h>

int* insertatlast(int a[], int n, int ele)
{
    int* new_array = malloc((n+1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        new_array[i] = a[i];
    }
    new_array[n] = ele;
    return new_array;
}
int * deleteatlast(int a[], int n)
{
    int *new=malloc((n-1)*sizeof(int));
    for(int i=0;i<n-1;i++)
    {
        new[i]=a[i];
    }
    return new;
}
int main()
{
    int n, ele;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the element you want to insert at last: ");
    scanf("%d", &ele);
    int* new_array = insertatlast(a, n, ele);
    printf("New array: ");
    for (int i = 0; i < n+1; i++) {
        printf("%d ", new_array[i]);
    }
    int *new=deleteatlast(a,n);
    printf("New array: ");
    for (int i = 0; i < n-1; i++) {
        printf("%d ", new[i]);
    }
    return 0;
}
