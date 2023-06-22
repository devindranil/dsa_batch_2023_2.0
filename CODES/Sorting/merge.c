#include <stdio.h>
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// function of merge
void merge(int a[], int mid, int low, int high)
{
    int b[100]; // b[] is a temp array which store the sorted result after combine L[] & R[]
    // i = left sub array
    // j = right sub array
    // k = temp array b[]
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    // remaining part of the array
    while (i <= mid) // if any element remain in left sub array
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high) // if any element remain in right sub array
    {
        b[k] = a[j];
        k++;
        j++;
    }

    // copy all the element form array b[] to array a[]
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
// merge sort function define
void mergeSort(int a[], int low, int high)
{
    int mid; // mid is a variable which calculate the mid of the array
    if (low < high)
    {
        mid = (low + high) / 2;
        // recursively call the mergesort
        mergeSort(a, low, mid);      // left sub array ---- mergeSort(a[], 0, 4)
        mergeSort(a, mid + 1, high); // right sub array
                                     /*
                                     ----------algo of merging techniques---------------
                                         call a merge(a,mid,low,high)
                                         mid = 4
                                         low = 0
                                         high = 8
                                         merge(a, 4 , 0, 8)
                                     */
        merge(a, mid, low, high);
    }
}

int main()
{
    int a[] = {15, 5, 24, 8, 1, 3, 16, 10, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int i;
    printf("The unsorted array is:\n");
    printArray(a, n);
    // call the merge sort algo function
    // mergeSort(a[9], 0, 8)
    mergeSort(a, 0, n - 1); // array , 0->low/lb, n-1-> high/ub
    printf("\n");
    printf("The Sorted array is:\n");
    printArray(a, n);
}