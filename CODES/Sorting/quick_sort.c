#include<stdio.h>
int partion(int a[], int low, int high)
{
	int pivot=a[low];
	int p=low;
	int q=high;
	int temp;
	do{
	
		while(a[p]<=pivot)//p is responsible for finding the greater value of pivot
		{
			p++;
		}
		while(a[q]>pivot)//q is responsible for finding the less value compare to pivot
		{
			q--;
		}
		if(p<q)
		{
			//swap p and q
			temp=a[p];
			a[p]=a[q];
			a[q]=temp;
		}
	}while(p<q);
	//swap pivot and q
	temp=a[low];//pivot element
	a[low]=a[q];
	a[q]=temp;
	return q;
	
}
void quickSort(int a[], int low, int high)
{
	int partionIndex;
	if(low<high)
	{
		partionIndex=partion(a,low,high);
		//left sub array
		quickSort(a,low,partionIndex-1);
		//right sub array
		quickSort(a,partionIndex+1,high);
	}
}
void printArray(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}	
}
int main()
{
	int a[] = {7,6,10,5,9,2,1,15,22,7,22,15,9,9,35};
	int n = sizeof(a) / sizeof(a[0]);
	int i;
	printf("The unsorted array is:\n");
	printArray(a,n);
	//call the quick sort algo function
	quickSort(a,0,n-1);
	printf("\n");
	printf("The Sorted array is:\n");
	printArray(a,n);
	
}
