#include <stdio.h>
// itereative approach
int binarySearch(int arr[], int n, int x)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = ((l + h) / 2);
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}
// Recusrive approach
int RecBinarySearch(int arr[], int l, int h, int x)
{
    if (h >= l)
    {
        int mid = ((l + h) / 2);
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            return RecBinarySearch(arr, l, mid - 1, x);
        }
        else
        {
            return RecBinarySearch(arr, mid + 1, h, x);
        }
    }
    // element not present in the array
    return -1;
}
void bubblesort(int a[], int n)
{
    int isSorted = 0;
    int i, j;
    for (i = 0; i < (n - 1); i++)
    {
        printf("\nworking on pass number %d\n", i + 1);
        isSorted = 0;
        for (j = 0; j < ((n - 1) - i); j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 1;
            }
        }
        if (isSorted == 0)
        {
            break;
        }
    }
}
int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 18;
    int result = binarySearch(arr, n, x);
    int result = RecBinarySearch(arr, 0, n - 1, x);
    if (result == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", result);
    }
    return 0;
}
