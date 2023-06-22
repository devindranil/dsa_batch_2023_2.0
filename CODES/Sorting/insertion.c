#include <stdio.h>
/*Function to implement a insertion sort algorithm*/
void insertionSort(int a[], int n)
{
    for(int i=1; i<n; i++)
    {
        int temp = a[i];
        int j = i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        /*while(j>=0)
        {
            if(a[j]>temp)
            {
                a[j+1] = a[j];
                j--;
            }
        }*/
        a[j+1]=temp;
    }
}
//trversal algorithm
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int a[] = {5, 4, 10, 1, 6, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int i;
    // print the array
    printf("The unsorted array:\n");
    printArray(a, n);
    printf("\n");
    // call the function
    insertionSort(a, n);
    // printf("/////////////////////////////////////\n");
    printf("The sorted array:\n");
    // print the sort array
    printArray(a, n);
    return 0;
}