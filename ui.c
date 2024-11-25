#include "ui.h"
#include "io.h"
#include "analyze.h"

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

//
// Private
//

static void ui_invalid_input()
{
	printf("info> bad input\n");
}

static void ui_exit()
{
	printf("info> bye\n");
}

static char ui_get_choice()
{
	char buf[3];

	printf("input> ");
	return read_line(buf, 3) ? buf[0] : 0;
}

static void ui_line(char c, int n)
{
	while (n-- > 0) {
		putchar(c);
	}
	putchar('\n');
}

static void ui_menu_options(const char *options[], int num_options)
{
	int i;

	for (i=0; i<num_options; i++) {
		printf("    %c) %s\n", 'a'+i, options[i]);
	}
}

static void ui_menu()
{
	const char *options[] = {
		"Menu",
		"Exit\n",
		"Bubble sort best case",
		"Bubble sort worst case",
		"Bubble sort average case\n",
		"Quick sort best case",
		"Quick sort worst case",
		"Quick sort average case\n",
		"Linear search best case",
		"Linear search worst case",
		"Linear search average case\n",
		"Binary search best case",
		"Binary search worst case",
		"Binary search average case",
		// TODO: complete menu
	};

	ui_line('-', MENU_WIDTH);
	ui_menu_options(options, sizeof(options) / sizeof(char *));
	ui_line('-', MENU_WIDTH);
}
const char* generate_title(algorithm_t a, case_t c){
	const char *algorithm_name, *case_name;

	switch (a){
		case bubble_sort_t: algorithm_name = "Bubble Sort"; break;
		case quick_sort_t: algorithm_name = "Quick Sort"; break;
		case insertion_sort_t: algorithm_name = "Insertion Sort"; break;
		case linear_search_t: algorithm_name = "Linear Search"; break;
		case binary_search_t: algorithm_name = "Binary Search"; break;
		default: algorithm_name = "Unknown Algorithm"; break;
	
	}

	switch (c) {
		case best_t: case_name = "Best Case"; break;
        case worst_t: case_name = "Worst Case"; break;
        case average_t: case_name = "Average Case"; break;
        default: case_name = "Unknown Case"; break;
    }

	static char title[100];
	snprintf(title, sizeof(title), "%s - %s", algorithm_name, case_name);
	return title;
}

//
// Public
//

void ui_results(int size, double *resultArr, int n, algorithm_t a, case_t c)
{ 
	const char *title = generate_title(a, c);
	int title_length = strlen(title); //längden på titeln
	int padding = (RESULT_WIDTH - title_length) / 2; //mellanslag före titeln
	ui_line('*', RESULT_WIDTH);
	
	printf("%*s%s\n", padding, "",title);
	
	ui_line('-', RESULT_WIDTH); 

	printf("%5s \t","Size");
	printf("%10s \t", "Time T(s)");
	printf("%7s \t", "T/logn");
	printf("%4s \t", "T/n");
	printf("%14s \t\n", "T/nlog");

	ui_line('-', RESULT_WIDTH);

	for (int i = 0; i < n; i++){
		
		switch(a){
			case bubble_sort_t:
				switch(c){
					case best_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i] / log(size)),
						(resultArr[i] / size),
						(resultArr[i] / (size * size)));
						break;
					case worst_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i] / (size * log(size))),
						(resultArr[i] / (size * size)),
						(resultArr[i] / ((long long)size * size * size)));
						break;
					case average_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i] / (size * log(size))),
						(resultArr[i] / (size * size)),
						(resultArr[i] / ((long long)size * size * size)));
						break;
				}
				break;
			case insertion_sort_t:
				switch(c){
					case best_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i] / log(size)),
						(resultArr[i] / size),
						(resultArr[i] / (size * size)));
						break;
					case worst_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i] / (size * log(size))),
						(resultArr[i] / (size * size)),
						(resultArr[i] / ((long long)size * size * size)));
						break;
					case average_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i] / (size * log(size))),
						(resultArr[i] / (size * size)),
						(resultArr[i] / ((long long)size * size * size)));
						break;
				}
				break;
			case quick_sort_t:
				switch(c){
					case best_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i] / size),
						(resultArr[i] / (size * log(size))),
						(resultArr[i] / (size * size)));
						break;
					case worst_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i] / (size * log(size))),
						(resultArr[i] / (size * size)),
						(resultArr[i] / ((long long)size * size * size)));
						break;
					case average_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i] / size),
						(resultArr[i] / (size * log(size))),
						(resultArr[i] / (size * size)));
						break;
				}
				break;
			case linear_search_t:
				switch(c){
					case best_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i]),
						(resultArr[i]),
						(resultArr[i] / size));
						break;
					case worst_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i] / log(size)),
						(resultArr[i] / size),
						(resultArr[i] / (size * size)));
						break;
					case average_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i] / size),
						(resultArr[i] / (size * log(size))),
						(resultArr[i] / (size * size)));
						break;
				}
				break;
			case binary_search_t:
				switch(c){
					case best_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i]),
						(resultArr[i]),
						(resultArr[i] / size));
						break;
					case worst_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i]),
						(resultArr[i]),
						(resultArr[i]));
						break;
					case average_t:
						printf("%-5d \t %.8f \t %.4e \t %.4e \t %.4e\n",
						(size),
						(resultArr[i]),
						(resultArr[i]),
						(resultArr[i] / log(size)),
						(resultArr[i] / size));
						break;
				}
				break;
		}
			size *= 2;
	}
	

	ui_line('*', RESULT_WIDTH);

}

void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];
	//double resultArr[RESULT_ROWS];
	show_menu = true;
	running = true;
	while (running) {
		if (show_menu) {
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice()) {
			// House keeping
			case 'a':
				show_menu = true;
				break;
			case 'b':
				running = false;
				break;
			// Bubble sort
			case 'c':
				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, bubble_sort_t, best_t);*/
				break;
			// Invalid input
			case 'd':
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, bubble_sort_t, worst_t);*/
				break;
			case 'e':
				benchmark(bubble_sort_t, average_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, bubble_sort_t, average_t);*/
				break;
			case 'f':
				benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, quick_sort_t, best_t);*/
				break;
			case 'g':
				benchmark(quick_sort_t, worst_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, quick_sort_t, worst_t);*/
				break;
			case 'h':
				benchmark(quick_sort_t, average_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, quick_sort_t, worst_t);*/
				break;
			case 'i':
				benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, insertion_sort_t, best_t);*/
				break;
			case 'j':
				benchmark(insertion_sort_t, worst_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, insertion_sort_t, worst_t);*/
				break;
			case 'k':
				benchmark(insertion_sort_t, average_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, insertion_sort_t, average_t);*/
				break;
			case 'l':
				/*benchmark(linear_search_t, best_t, result, RESULT_ROWS);
				for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, linear_search_t, best_t);*/
				break;
			case 'm':
				benchmark(linear_search_t, worst_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, linear_search_t, worst_t);*/
				break;
			case 'n':
				benchmark(linear_search_t, average_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, linear_search_t, average_t);*/
				break;
			case 'o':
				benchmark(binary_search_t, best_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, binary_search_t, best_t);*/
				break;
			case 'p':
				benchmark(binary_search_t, worst_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, binary_search_t, worst_t);*/
				break;
			case 'q':
				benchmark(binary_search_t, average_t, result, RESULT_ROWS);
				/*for (int i = 0; i < RESULT_ROWS; i++){
					resultArr[i] = result[i].time;
				}
				ui_results(SIZE_START, resultArr, RESULT_ROWS, binary_search_t, average_t);*/
				break;
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}
