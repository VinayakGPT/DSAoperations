void revarr(int *a, int n) {
    int temp;
    for(int i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
    for(int j=0;j<n;j++)
    {
        printf("%d",a[j]);
    }
}
void mergearr(int a[],int b[],int n1,int n2)
{
    for(int i=0;i<n2;i++)
    {
        a[n1+i]=b[i];
    }
}
void printma(int a[],int n1,int n2)
{
    printf("\n Merged array is : \n");
    for(int i=0;i<n1+n2;i++)
    {
        printf("%d ",a[i]);
    }
}
void deleteelement(int a[],int n,int ele)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]!=ele)
        printf("%d ",a[i]);
        else
        continue;
    }
}
void deleteatposition(int a[],int n,int position)
{
    printf("\n");
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[position-1])
        continue;
        else
        printf("%d ",a[i]);
    }
}
void insertatposition(int a[],int position,int ele,int n)
{
    for(int i=n;i>=position;i--)
    {
        a[i]=a[i-1];
    }
    a[position-1]=ele;
}
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
int findmin(int a[], int n)
{
    int min = a[0];
    for(int i = 1; i < n; i++)
    {
        if(min > a[i])
        {
            min = a[i];
        }
    }
    return min;
}
int* create_array(int n)
{
    // allocate memory for the array
    int* a = (int*) malloc(n * sizeof(int));
    return a;
}
void delete_array(int* a)
{
    // free the memory allocated for the array
    free(a);
}
