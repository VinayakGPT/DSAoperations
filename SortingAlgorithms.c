#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int a[n];
    initarr(a, n);
    traversearr(a, n);
    heapsortasc(a,n);
    traversearr(a, n);
    return 0;
}
void initarr(int *a, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
void traversearr(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void bubblesortasc(int *a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        for (int j = 0; j < n - 1 - i; j++) // for number of comparisons
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void bubblesortdesc(int *a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        for (int j = 0; j < n - 1 - i; j++) // for number of comparisons
        {
            if (a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void adaptivebubblesortasc(int *a, int n)
{
    int issorted = 0;
    int temp;
    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        printf("Working on pass number %d\n", i + 1);
        issorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // for number of comparisons
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted == 1)
            return;
    }
}
void adaptivebubblesortdesc(int *a, int n)
{
    int issorted = 0;
    int temp;
    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        printf("Working on pass number %d\n", i + 1);
        issorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // for number of comparisons
        {
            if (a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted == 1)
            return;
    }
}
void insertionsortasc(int *a, int n)
{
    int key, j;
    // loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; // FOR PASS 1 - When j=-1, that is the index just before 0, put the key element, that is the original element which was to be inserted, into a[j+1], i.e., at the first position. Before that, a[i] is copied into a variable named key, and is kept safe until the work for the pass is complete.
    }
}
void insertionsortdesc(int *a, int n)
{
    int key, j;
    // loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void selectionsortasc(int *a, int n)
{
    int temp;
    for (int i = 0; i < n; i++) // for number of passes
    {
        for (int j = i + 1; j < n; j++) // for number of comparisons
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void selectionsortdesc(int *a, int n)
{
    int temp;
    for (int i = 0; i < n; i++) // for number of passes
    {
        for (int j = i + 1; j < n; j++) // for number of comparisons
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int partitionasc(int *a, int low, int high)
{
    int temp;
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp=a[low]; //When j<i, then swap pivot, i.e., a[low] with j. Also here, pivot is not used to swap, because we want the change to be reflected in the actual array and not just the variable that is pivot.
    a[low]=a[j];
    a[j]=temp;
    return j; //returned would be the index at which the pivot finally sits.
}
void quicksortasc(int *a, int low, int high)
{
    int partitionindex; // index of pivot after partition.
    if (low < high)
    { // if array has no elements, then stop.
        partitionindex = partitionasc(a, low, high);
        quicksortasc(a, low, partitionindex - 1);  // sort left subarray.
        quicksortasc(a, partitionindex + 1, high); // sort right subarray.
    }
}
int partitiondesc(int *a, int low, int high)
{
    int temp;
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (a[i] > pivot)
        {
            i++;
        }
        while (a[j] <= pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp=a[low]; //When j<i, then swap pivot, i.e., a[low] with j. Also here, pivot is not used to swap, because we want the change to be reflected in the actual array and not just the variable that is pivot.
    a[low]=a[j];
    a[j]=temp;
    return j; //returned would be the index at which the pivot finally sits.
}
void quicksortdesc(int *a, int low, int high)
{
    int partitionindex; // index of pivot after partition.
    if (low < high)
    { // if array has no elements, then stop.
        partitionindex = partitiondesc(a, low, high);
        quicksortdesc(a, low, partitionindex - 1);  // sort left subarray.
        quicksortdesc(a, partitionindex + 1, high); // sort right subarray.
    }
}
void mergeasc(int a[], int mid, int low, int high) //Is it possible to dynamically allocate memory for b?
{
    int i,j,k;
    int b[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k-low]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k-low]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        b[k-low]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        b[k-low]=a[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++)
    {
        a[i]=b[i-low];
    }
}
void mergesortasc(int a[], int low, int high)
{
    int mid;
    if(low<high){
    mid=(low+high)/2;
    mergesortasc(a,low,mid);
    mergesortasc(a,mid+1,high);
    mergeasc(a,mid,low,high);
    }
}
void mergedesc(int a[], int mid, int low, int high)
{
    int i,j,k;
    int b[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]>a[j])
        {
            b[k-low]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k-low]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        b[k-low]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        b[k-low]=a[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++)
    {
        a[i]=b[i-low];
    }
}
void mergesortdesc(int a[], int low, int high)
{
    int mid;
    if(low<high){
    mid=(low+high)/2;
    mergesortdesc(a,low,mid);
    mergesortdesc(a,mid+1,high);
    mergedesc(a,mid,low,high);
    }
}
//count sort
int findmax(int a[], int n)
{
    int max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
void countsortasc(int a[], int n)
{
    int i,j;
    int max=findmax(a,n);
    int * count=malloc((max+1)*sizeof(int));
    memset(count,0,(max+1)*sizeof(int));
    for(int i=0;i<n;i++)
    {
        count[a[i]]=count[a[i]]+1;
    }
    i=0;
    j=0;
    while(i<=max)
    {
        if(count[i]>0)
        {
            a[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
void countsortdesc(int a[], int n)
{
    int i,j;
    int max=findmax(a,n);
    int * count=malloc((max+1)*sizeof(int));
    memset(count,0,(max+1)*sizeof(int));
    for(int i=0;i<n;i++)
    {
        count[a[i]]=count[a[i]]+1;
    }
    i=0;
    j=0;
    while(i<=max)
    {
        if(count[i]>0)
        {
            a[n-j-1]=i;
            count[i]=count[i]-1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
//HEAP SORT (Concept of Binary Tree -> Limited understanding)
void heapify(int a[], int n, int i) {
    // Initialize the largest element as the root node
    int largest = i;

    // Find the left and right child nodes of the current node
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If the left child is larger than the root node, update the largest element
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    // If the right child is larger than the largest element, update the largest element
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    // If the largest element is not the root node, swap the root with the largest element
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}

void heapsortasc(int a[], int n) {
    // Build the initial max heap by calling heapify() on each non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    // Extract elements from the max heap one by one, and place them at the end of the array
    for (int i = n - 1; i >= 0; i--) {
        // Swap the root node (which contains the maximum element) with the last element in the unsorted part of the array
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        // Reduce the heap size by 1 and call heapify() on the new root to maintain the max heap property
        heapify(a, i, 0);
    }
}