#include <stdio.h>
//mergesort function
void merge(int a[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1; //size of left subarray
	int n2 = r - m;		//size of right subarray
	//create temp arrays
	int L[n1], R[n2];
	//copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++)
	{
		L[i] = a[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = a[m + 1 + j];
	}
	//merge the temp arrays back into a[l..r]
	i = 0; //initial index of first subarray
	j = 0; //initial index of second subarray
	k = l; //initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	//copy the remaining elements of L[], if there are any
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	//copy the remaining elements of R[], if there are any
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}


//merge sort function
void mergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		//same as (l+r)/2, but avoids overflow for large l and h
		int m = l + (r - l) / 2;
		//sort first and second halves
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
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
	int a[] = {15, 5, 24, 8, 1, 3, 16, 10, 20};
	int n = sizeof(a) / sizeof(a[0]);
	int i;
	printf("The unsorted array is:\n");
	printArray(a, n);
	// call the merge sort algo function
	mergeSort(a, 0, n - 1);
	printf("\n");
	printf("The Sorted array is:\n");
	printArray(a, n);
}