#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "analyze.h"
#include "algorithm.h"
#include "ui.h"


static void generate_input(case_t c, int arr[], int size) {
    
    switch (c) {
        case best_t:
            // Best case: Sorterad array
            for (int i = 0; i < size; i++) {
                arr[i] = i;
            }
            break;

        case worst_t:
            // Worst case: Omvänd sorterad array
            for (int i = 0; i < size; i++) {
                arr[i] = size - i;
            }
            break;

        case average_t:
        default:
            // Average case: Slumpmässiga data
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % size;
            }
            break;
    }
}
static void bestCase_quick(int arr[], int low, int high, int *currentValue){
    if (high <= low) {
        return; //basfall: om området är för litet
    }
    int mid = (low + high) / 2; //välj ett mitten element
    arr[mid] = (*currentValue)++; //tildela värdet till pivot
    bestCase_quick(arr, low, mid - 1, currentValue); //vänster
    bestCase_quick(arr, mid + 1, high, currentValue); //höger
}

static void quickSort_arr(case_t c, int arr[], int size){

    switch(c){
        case best_t:
            int currentValue = 1;
            bestCase_quick(arr, 0, size - 1, &currentValue);
            break;

        case worst_t:
            for (int i = 0; i < size; i++){
                arr[i] = size - 1;
            }
            break;

        case average_t:
             for (int i = 0; i < size; i++){
                 arr[i] = rand() % size;
             }
             break;
    }
}

static void searchArr(algorithm_t a,case_t c, int arr[],int size){
    switch (c) {
        case best_t:
            for (int i = 0; i < size; i++){
                arr[i] = 1;
            }
            break;
        
        case worst_t:
           for (int i = 0; i < size; i++){
            arr[i] = 0;
           }
        case average_t:
            if (a == linear_search_t){
                for (int i = 0; i < size; i++) {
                    arr[i] = (i == size / 2) ? 1 : 0;
                }
            } else {
                for (int i = 0; i < size; i++) {
                    arr[i] = (i == size / 4) ? 1 : 0;
                }
            }
        break;

    default:
    }       
}

//en public funktion som tar in algoritmen med olika inputs
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
    struct timespec start;
    struct timespec end;
    srand(time(NULL));

    memset(buf, 0, n * sizeof(result_t));

    int size = SIZE_START;
    int *arr = (int*)malloc(size * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Minnesomallokering misslyckades.\n");
        return;
    }
    
    double timeArr[n];

    memset(timeArr, 0, sizeof(timeArr));

    for (int i = 0; i < n; i++){
        generate_input(c, arr, size);;

        clock_gettime(CLOCK_MONOTONIC, &start);
        switch(a){
            case bubble_sort_t:
                bubble_sort(arr, size);
                break;
            case quick_sort_t:
                quickSort_arr(c, arr, size);
                quick_sort(arr, size);
                break;
            case insertion_sort_t:
                insertion_sort(arr, size);
                break;
            case linear_search_t:
                searchArr(a, c, arr, size);
                linear_search(arr, size, arr[size / 2]);
                break;
            case binary_search_t:
                searchArr(a, c, arr, size);
                binary_search(arr, size, arr[size / 2]);
                break;
        }
        clock_gettime(CLOCK_MONOTONIC, &end);

        double time_sec = ((end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9);
        buf->time = time_sec;
        buf->size = size;
        timeArr[i] = time_sec; 
        
        size *= 2;
        
        
        int *new_Arr = realloc(arr, size * sizeof(int));
        if (!new_Arr){
            fprintf(stderr, "Minnesomallokering misslyckades.\n");
            free(arr);
            return;
        }
        arr = new_Arr;
    }
    int temp_size = SIZE_START;
    ui_results(temp_size, timeArr, n, a, c);
    free(arr);
}
