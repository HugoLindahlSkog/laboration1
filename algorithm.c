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
	 for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n-i-n; j++){
			if (a[j] > a[j+1]) {
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

void quick_sort(int *a, int n)
{
	
}

bool linear_search(const int *a, int n, int v)
{
	return false; // TODO: linear search
}

bool binary_search(const int *a, int n, int v)
{
	return false; // TODO: binary search
}
