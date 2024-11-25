#include "algorithm.h"
#include <stdio.h>
#include <stdlib.h>

//
// Private
//

static void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
static int partition(int *a, int low, int high)
{
	int pivot = a[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			swap(&a[i], &a[high]);
		}
	}
	swap(&a[i+1], &a[high]);
	return i+1;
}

static int quickSort(int *a, int low, int high)
{
	if (low < high)
	{
		//dela upp arrayerna med partition
		int pivot_index = partition(a, low, high);
		quickSort(a, low, pivot_index - 1); //sortera arrayerna rekrusivt
		quickSort(a, pivot_index + 1, high);
	}
	return 0;
}



//
// Public
//

void bubble_sort(int *a, int n)
{
	 for (int i = 0; i < n - 1; i++)
	 {
		int swapped = 0;
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				swapped = 1;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

void insertion_sort(int *a, int n)
{
	
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j+1] = key;
	}
}

void quick_sort(int *a, int n)
{
	//anropa quicksort med hela arrayn
	quickSort(a, 0, n - 1);
}

bool linear_search(const int *a, int n, int v)
{
	for (int i = 0; i < n; i++) //iterera varje element
	{
		if (a[i] == v) //om a[i] == v så returnera true
		return true; 
	}
	return false;
}

bool binary_search(const int *a, int n, int v)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (a[mid] == v)
			return true;
		
		if (a[mid] < v)
			left = mid + 1;
		
		else
			right = mid - 1;

	}
	return false; 
} 

/*int main() {
    int array[] = {29, 10, 14, 37, 13};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n);

    printf("Sorterad array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
} */
