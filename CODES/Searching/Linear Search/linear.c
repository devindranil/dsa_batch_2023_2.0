// wap in c using function to implement linear search algorithm
#include <stdio.h>
int linearSearch(int a[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        //comparison
        if(a[i]==key)
        {
            return i;
        }
    }
    //if the search element is not present in the array
    return -1;
}
void main()
{
    int a[] = {70, 40, 30, 11, 57, 41, 25, 14};
    int n = sizeof(a) / sizeof(a[0]);
    int key = 59;
    int result = linearSearch(a, n, key);
    if (result == -1)
    {
        printf("Element is not present in array");
    }
    else
    {
        printf("Element is present at index %d", result);
    }
}