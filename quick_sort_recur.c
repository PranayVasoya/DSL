#include <stdio.h>

void quicksort (int [], int, int);

int main()
{
    int a[30];
    int size, i;

    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, size - 1);
    printf("After sorting: ");
    for (i = 0; i < size; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}
void quicksort(int a[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (a[i] <= a[pivot] && i <= high)
            {
                i++;
            }
            while (a[j] > a[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[j];
        a[j] = a[pivot];
        a[pivot] = temp;
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}