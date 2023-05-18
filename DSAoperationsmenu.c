#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void traversearr(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void revarr(int *a, int n)
{
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
    for (int j = 0; j < n; j++)
    {
        printf("%d ", a[j]);
    }
}
void mergearr(int a[], int b[], int n1, int n2)
{
    for (int i = 0; i < n2; i++)
    {
        a[n1 + i] = b[i];
    }
    printf("Merged array is : \n");
    traversearr(a, n1 + n2);
}
void deleteelementa(int a[], int *n, int ele)
{
    int count = 0;
    for (int k = 0; k < *n; k++)
    {
        if (a[k] == ele)
            count++;
    }

    if (count == 1)
    {
        int i = 0;
        while (i < *n && a[i] != ele)
        {
            i++;
        }

        if (i == *n)
        {
            printf("Element not found in array!");
            return;
        }

        for (int j = i; j < *n - 1; j++)
        {
            a[j] = a[j + 1];
        }
        (*n)--;
    }
    else
    {
        printf("Element not found in array!");
        return;
    }

    for (int i = 0; i < *n; i++)
    {
        printf("%d ", a[i]);
    }
}
void deleteatpositiona(int a[], int *n, int position)
{
    printf("\n");
    for (int i = 0; i < *n; i++)
    {
        if (a[i] == a[position - 1])
            continue;
        else
            printf("%d ", a[i]);
    }
}
void insertatpositiona(int a[], int position, int ele, int *n)
{
    for (int i = *n; i >= position; i--)
    {
        a[i] = a[i - 1];
    }
    a[position - 1] = ele;
}
int findmin(int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
    }
    return min;
}
int *createarray(int n)
{
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    return a;
}
void deletearray(int *a)
{
    free(a);
}
int *insertatlasta(int a[], int n, int ele)
{
    int *new_array = malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        new_array[i] = a[i];
    }
    new_array[n] = ele;
    return new_array;
}
int *deleteatlasta(int a[], int n)
{
    int *new = malloc((n - 1) * sizeof(int));
    for (int i = 0; i < n - 1; i++)
    {
        new[i] = a[i];
    }
    return new;
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
    temp = a[low]; // When j<i, then swap pivot, i.e., a[low] with j. Also here, pivot is not used to swap, because we want the change to be reflected in the actual array and not just the variable that is pivot.
    a[low] = a[j];
    a[j] = temp;
    return j; // returned would be the index at which the pivot finally sits.
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
    temp = a[low]; // When j<i, then swap pivot, i.e., a[low] with j. Also here, pivot is not used to swap, because we want the change to be reflected in the actual array and not just the variable that is pivot.
    a[low] = a[j];
    a[j] = temp;
    return j; // returned would be the index at which the pivot finally sits.
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
void mergeasc(int a[], int mid, int low, int high) // Is it possible to dynamically allocate memory for b?
{
    int i, j, k;
    int b[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k - low] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k - low] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k - low] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k - low] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i - low];
    }
}
void mergesortasc(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesortasc(a, low, mid);
        mergesortasc(a, mid + 1, high);
        mergeasc(a, mid, low, high);
    }
}
void mergedesc(int a[], int mid, int low, int high)
{
    int i, j, k;
    int b[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] > a[j])
        {
            b[k - low] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k - low] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k - low] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k - low] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i - low];
    }
}
void mergesortdesc(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesortdesc(a, low, mid);
        mergesortdesc(a, mid + 1, high);
        mergedesc(a, mid, low, high);
    }
}
int findmax(int *a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
void countsortasc(int a[], int n)
{
    int i, j;
    int max = findmax(a, n);
    int *count = malloc((max + 1) * sizeof(int));
    memset(count, 0, (max + 1) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    i = 0;
    j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
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
    int i, j;
    int max = findmax(a, n);
    int *count = malloc((max + 1) * sizeof(int));
    memset(count, 0, (max + 1) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    i = 0;
    j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[n - j - 1] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
// HEAP SORT (Concept of Binary Tree -> Limited understanding)
void heapify(int a[], int n, int i)
{
    // Initialize the largest element as the root node
    int largest = i;

    // Find the left and right child nodes of the current node
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If the left child is larger than the root node, update the largest element
    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }

    // If the right child is larger than the largest element, update the largest element
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }

    // If the largest element is not the root node, swap the root with the largest element
    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}

void heapsortasc(int a[], int n)
{
    // Build the initial max heap by calling heapify() on each non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    // Extract elements from the max heap one by one, and place them at the end of the array
    for (int i = n - 1; i >= 0; i--)
    {
        // Swap the root node (which contains the maximum element) with the last element in the unsorted part of the array
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        // Reduce the heap size by 1 and call heapify() on the new root to maintain the max heap property
        heapify(a, i, 0);
    }
}
int binsearch(int a[], int ele, int n)
{
    int mid, high, low;
    high = n - 1;
    low = 0;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (ele == a[mid])
            return mid;
        else if (ele > a[mid])
            low = mid + 1;
        else if (ele < a[mid])
            high = mid - 1;
    }
    return -1;
}
struct node
{
    int data;
    struct node *next;
};

void printlist(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node *push(struct node *head, int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}
struct node *mergell(struct node *s1, struct node *s2)
{
    struct node *temp = s1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = s2;
    return s1;
}
void displayodd(struct node *head)
{
    struct node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        if (count % 2 != 0)
        {
            printf("%d ", temp->data);
        }
        temp = temp->next;
        count++;
    }
}
void displayeven(struct node *head)
{
    struct node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        if (count % 2 == 0)
        {
            printf("%d ", temp->data);
        }
        temp = temp->next;
        count++;
    }
}
struct node *reverselist(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *nextnode = NULL;

    while (current != NULL)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    return prev;
}
struct node *insertatbeginning(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return head;
}
struct node *insertatindex(struct node *head, int val, int index)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if (index == 0)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        struct node *current = head;
        struct node *prev = NULL;
        int i = 0;
        while (i < index && current != NULL)
        {
            prev = current;
            current = current->next;
            i++;
        }
        if (i == index)
        {
            prev->next = newnode;
            newnode->next = current;
        }
        else
        {
            printf("Invalid index\n");
        }
    }
    return head;
}

struct node *insertlast(struct node *head, int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
    }
    return head;
}

struct node *insertafternode(struct node *head, struct node *prevnode, int val)
{
    if (prevnode == NULL)
    {
        printf("Previous node cannot be NULL\n");
        return head;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = prevnode->next;
    prevnode->next = newnode;

    return head;
}

struct node *deletefirst(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

struct node *deleteatindex(struct node *head, int index)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return head;
    }

    if (index == 0)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        struct node *current = head;
        struct node *prev = NULL;
        int i = 0;
        while (i < index && current != NULL)
        {
            prev = current;
            current = current->next;
            i++;
        }
        if (current != NULL)
        {
            prev->next = current->next;
            free(current);
        }
        else
        {
            printf("Invalid index\n");
        }
    }
    return head;
}

struct node *deletelast(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *current = head;
        struct node *prev = NULL;
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current);
    }
    return head;
}

struct node *deletevalue(struct node *head, int value)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return head;
    }

    if (head->data == value)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        struct node *current = head;
        struct node *prev = NULL;
        while (current != NULL && current->data != value)
        {
            prev = current;
            current = current->next;
        }
        if (current != NULL)
        {
            prev->next = current->next;
            free(current);
        }
        else
        {
            printf("Value not found in the linked list\n");
        }
    }
    return head;
}
struct node *getmid(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;
    struct node *temp = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (temp != NULL)
    {
        temp->next = NULL;
    }
    return slow;
}
struct node *merge(struct node *left, struct node *right)
{
    struct node merged;
    struct node *mergeadd = &merged;
    while (left != NULL && right != NULL)
    {
        if (left->data <= right->data)
        {
            mergeadd->next = left;
            left = left->next;
        }
        else
        {
            mergeadd->next = right;
            right = right->next;
        }
        mergeadd = mergeadd->next;
    }
    if (left != NULL)
    {
        mergeadd->next = left;
    }
    else
    {
        mergeadd->next = right;
    }
    return merged.next;
}
struct node *mergesort(struct node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct node *mid = getmid(head);
    struct node *left = mergesort(head);
    struct node *right = mergesort(mid);
    return merge(left, right);
}
struct node *bubblesort(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int swapped;
    struct node *current;
    struct node *prev = NULL;
    do
    {
        swapped = 0;
        current = head;
        while (current->next != prev)
        {
            if (current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        prev = current;

    } while (swapped);
    return head;
}
void search(struct node *head, int value)
{
    struct node *current = head;
    int found = 0;
    int pos = 0;

    while (current != NULL)
    {
        pos++;
        if (current->data == value)
        {
            found = 1;
            break;
        }
        current = current->next;
    }

    if (found)
    {
        printf("Value %d found at position %d\n", value, pos);
    }
    else
    {
        printf("Value not found in the linked list\n");
    }
}
void printreverse(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    printreverse(head->next);
    printf("%d ", head->data);
}
struct dnode
{
    int data;
    struct dnode *prev;
    struct dnode *next;
};
struct dnode *createnode(int value)
{
    struct dnode *newnode = (struct dnode *)malloc(sizeof(struct dnode));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void traversedll(struct dnode *head)
{
    struct dnode *ptr = (struct dnode *)malloc(sizeof(struct dnode));
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void revtraversal(struct dnode *head)
{
    struct dnode *ptr = malloc(sizeof(struct dnode));
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    } while (ptr != NULL);
    printf("\n");
}

struct dnode *insertfirstd(struct dnode *head, int a)
{
    struct dnode *ptr = malloc(sizeof(struct dnode));
    ptr->data = a;
    ptr->prev = NULL;
    ptr->next = head;
    if (head != NULL)
    {
        head->prev = ptr;
    }
    return ptr;
}

struct dnode *insertatindexd(struct dnode *head, int index, int a)
{
    struct dnode *ptr = head;
    struct dnode *p = malloc(sizeof(struct dnode));
    p->data = a;
    int i = 0;
    while (i != index - 1 && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    if (ptr == NULL)
    {
        printf("Index out of bounds\n");
        return head;
    }
    struct dnode *pt = ptr->next;
    p->next = pt;
    p->prev = ptr;
    if (pt != NULL)
    {
        pt->prev = p;
    }
    ptr->next = p;
    if (index == 0)
    {
        return p;
    }
    return head;
}

struct dnode *insertlastd(struct dnode *head, int a)
{
    struct dnode *ptr = head;
    struct dnode *p = malloc(sizeof(struct dnode));
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    p->data = a;
    p->prev = ptr;
    ptr->next = p;
    p->next = NULL;
    return head;
}

struct dnode *deletefirstd(struct dnode *head)
{
    struct dnode *ptr = head->next;
    head = ptr;
    head->next = ptr->next;
    head->prev = NULL;
    return head;
}

struct dnode *deleteatindexd(struct dnode *head, int index)
{
    struct dnode *p = head;
    struct dnode *ptr = p->next;
    int i = 0;
    while (i != index - 1 && p != NULL)
    {
        p = p->next;
        ptr = ptr->next;
        i++;
    }
    if (p == NULL)
    {
        printf("Index out of bounds\n");
        return head;
    }
    struct dnode *pt = ptr->next;
    p->next = ptr->next;
    if (pt != NULL)
    {
        pt->prev = p;
    }
    free(ptr);
    return head;
}

struct dnode *deletelastd(struct dnode *head)
{
    struct dnode *ptr = head;
    struct dnode *p = head->next;
    while (p->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return head;
}

struct cnode
{
    int data;
    struct cnode *next;
};

struct cnode *createnodec(int value)
{
    struct cnode *newnode = (struct cnode *)malloc(sizeof(struct cnode));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

struct cnode *createcll(int size)
{
    struct cnode *head = NULL;

    for (int i = 0; i < size; i++)
    {
        int value;
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &value);

        struct cnode *newnode = createnodec(value);

        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            struct cnode *current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            current->next = newnode;
            newnode->next = head;
        }
    }

    return head;
}

void linkedlisttraversalc(struct cnode *head)
{
    struct cnode *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
struct cnode *insertfirstc(struct cnode *head, int a)
{
    struct cnode *ptr = (struct cnode *)malloc(sizeof(struct cnode));
    ptr->data = a;
    struct cnode *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct cnode *insertatindexc(struct cnode *head, int a, int index)
{
    struct cnode *p = (struct cnode *)malloc(sizeof(struct cnode *));
    struct cnode *ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    p->data = a;
    p->next = ptr->next;
    ptr->next = p;
    return head;
}

struct cnode *insertlastc(struct cnode *head, int a)
{
    struct cnode *p = (struct cnode *)malloc(sizeof(struct cnode *));
    struct cnode *ptr = head;
    p->data = a;
    do
    {
        ptr = ptr->next;
    } while (ptr->next != head);
    ptr->next = p;
    p->next = head;
    return head;
}

struct cnode *insertafternodec(struct cnode *head, struct cnode *prevnode, int a)
{
    struct cnode *p = (struct cnode *)malloc(sizeof(struct cnode *));
    p->data = a;
    p->next = prevnode->next;
    prevnode->next = p;
    return head;
}

struct cnode *deletefirstc(struct cnode *head)
{
    if (head == NULL)
    {
        return NULL; // list is empty
    }
    if (head->next == head)
    {
        free(head); // list has only one element
        return NULL;
    }
    struct cnode *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = head->next;
    head = head->next;
    return head;
}

struct cnode *deleteatindexc(struct cnode *head, int index)
{
    struct cnode *ptr = head;
    struct cnode *p = head->next;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    free(p);
    p = NULL;
    return head;
}
struct cnode *deletelastc(struct cnode *head)
{
    struct cnode *ptr = head;
    struct cnode *p = head->next;
    int i = 0;
    while (p->next != head)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = head;
    free(p);
    p = NULL;
    return head;
}
struct cnode *deletevaluec(struct cnode *head, int value)
{
    struct cnode *ptr = head;
    struct cnode *p = head->next;
    if (head->data == value)
    { // delete the head node
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = head->next;
        free(head);
        head = p->next;
    }
    else
    { // delete a non-head node
        while (p->data != value && p != head)
        {
            ptr = ptr->next;
            p = p->next;
        }
        if (p->data == value)
        {
            ptr->next = p->next;
            free(p);
            p = NULL;
        }
    }
    return head;
}
typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;
typedef struct stackl
{
    int data;
    struct stackl *next;
} stackl;
int isempty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int isfull(stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    else
        return 0;
}
void pushelement(stack *s, int val)
{
    if (isfull(s))
    {
        printf("Stack overflow. Cannot push %d in stack.", val);
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}
int popelement(stack *s)
{
    if (isempty(s))
    {
        printf("Stack underflow. The stack is empty!\n");
        return -1;
    }
    else
    {
        int temp = s->arr[s->top];
        s->top--;
        return temp;
    }
}
void displaystack(stack *s)
{
    if (isempty(s))
    {
        printf("Stack underflow. The stack is empty!\n");
    }
    else
    {
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->arr[i]);
        }
    }
}
void peek(stack *s, int pos)
{
    if (s->top - pos + 1 < 0)
        printf("Invalid entry. No such position exists!\n");
    else if (isempty(s))
        printf("Stack underflow! Stack is empty.\n");
    else
        printf("The value at the given position is %d ", s->arr[s->top - pos + 1]);
}
void stacktop(stack *s)
{
    if (isempty(s))
        printf("Stack underflow! Stack is empty.\n");
    else
        printf("The element at the top is : %d ", s->arr[s->top]);
}
void stackbottom(stack *s)
{
    if (isempty(s))
        printf("Stack underflow! Stack is empty.\n");
    else
        printf("The element at the bottom is : %d ", s->arr[0]);
}
int isemptyl(stackl *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
}
int isfulll(stackl *top)
{
    stackl *ptr = (stackl *)malloc(sizeof(stackl));
    if (ptr == NULL)
    {
        return 1;
    }
    else
        return 0;
}
stackl *pushl(stackl *top, int val)
{
    if (isfulll(top))
    {
        printf("Stack overflow! Stack is full.\n");
    }
    else
    {
        stackl *node = (stackl *)malloc(sizeof(stackl));
        node->data = val;
        node->next = top;
        top = node;
    }
    return top;
}
int popl(stackl **top)
{
    if (isemptyl(*top))
    {
        printf("Stack underflow. Stack is empty!\n");
        return -1;
    }
    else
    {
        stackl *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}
void displaystackl(stackl *top)
{
    if (isemptyl(top))
        printf("Stack underflow. Stack is empty!\n");
    else
    {

        printf("Stack is : \n");
        while (top != NULL)
        {
            printf("%d\n", top->data);
            top = top->next;
        }
    }
}
void peekl(stackl *top, int pos)
{
    if (isemptyl(top))
        printf("Stack Underflow. Stack is empty!\n");
    else
    {
        stackl *temp = top;
        for (int i = 0; temp != NULL && i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
            printf("Invalid entry. No such position exists!\n");
        else
            printf("The element at position %d is %d", pos, temp->data);
    }
}
void stackltop(stackl *top)
{
    if (isemptyl(top))
        printf("Stack underflow! Stack is empty.");
    else
        printf("The element at the top of the stack is %d", top->data);
}
void stacklbottom(stackl *top)
{
    if (isemptyl(top))
        printf("Stack underflow! Stack is empty.");
    else
    {
        stackl *temp = top;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("The element at the bottom of the stack is %d", temp->data);
    }
}
typedef struct
{
    int size;
    int front;
    int rear;
    int *arr;
} queue;
struct qnode
{
    int data;
    struct qnode *next;
};
typedef struct
{
    int size;
    int front;
    int rear;
    int *arr;
} deque;
struct qnode *f = NULL;
struct qnode *r = NULL;
int isfullq(queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
int isemptyq(queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(queue *q, int ele)
{
    if (isfullq(q))
    {
        printf("Queue is full!");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = ele;
    }
}
int dequeue(queue *q)
{
    int a = -1;
    if (isemptyq(q))
    {
        printf("Queue is empty!");
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}
void displayq(queue *q)
{
    if (isemptyq(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void firstval(queue *q)
{
    printf("%d is the first value of the queue. \n", q->arr[q->front]);
}
void lastval(queue *q)
{
    printf("%d is the last value of the queue. \n", q->arr[q->rear]);
}
int isfullcq(queue *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    else
        return 0;
}
int isemptycq(queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
        return 0;
}
void cenqueue(queue *q, int ele)
{
    if (isfullcq(q))
    {
        printf("Queue is full!");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = ele;
        printf("Element %d successfully enqueued!\n", ele);
    }
}
int cdequeue(queue *q)
{
    int a = -1;
    if (isemptycq(q))
    {
        printf("Queue is empty!");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        a = q->arr[q->front];
    }
    return a;
}
void displaycq(queue *q)
{
    if (isemptycq(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front + 1;
    printf("Queue elements: ");
    do
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    } while (i != (q->rear + 1) % q->size);
}
void displaylqueue(struct qnode *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void lenqueue(int val)
{
    struct qnode *nnode = (struct qnode *)malloc(sizeof(struct qnode));
    if (nnode == NULL)
    {
        printf("Queue is Full"); // memory not allocated from heap means that there is no space left.
    }
    else
    {
        nnode->data = val;
        nnode->next = NULL;
        if (f == NULL)
        {
            f = r = nnode;
        }
        else
        {
            r->next = nnode;
            r = nnode;
        }
    }
}
int ldequeue()
{
    int a = -1;
    struct qnode *ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        f = f->next;
        a = ptr->data;
        free(ptr);
    }
    return a;
}
void SSenqueue(stack *s1, int val)
{
    if (isfull(s1))
    {
        printf("Queue is full. Cannot enqueue %d.\n", val);
    }
    else
    {
        pushelement(s1, val);
        printf("%d enqueued to the queue.\n", val);
    }
}
int SSdequeue(stack *s1, stack *s2)
{
    int x = -1;
    if (isempty(s2) && isempty(s1))
    {
        printf("Queue is empty!");
        return x;
    }
    else
    {
        int index = s1->top;
        while (index >= 0)
        {
            pushelement(s2, popelement(s1));
            index--;
        }
        x = popelement(s2);
        return x;
    }
}
void SSdisplayq(stack *s1, stack *s2)
{
    if (isempty(s1) && isempty(s2))
    {
        printf("Queue is empty!\n");
        return;
    }
    while (!isempty(s1))
    {
        pushelement(s2, popelement(s1));
    }

    int index = s2->top;
    while (index >= 0)
    {
        printf("%d ", s2->arr[index]);
        index--;
    }
    printf("\n");
}
int isfulldeq(deque *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
int isemptydeq(deque *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
        return 0;
}
void enqueuer(deque *q, int ele)
{
    if (isfulldeq(q))
    {
        printf("Queue is full!");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = ele;
    }
}
void enqueuef(deque *q, int ele)
{
    if (isfulldeq(q))
    {
        printf("Queue is full!");
    }
    else
    {
        q->front++;
        for (int i = q->rear; i > q->front - 1; i--)
            q->arr[i + 1] = q->arr[i];
        q->arr[q->front] = ele;
        q->front--;
        q->rear++;
    }
}
int dequeuef(deque *q)
{
    int a = -1;
    if (isemptydeq(q))
    {
        printf("Queue is empty!");
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}
int dequeuer(deque *q)
{
    int a = -1;
    if (isemptydeq(q))
    {
        printf("Queue is empty!");
    }
    else
    {
        a = q->arr[q->rear];
        q->rear--;
    }
    return a;
}
void displaydeq(deque *q)
{
    if (isemptydeq(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
int main()
{
    int mainchoice, subchoice1, subchoice2, subchoice3, subsubchoice1, value, index;
    do
    {
        printf("Menu:\n");
        printf("1. Array\n");
        printf("2. Singly Linked List\n");
        printf("3. Doubly Linked List\n");
        printf("4. Circular Linked List\n");
        printf("5. Stack\n");
        printf("6. Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mainchoice);

        switch (mainchoice)
        {
        case 1:
            printf("Array chosen. \n");
            int n1, m;
            printf("Enter the size of the array: \n");
            scanf("%d", &n1);
            int *arr = createarray(n1);
            do
            {
                printf("\nMenu:\n");
                printf("1. Traverse the array\n");
                printf("2. Reverse the array\n");
                printf("3. Merge two arrays\n");
                printf("4. Delete an element from the array\n");
                printf("5. Delete an element at a given position\n");
                printf("6. Insert an element at a given position\n");
                printf("7. Find the maximum element\n");
                printf("8. Find the minimum element\n");
                printf("9. Delete the array\n");
                printf("10. Insert an element at the end of the array\n");
                printf("11. Delete an element from the end of the array\n");
                printf("12. Sort the array\n");
                printf("13. Perform binary search (choose only if array is sorted)\n");
                printf("0. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &subchoice1);

                switch (subchoice1)
                {
                case 1:
                    printf("The array is : \n");
                    traversearr(arr, n1);
                    break;
                case 2:
                    printf("The reversed array is : \n");
                    revarr(arr, n1);
                    break;
                case 3:
                    int m;
                    printf("Enter the size of the second array: ");
                    scanf("%d", &m);
                    int *arr2 = createarray(m);
                    mergearr(arr, arr2, n1, m);
                    deletearray(arr2);
                    break;
                case 4:
                {
                    int element;
                    printf("Enter the element to delete: ");
                    scanf("%d", &element);
                    deleteelementa(arr, &n1, element);
                    printf("\nElement deleted successfully.\n");
                    break;
                }
                case 5:
                {
                    int position;
                    printf("Enter the position of the element to delete: ");
                    scanf("%d", &position);
                    deleteatpositiona(arr, &n1, position);
                    printf("Element at given position deleted successfully.\n");
                    break;
                }
                case 6:
                {
                    int position, element;
                    printf("Enter the position to insert: ");
                    scanf("%d", &position);
                    printf("Enter the element to insert: ");
                    scanf("%d", &element);
                    insertatpositiona(arr, position, element, &n1);
                    printf("Element inserted at given position successfully.\n");
                    break;
                }
                case 7:
                {
                    int max = findmax(arr, n1);
                    printf("Maximum element: %d\n", max);
                    break;
                }
                case 8:
                {
                    int min = findmin(arr, n1);
                    printf("Minimum element: %d\n", min);
                    break;
                }
                case 9:
                    deletearray(arr);
                    printf("Array deleted successfully.\n");
                    break;
                case 10:
                {
                    int element;
                    printf("Enter the element to insert at the end: ");
                    scanf("%d", &element);
                    arr = insertatlasta(arr, n1, element);
                    n1++;
                    printf("Element inserted at end successfully.\n");
                    break;
                }
                case 11:
                    arr = deleteatlasta(arr, n1);
                    n1--;
                    printf("Element deleted at end successfully.\n");
                    break;
                case 12:
                    do
                    {
                        printf("\n----- Sorting Menu -----\n");
                        printf("1. Bubble Sort (Ascending)\n");
                        printf("2. Bubble Sort (Descending)\n");
                        printf("3. Adaptive Bubble Sort (Ascending)\n");
                        printf("4. Adaptive Bubble Sort (Descending)\n");
                        printf("5. Insertion Sort (Ascending)\n");
                        printf("6. Insertion Sort (Descending)\n");
                        printf("7. Selection Sort (Ascending)\n");
                        printf("8. Selection Sort (Descending)\n");
                        printf("9. Quick Sort (Ascending)\n");
                        printf("10. Quick Sort (Descending)\n");
                        printf("11. Merge Sort (Ascending)\n");
                        printf("12. Merge Sort (Descending)\n");
                        printf("13. Count Sort (Ascending)\n");
                        printf("14. Count Sort (Descending)\n");
                        printf("15. Heap Sort (Ascending)\n");
                        printf("0. Exit\n");

                        printf("Enter your choice: ");
                        scanf("%d", &subsubchoice1);

                        switch (subsubchoice1)
                        {

                        case 1:
                            // Bubble Sort (Ascending)
                            printf("Sorting in ascending order using bubble sort...\n");
                            bubblesortasc(arr, n1);
                            printf("Sorted array in ascending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 2:
                            // Bubble Sort (Descending)
                            printf("Sorting in descending order using bubble sort...\n");
                            bubblesortdesc(arr, n1);
                            printf("Sorted array in descending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 3:
                            // Adaptive Bubble Sort (Ascending)
                            printf("Sorting in ascending order using adaptive bubble sort...\n");
                            adaptivebubblesortasc(arr, n1);
                            printf("Sorted array in ascending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 4:
                            // Adaptive Bubble Sort (Descending)
                            printf("Sorting in descending order using adaptive bubble sort...\n");
                            adaptivebubblesortdesc(arr, n1);
                            printf("Sorted array in descending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 5:
                            // Insertion Sort (Ascending)
                            printf("Sorting in ascending order using insertion sort...\n");
                            insertionsortasc(arr, n1);
                            printf("Sorted array in ascending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 6:
                            // Insertion Sort (Descending)
                            printf("Sorting in descending order using insertion sort...\n");
                            insertionsortdesc(arr, n1);
                            printf("Sorted array in descending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 7:
                            // Selection Sort (Ascending)
                            printf("Sorting in ascending order using selection sort...\n");
                            selectionsortasc(arr, n1);
                            printf("Sorted array in ascending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 8:
                            // Selection Sort (Descending)
                            printf("Sorting in descending order using selection sort...\n");
                            selectionsortdesc(arr, n1);
                            printf("Sorted array in descending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 9:
                            // Quick Sort (Ascending)
                            printf("Sorting in ascending order using quick sort...\n");
                            quicksortasc(arr, 0, n1 - 1);
                            printf("Sorted array in ascending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 10:
                            // Quick Sort (Descending)
                            printf("Sorting in descending order using quick sort...\n");
                            quicksortdesc(arr, 0, n1 - 1);
                            printf("Sorted array in descending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 11:
                            // Merge Sort (Ascending)
                            printf("Sorting in ascending order using merge sort...\n");
                            mergesortasc(arr, 0, n1 - 1);
                            printf("Sorted array in ascending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 12:
                            // Merge Sort (Descending)
                            printf("Sorting in descending order using merge sort...\n");
                            mergesortdesc(arr, 0, n1 - 1);
                            printf("Sorted array in descending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 13:
                            // Count Sort (Ascending)
                            printf("Sorting in ascending order using count sort...\n");
                            countsortasc(arr, n1);
                            printf("Sorted array in ascending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 14:
                            // Count Sort (Descending)
                            printf("Sorting in descending order using count sort...\n");
                            countsortdesc(arr, n1);
                            printf("Sorted array in descending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 15:
                            // Heap Sort (Ascending)
                            printf("Sorting in ascending order using heap sort...\n");
                            heapsortasc(arr, n1);
                            printf("Sorted array in ascending order: ");
                            for (int i = 0; i < n1; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        case 0:
                            printf("Exiting the program...\n");
                            break;

                        default:
                            printf("Invalid choice. Please enter a valid option.\n");
                        }
                    } while (subsubchoice1 != 0);
                    break;
                case 13:
                    int element;
                    printf("Enter the element to search: ");
                    scanf("%d", &element);

                    int index = binsearch(arr, element, n1);
                    if (index != -1)
                    {
                        printf("Element %d found at index %d\n", element, index);
                    }
                    else
                    {
                        printf("Element not found\n");
                    }

                    break;
                case 0:
                    printf("Exiting the program. Bye!\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                }
            } while (subchoice1 != 0);
            break;
        case 2:
            printf("Singly Linked list chosen.\n");
            struct node *head = NULL;
            printf("Create the linked list:\n");
            printf("Enter the number of elements: ");
            int n;
            scanf("%d", &n);
            printf("Enter the elements:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &value);
                head = push(head, value);
            }
            do
            {
                printf("\n\n--- Singly Linked List MENU ---\n");
                printf("1. Display Linked List\n");
                printf("2. Insert at the beginning\n");
                printf("3. Insert at a specific index\n");
                printf("4. Insert at the end\n");
                printf("5. Insert after a node\n");
                printf("6. Delete first node\n");
                printf("7. Delete node at a specific index\n");
                printf("8. Delete last node\n");
                printf("9. Delete a specific value\n");
                printf("10. Sort the linked list (MergeSort)\n");
                printf("11. Sort the linked list (BubbleSort)\n");
                printf("12. Search an element\n");
                printf("13. Print the linked list in reverse order\n");
                printf("14. Reverse the linked list\n");
                printf("15. Merge two linked lists\n");
                printf("16. Display elements at odd positions\n");
                printf("17. Display elements at even positions\n");
                printf("0. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &subchoice2);

                switch (subchoice2)
                {
                case 1:
                    printf("\nLinked List: ");
                    printlist(head);
                    break;

                case 2:
                    printf("\nEnter the value to insert at the beginning: ");
                    scanf("%d", &value);
                    head = insertatbeginning(head, value);
                    printf("Element inserted at the beginning successfully.\n");
                    break;

                case 3:
                    printf("\nEnter the value to insert: ");
                    scanf("%d", &value);
                    printf("Enter the index to insert at: ");
                    scanf("%d", &index);
                    head = insertatindex(head, value, index);
                    if (head != NULL)
                    {
                        printf("Element inserted at index %d successfully.\n", index);
                    }
                    break;

                case 4:
                    printf("\nEnter the value to insert at the end: ");
                    scanf("%d", &value);
                    head = insertlast(head, value);
                    printf("Element inserted at the end successfully.\n");
                    break;

                case 5:
                    printf("\nEnter the value to insert: ");
                    scanf("%d", &value);
                    printf("Enter the value of the node after which to insert: ");
                    scanf("%d", &index);
                    struct node *temp = head;
                    while (temp != NULL && temp->data != index)
                    {
                        temp = temp->next;
                    }
                    if (temp != NULL)
                    {
                        head = insertafternode(head, temp, value);
                        printf("Element inserted after node successfully.\n");
                    }
                    else
                    {
                        printf("Node with the given value not found\n");
                    }
                    break;

                case 6:
                    head = deletefirst(head);
                    printf("First node deleted successfully.\n");
                    break;

                case 7:
                    printf("\nEnter the index of the node to delete: ");
                    scanf("%d", &index);
                    head = deleteatindex(head, index);
                    if (head != NULL)
                    {
                        printf("Node at index %d deleted successfully.\n", index);
                    }
                    break;

                case 8:
                    head = deletelast(head);
                    printf("\nLast node deleted successfully.\n");
                    break;

                case 9:
                    printf("\nEnter the value to delete: ");
                    scanf("%d", &value);
                    head = deletevalue(head, value);
                    printf("\nGiven value deleted successfully.\n");
                    break;

                case 10:
                    printf("Original list: ");
                    printlist(head);
                    head = mergesort(head);
                    printf("\nSorted list: ");
                    printlist(head);
                    break;

                case 11:
                    printf("Original list: ");
                    printlist(head);
                    head = bubblesort(head);
                    printf("\nSorted list: ");
                    printlist(head);
                    break;

                case 12:
                    printf("Enter the value to search : ");
                    scanf("%d", &value);
                    search(head, value);
                    break;

                case 13:
                    printreverse(head);
                    break;

                case 14:
                    head = reverselist(head);
                    printf("Reversed linked list: ");
                    printlist(head);
                    break;
                case 15:
                    struct node *s2 = NULL;
                    printf("Create the second linked list:\n");
                    printf("Enter the number of elements: ");
                    int n;
                    scanf("%d", &n);
                    printf("Enter the elements:\n");
                    for (int i = 0; i < n; i++)
                    {
                        scanf("%d", &value);
                        s2 = push(s2, value);
                    }
                    head = mergell(head, s2);
                    printlist(head);
                    break;
                case 16:
                    displayodd(head);
                    break;
                case 17:
                    displayeven(head);
                    break;
                case 0:
                    printf("\nExiting the program. Bye!\n");
                    break;

                default:
                    printf("\nInvalid choice. Please try again.");
                    break;
                }

            } while (subchoice2 != 0);
            break;

        case 3:
            printf("Doubly Linked list chosen.\n");

            printf("Enter the size of the doubly linked list: ");
            scanf("%d", &n1);
            struct dnode *headd = NULL;
            struct dnode *tail = NULL;

            for (int i = 0; i < n1; i++)
            {
                int value;
                printf("Enter the value for node %d: ", i + 1);
                scanf("%d", &value);

                struct dnode *newnode = createnode(value);

                if (headd == NULL)
                {
                    headd = newnode;
                    tail = newnode;
                }
                else
                {
                    tail->next = newnode;
                    newnode->prev = tail;
                    tail = newnode;
                }
            }
            printf("The doubly linked list is: ");

            int val;
            do
            {
                printf("\n--- Doubly Linked List Menu ---\n");
                printf("1. Display Linked List\n");
                printf("2. Insert at the beginning\n");
                printf("3. Insert at a specific index\n");
                printf("4. Insert at the end\n");
                printf("5. Delete first node\n");
                printf("6. Delete node at a specific index\n");
                printf("7. Delete last node\n");
                printf("8. Reverse traversal of the list\n");
                printf("0. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &subchoice3);

                switch (subchoice3)
                {
                case 1:
                    printf("Doubly linked list: ");
                    traversedll(headd);
                    break;
                case 2:
                    printf("Enter the value to insert: ");
                    scanf("%d", &val);
                    headd = insertfirstd(headd, val);
                    printf("Element inserted at the beginning successfully.\n");
                    break;

                case 3:
                    printf("Enter the index to insert at: ");
                    scanf("%d", &index);
                    printf("Enter the value to insert: ");
                    scanf("%d", &val);
                    headd = insertatindexd(headd, index, val);
                    if (headd != NULL)
                    {
                        printf("Element inserted at index %d successfully.\n", index);
                    }
                    break;

                case 4:
                    printf("Enter the value to insert at the end: ");
                    scanf("%d", &val);
                    headd = insertlastd(headd, val);
                    printf("Element inserted at the end successfully.\n");
                    break;

                case 5:
                    headd = deletefirstd(headd);
                    printf("First node deleted successfully.\n");
                    break;

                case 6:
                    printf("Enter the index of the node to delete: ");
                    scanf("%d", &index);
                    headd = deleteatindexd(headd, index);
                    if (headd != NULL)
                    {
                        printf("Node at index %d deleted successfully.\n", index);
                    }
                    break;

                case 7:
                    headd = deletelastd(headd);
                    printf("Last node deleted successfully.\n");
                    break;

                case 8:
                    printf("Reverse traversal of the list: ");
                    revtraversal(headd);
                    break;

                case 0:
                    printf("Exiting the program.\n");
                    break;

                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
                }
            } while (subchoice3 != 0);
            break;
            deletearray(arr);
        case 4:
            printf("Circular Linked List chosen. \n");
            printf("Enter the size of the circular linked list: ");
            scanf("%d", &n1);
            struct cnode *chead = createcll(n1);
            int subchoice4, data, index;
            do
            {
                printf("\n-- Circular Linked List Menu --");
                printf("\n1. Traverse Linked List");
                printf("\n2. Insert at the Beginning");
                printf("\n3. Insert at a Specific Position");
                printf("\n4. Insert at the End");
                printf("\n5. Insert After a Node");
                printf("\n6. Delete First Node");
                printf("\n7. Delete Node at a Specific Position");
                printf("\n8. Delete Last Node");
                printf("\n0. Exit");

                printf("\nEnter your choice: ");
                scanf("%d", &subchoice4);

                switch (subchoice4)
                {

                case 1:
                    printf("Linked List: ");
                    linkedlisttraversalc(chead);
                    printf("\n");
                    break;

                case 2:
                    printf("Enter data to insert at the beginning: ");
                    scanf("%d", &data);
                    chead = insertfirstc(chead, data);
                    printf("Node inserted at the beginning.\n");
                    break;

                case 3:
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    printf("Enter index to insert at: ");
                    scanf("%d", &index);
                    chead = insertatindexc(chead, data, index);
                    printf("Node inserted at index %d.\n", index);
                    break;

                case 4:
                    printf("Enter data to insert at the end: ");
                    scanf("%d", &data);
                    chead = insertlastc(chead, data);
                    printf("Node inserted at the end.\n");
                    break;

                case 5:
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    printf("Enter the data value of the node after which to insert: ");
                    scanf("%d", &index);
                    struct cnode *prevnode = chead;
                    while (prevnode->data != index && prevnode->next != chead)
                    {
                        prevnode = prevnode->next;
                    }
                    if (prevnode->data == index)
                    {
                        chead = insertafternodec(chead, prevnode, data);
                        printf("Node inserted after the specified node.\n");
                    }
                    else
                    {
                        printf("Node not found.\n");
                    }
                    break;

                case 6:
                    chead = deletefirstc(chead);
                    printf("First node deleted.\n");
                    break;

                case 7:
                    printf("Enter the index of the node to delete: ");
                    scanf("%d", &index);
                    chead = deleteatindexc(chead, index);
                    printf("Node at index %d deleted.\n", index);
                    break;

                case 8:
                    chead = deletelastc(chead);
                    printf("Last node deleted.\n");
                    break;
                case 0:
                    printf("\nExiting the program.\n");
                    break;
                default:
                    printf("\nInvalid choice. Please try again.\n");
                }

            } while (subchoice4 != 0);
            break;
        case 5:
            int subchoice5, subsubchoice3, subsubchoice4, pos, size, popped;
            do
            {
                printf("\n----- Stack Menu -----\n");
                printf("1. Implement stack using Array.\n");
                printf("2. Implement stack using Linked List.\n");
                printf("0. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &subchoice5);
                switch (subchoice5)
                {
                case 1:
                    printf("Let's implement stack using array. \n");
                    stack *s = (stack *)malloc(sizeof(stack)); // convenient to make a pointer of the structure because then it can be passed to functions and be called by reference.
                    printf("Enter the size of stack : ");
                    scanf("%d", &s->size);
                    s->top = -1;
                    s->arr = (int *)malloc(s->size * sizeof(int));
                    printf("Enter the number of elements : ");
                    scanf("%d", &n);
                    for (int i = 0; i < n; i++)
                    {
                        printf("Enter element : ");
                        scanf("%d", &val);
                        pushelement(s, val);
                    }
                    do
                    {
                        printf("\n----- Stack implemented using Array Menu -----\n");
                        printf("1. Push element in stack\n");
                        printf("2. Pop element in stack\n");
                        printf("3. Display stack\n");
                        printf("4. Peek element\n");
                        printf("5. Display top element\n");
                        printf("6. Display bottom element\n");
                        printf("0. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &subsubchoice3);

                        switch (subsubchoice3)
                        {
                        case 1:
                            printf("Enter the value to push: ");
                            scanf("%d", &val);
                            pushelement(s, val);
                            break;
                        case 2:
                            val = popelement(s);
                            if (val != -1)
                                printf("%d popped from the stack.\n", val);
                            break;
                        case 3:
                            printf("Stack : \n");
                            displaystack(s);
                            break;
                        case 4:
                            printf("Enter the position to peek: ");
                            scanf("%d", &pos);
                            peek(s, pos);
                            break;
                        case 5:
                            stacktop(s);
                            break;
                        case 6:
                            stackbottom(s);
                            break;
                        case 0:
                            printf("Exiting the program.\n");
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                        }
                    } while (subsubchoice3 != 0);
                    break;
                case 2:
                    printf("Let's implement stack using linked list. \n");
                    stackl *top = NULL;
                    printf("Enter the number of elements : ");
                    scanf("%d", &n);
                    for (int i = 0; i < n; i++)
                    {
                        printf("Enter element : ");
                        scanf("%d", &val);
                        top = pushl(top, val);
                    }
                    do
                    {
                        printf("\n----- Stack implemented using Linked List Menu -----\n");
                        printf("1. Push element in stack\n");
                        printf("2. Pop element in stack\n");
                        printf("3. Display stack\n");
                        printf("4. Peek element\n");
                        printf("5. Display top element\n");
                        printf("6. Display bottom element\n");
                        printf("0. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &subsubchoice4);

                        switch (subsubchoice4)
                        {
                        case 1:
                            printf("Enter the value to be pushed in stack : ");
                            scanf("%d", &val);
                            top = pushl(top, val);
                            printf("%d successfully pushed in stack.", val);
                            break;
                        case 2:
                            popped = popl(&top);
                            if (popped != -1)
                                printf("%d popped successfully from stack.\n", popped);
                            break;
                        case 3:
                            displaystackl(top);
                            break;
                        case 4:
                            printf("Enter the position to peek: ");
                            scanf("%d", &pos);
                            peekl(top, pos);
                            break;
                        case 5:
                            stackltop(top);
                            break;
                        case 6:
                            stacklbottom(top);
                            break;
                        case 0:
                            printf("Exiting the program.\n");
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                        }
                    } while (subsubchoice4 != 0);
                }
            } while (subchoice5 != 0);
            break;
        case 6:
            int subchoice6, subsubchoice5;
            queue *q = (queue *)malloc(sizeof(queue));
            do
            {
                printf("\n----- Queue Menu -----\n");
                printf("1. Implement queue using Array.\n");
                printf("2. Implement queue using Circular Array.\n");
                printf("3. Implement queue using Linked List.\n");
                printf("4. Implement queue using 2 Stacks.\n");
                printf("5. Implement Double Ended Queue using Array.\n");
                printf("0. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &subchoice6);
                switch (subchoice6)
                {
                case 1:
                    printf("Let's implement queue using array.\n");
                    printf("Enter the size of the input : ");
                    scanf("%d", &size);
                    q->size = 100;
                    q->front = -1;
                    q->rear = -1;
                    q->arr = (int *)malloc(q->size * sizeof(int));
                    for (int i = 0; i < size; i++)
                    {
                        printf("Enter element : ");
                        scanf("%d", &val);
                        enqueue(q, val);
                    }
                    do
                    {
                        printf("\n----- Queue implemented using Array Menu -----\n");
                        printf("1. Enqueue element in queue\n");
                        printf("2. Dequeue element in queue\n");
                        printf("3. Display queue\n");
                        printf("4. Display first element in queue\n");
                        printf("5. Display last element in queue\n");
                        printf("0. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &subsubchoice5);

                        switch (subsubchoice5)
                        {
                        case 1:
                            printf("Enter the value to enqueue: ");
                            scanf("%d", &val);
                            enqueue(q, val);
                            printf("Element %d successfully enqueued!\n", val);
                            break;
                        case 2:
                            val = dequeue(q);
                            if (val != -1)
                                printf("%d dequeued from queue.\n", val);
                            break;
                        case 3:
                            displayq(q);
                            break;
                        case 4:
                            firstval(q);
                            break;
                        case 5:
                            lastval(q);
                            break;
                        case 0:
                            printf("Exiting the program.\n");
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                        }
                    } while (subsubchoice5 != 0);
                    break;
                case 2:
                    printf("Let's implement circular queue using array.\n");
                    printf("Enter the size of the circular queue : ");
                    scanf("%d", &n);
                    q->size = n + 1;
                    q->front = 0;
                    q->rear = 0;
                    q->arr = (int *)malloc(q->size * sizeof(int));
                    for (int i = 1; i < q->size; i++)
                    {
                        printf("Enter element : ");
                        scanf("%d", &val);
                        cenqueue(q, val);
                    }
                    do
                    {
                        printf("\n----- Circular Queue implemented using Array Menu -----\n");
                        printf("1. Enqueue element in circular queue\n");
                        printf("2. Dequeue element in circular queue\n");
                        printf("3. Display circular queue\n");
                        printf("0. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &subsubchoice5);

                        switch (subsubchoice5)
                        {
                        case 1:
                            printf("Enter the value to enqueue: ");
                            scanf("%d", &val);
                            cenqueue(q, val);
                            break;
                        case 2:
                            val = cdequeue(q);
                            if (val != -1)
                                printf("%d dequeued from queue.\n", val);
                            break;
                        case 3:
                            displaycq(q);
                            break;
                        case 0:
                            printf("Exiting the program.\n");
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                        }
                    } while (subsubchoice5 != 0);
                    break;
                case 3:
                    int n;
                    printf("Let's implement queue using linked list. \n");
                    printf("Enter the size of input : ");
                    scanf("%d", &n);
                    for (int i = 0; i < n; i++)
                    {
                        printf("Enter number : ");
                        scanf("%d", &val);
                        lenqueue(val);
                    }
                    do
                    {
                        printf("\n----- Circular Queue implemented using Linked List Menu -----\n");
                        printf("1. Enqueue element in queue\n");
                        printf("2. Dequeue element in queue\n");
                        printf("3. Display queue\n");
                        printf("0. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &subsubchoice5);

                        switch (subsubchoice5)
                        {
                        case 1:
                            printf("Enter the value to enqueue: ");
                            scanf("%d", &val);
                            lenqueue(val);
                            break;
                        case 2:
                            val = ldequeue();
                            if (val != -1)
                                printf("%d dequeued from queue.\n", val);
                            break;
                        case 3:
                            displaylqueue(f);
                            break;
                        case 0:
                            printf("Exiting the program.\n");
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                        }
                    } while (subsubchoice5 != 0);
                    break;
                case 4:
                    printf("Let's implement queue using two stacks.\n");
                    stack *s1 = (stack *)malloc(sizeof(stack));
                    stack *s2 = (stack *)malloc(sizeof(stack));
                    s1->top = -1;
                    s2->top = -1;
                    s1->size = 100;
                    s2->size = 100;
                    s1->arr = (int *)malloc(s1->size * sizeof(int));
                    s2->arr = (int *)malloc(s2->size * sizeof(int));
                    printf("Enter the size of queue : ");
                    scanf("%d", &n);
                    printf("Enter the elements : \n");
                    for (int i = 0; i < n; i++)
                    {
                        scanf("%d", &val);
                        pushelement(s1, val);
                    }
                    do
                    {
                        printf("\n----- Queue implemented using 2 Stacks Menu -----\n");
                        printf("1. Enqueue element in queue\n");
                        printf("2. Dequeue element in queue\n");
                        printf("3. Display queue\n");
                        printf("0. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &subsubchoice5);

                        switch (subsubchoice5)
                        {
                        case 1:
                            printf("Enter the value to enqueue: ");
                            scanf("%d", &val);
                            SSenqueue(s1, val);
                            break;
                        case 2:
                            val = SSdequeue(s1, s2);
                            if (val != -1)
                                printf("%d dequeued from queue.\n", val);
                            break;
                        case 3:
                            SSdisplayq(s1, s2);
                            break;
                        case 0:
                            printf("Exiting the program.\n");
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                        }
                    } while (subsubchoice5 != 0);
                    break;
                case 5:
                    deque *q = (deque *)malloc(sizeof(deque));
                    printf("Let's implement queue using array.\n");
                    printf("Enter the size of the input : ");
                    scanf("%d", &size);
                    q->size = 100;
                    q->front = -1;
                    q->rear = -1;
                    q->arr = (int *)malloc(q->size * sizeof(int));
                    for (int i = 0; i < size; i++)
                    {
                        printf("Enter element : ");
                        scanf("%d", &val);
                        enqueuer(q, val);
                    }
                    do
                    {
                        printf("\n----- DEQueue implemented using Array Menu -----\n");
                        printf("1. Enqueue element from front in queue\n");
                        printf("2. Enqueue element from rear in queue\n");
                        printf("3. Dequeue element from front in queue\n");
                        printf("4. Dequeue element from rear in queue\n");
                        printf("5. Display queue\n");
                        printf("0. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &subsubchoice5);

                        switch (subsubchoice5)
                        {
                        case 1:
                            printf("Enter the value to enqueue from front: ");
                            scanf("%d", &val);
                            enqueuef(q, val);
                            printf("Element %d successfully enqueued!\n", val);
                            break;
                        case 2:
                            printf("Enter the value to enqueue from rear: ");
                            scanf("%d", &val);
                            enqueuer(q, val);
                            printf("Element %d successfully enqueued!\n", val);
                            break;
                        case 3:
                            val = dequeuef(q);
                            if (val != -1)
                                printf("%d dequeued from front of queue.\n", val);
                            break;
                        case 4:
                            val = dequeuer(q);
                            if (val != -1)
                                printf("%d dequeued from rear of queue.\n", val);
                            break;
                        case 5:
                            displaydeq(q);
                            break;
                        case 0:
                            printf("Exiting the program.\n");
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                        }
                    } while (subsubchoice5 != 0);
                }
            } while (subchoice6 != 0);
            break;
        case 0:
            printf("Exiting the program. Bye!\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    } while (mainchoice != 0);
    printf("\n");
    return 0;
}