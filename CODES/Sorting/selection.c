#include <stdio.h>
/*Function to implement a selection sort algorithm*/
//function for swap
void swap(int *xp, int *yp)
{
    int temp;
    temp=*xp;
    *xp=*yp;
    *yp=temp;
}
void selectionSort(int a[], int n)
{
    for(int i=0; i<n-1;i++)
    {
        // i index value is our minimumn element
        int min = i; //0 1 ---- 5
        for(int j=i+1;j<n;j++) //j=1 1<6
        {
            //condition to update the value of min
            if(a[j]<a[min]) //a[1]<a[0] 4<7 yes
            {
                min=j; //1
            }
        }
        //swap logic
        if(min!=i) // 5!=0 yes
        {
            swap(&a[i],&a[min]);
        }
    }
}
int main()
{
    int a[] = {7, 4, 10, 8, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int i;
    // print the array
    printf("The unsorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    // call the function
    selectionSort(a, n);
    // printf("/////////////////////////////////////\n");
    printf("The sorted array:\n");
    // print the sort array
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}