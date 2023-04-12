#include<stdio.h>
int main()
{
    int n,temp,ele,index;
    printf("Enter the number of elements");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Enter the element that you want to search : ");
    scanf("%d",&ele);
    index=binsearch(a,ele,n);
    if(index==-1)
    printf("The given element does not exist in the array!");
    else
    printf("The given element %d was found at a[%d]",ele,index);
    return 0;
}
int binsearch(int a[],int ele,int n )
{
    int mid,high,low;
    high=n-1;
    low=0;
    while(low<=high){
    mid=(high+low)/2;
    if(ele==a[mid])
    return mid;
    else if(ele>a[mid])
    low=mid+1;
    else if(ele<a[mid])
    high=mid-1;
    }
    return -1;
}