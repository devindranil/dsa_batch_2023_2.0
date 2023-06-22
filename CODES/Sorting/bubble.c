#include <stdio.h>
//un optimized bubble sort
void bubblesort(int a[], int n)
{
	int i,j;
    for (i = 0; i < n - 1; i++) // no of passes
    {
        printf("Working on pass number: %d\n", i + 1); // to show the no passes
        for (j = 0; j < ((n - 1) - i); j++)        // no of comparison
        {
            if (a[j] > a[j + 1]) // logic of comparison
            {
                // swap
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
//optimized bubble sort 
void bubblesortOptimized(int a[], int n)
{
    int isSorted = 0; // variable to check the array is sorted or unsorted
    int i, j;
    for (i = 0; i < n - 1; i++) // no of passes
    {
        printf("\nWorking on pass number: %d\n", i + 1); // to show the no passes
        isSorted = 0;
        for (j = 0; j < ((n - 1) - i); j++) // no of comparison
        {
            if (a[j] > a[j + 1]) // logic of comparison
            {
                // swap the values
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 1; // 1 indicate the array is unsorted
            }
        }
        //condition to out of the loop
        if (isSorted==0)
        {
            break;
        }
    }
}
int main()
{
    // int a[] = {15, 16, 6, 8, 5};
    int a[] = {16,14,5,6,8};
    //int a[] = {1,2,3,4,6,5};
    int n = sizeof(a) / sizeof(a[0]);
    int i;
    // print the array
    printf("The unsorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    //bubblesort(a, n);
    // printf("/////////////////////////////////////\n");
    bubblesortOptimized(a, n);
    printf("The sorted array:\n");
    // print the sort array
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
