#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "analyze.h"
#include "algorithm.h"




static void (*algorithm_functions[])(void *) = {
    (void (*)(void *))bubble_sort,
    (void (*)(void *))insertion_sort,
    (void (*)(void *))quick_sort,
    (void (*)(void *))linear_search,
    (void (*)(void *))binary_search
};

//en privat funktion som värmer upp
static void warmup(int loops)
{
    volatile int tot = 0;
    for (int i = 0; i < loops; i++) {
        tot++;
    }
}

//en privat funktion som mäter tiden
static double measure_time(void (*func)(void *), void *arg)
{
    warmup(1000000); //sköts intern utan att det märks

    /*clock_t start = clock();
    func(arg);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;*/

    struct timespec start, end;
    
    if (clock_gettime(CLOCK_MONOTONIC, &start) == -1)
    {
        perror("clock_gettime start");
        exit(EXIT_FAILURE);
    }
    func(arg);

    if (clock_gettime(CLOCK_MONOTONIC, &end) == -1)
    {
        perror("clock_gettime end");
        exit(EXIT_FAILURE);
    }

    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

void *generate_input(case_t c, int size) {
    int *data = malloc(size * sizeof(int));
    if (!data) {
        fprintf(stderr, "Error: Failed to allocate memory for input of size %d\n", size);
        return NULL;
    }

    switch (c) {
        case best_t:
            // Best case: Sorterad array
            for (int i = 0; i < size; i++) {
                data[i] = i;
            }
            break;

        case worst_t:
            // Worst case: Omvänd sorterad array
            for (int i = 0; i < size; i++) {
                data[i] = size - i;
            }
            break;

        case average_t:
        default:
            // Average case: Slumpmässiga data
            for (int i = 0; i < size; i++) {
                data[i] = rand() % size;
            }
            break;
    }

    return data;
}
//frigör minne
void free_input(void *input)
{
    if (input != NULL)
    {
        free(input);
    }
}


//en public funktion som tar in algoritmen med olika inputs
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{

    for (int i = 0; i < n; i++)
    {
        //generera input baserat på case_t
        int size = SIZE_START * (1 << i);
        void *input = generate_input(c, size);

        if (input == NULL)
        {
            fprintf(stderr, "Error: Failed to generate input for case %d\n", i);
            continue;
        }

        //mät exekveringstiden
        double time = measure_time(algorithm_functions[a], input);

        

        //fyll resultat i bufferten
        buf[i].size = size;
        buf[i].time = time;

        free_input(input);
    }
}


