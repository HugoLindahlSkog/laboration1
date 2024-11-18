#include "algorithm.h"
#include <stdio.h>
#include <stdlib.h>

//
// Private
//

//
// Public
//
void bubble_sort(int *a, int n)
{
	 for (int i = 0; i < n - 1; i++)
	 {
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
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


static int partition(int *a, int left, int right)
{
	int pivot = a[right]; //välj sista element som pivot
	int i = left - 1;

	for (int j = left; j < right; j++)
	{
		if (a[j] < pivot) 
		{
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;  //byt plats på a[i] och a[j];
		}
	}
	//byt plats på pivot till rätt position och retunera pivot nya index
	int temp = a[i+1];
	a[i+1] = a[right];
	a[right] = temp;

	return i+1;
}

static int quickSort(int *a, int left, int right)
{
	if (left < right)
	{
		//dela upp arrayerna med partition
		int pivot_index = partition(a, left, right);
		quickSort(a, left, pivot_index - 1); //sortera arrayerna rekrusivt
		quickSort(a, pivot_index + 1, right);
	}
	return 0;
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
		if (a[i] == v) //om a[i] == v så returnera i
		return i; 
	}
	return false;
}

bool binary_search(const int *a, int n, int v)
{
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
