#include <stdio.h>
#define MAX_SIZE 100
// TODO:Insertion at the beginning
void insertionAtBeginning(int arr[], int *size, int element)
{
    if (*size >= MAX_SIZE)
    {
        printf("Error: Array size exceeded maximum limit.\n");
        return;
    }
    for (int i = (*size) - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = element;
    (*size)++;
}
// TODO:Insertion at the end
void insertionAtEnd(int arr[], int *size, int element)
{
    if (*size >= MAX_SIZE)
    {
        printf("Error: Array size exceeded maximum limit.\n");
        return;
    }
    arr[*size] = element;
    (*size)++;
}
// TODO:Insert at any position
void insertionAtPosition(int arr[], int *size, int element, int position)
{
    if (*size >= MAX_SIZE)
    {
        printf("Error: Array size exceeded maximum limit.\n");
        return;
    }
    for (int i = *size - 1; i >= position; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
    (*size)++;
}
// TODO:Deletion at any position
void deleteAtPosition(int arr[], int *size, int position)
{
    if (position < 0 || position >= *size)
    {
        //?check the array is blank or not
        if (*size == 0)
        {
            printf("Error: Array is empty.\n");
            return;
        }
        printf("Error: Invalid position.\n");
        return;
    }
    for (int i = position; i <=  *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
int main()
{
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50};
    int size = 5;
    int element = 55;
    int position = 0;

    printf("Initial array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // insertionAtBeginning(arr, &size, element);
    // insertionAtEnd(arr, &size, element);
    // insertionAtPosition(arr,&size,element,position);
    deleteAtPosition(arr, &size, position);
    //printf("Array after inserting %d at the beginning: ", element);
    printf("array AFTER OPERATION: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
