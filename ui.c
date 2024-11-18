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
static void ui_results(const result_t *results, int rows, const char *title)
{
	int title_length = strlen(title); //längden på titeln
	int padding = (RESULT_WIDTH - title_length) / 2; //mellanslag före titeln
	ui_line('*', RESULT_WIDTH);
	
	for (int i = 0; i < padding; i++)
	{
		putchar(' ');
	}
	printf("%s\n", title);
	
	ui_line('-', RESULT_WIDTH); 

	printf("%-8s %-12s %-12s %-12s %-12s\n",
	"Size", "Time T(s)", "T/logn", "T/n", "T/nlog");

	ui_line('-', RESULT_WIDTH);

	for (int i = 0; i < rows; i++){
		int size = results[i].size;
		double time = results[i].time;
		double logn = log(size) / log(2);

		printf("%-8d %-12.6f %-12.6f %-12.6f%-12.6f\n",
		size,
		time,
		time / logn,
		time / size,
		time / (size * logn));
	}

	ui_line('*', RESULT_WIDTH);

}

//
// Public
//
void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];
	
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
				ui_results(result, RESULT_ROWS, "Bubble Sort - Best Case");
				break;
			// Invalid input
			case 'd':
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
				printf("todo> implement BE + present results in FE\n");
				break;
			case 'e':
				benchmark(bubble_sort_t, average_t, result, RESULT_ROWS);
				printf("todo> implement BE + present results in FE\n");
				break;
			case 'f':
				benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
				printf("todo> implement BE + present results in FE\n");
				break;
			case 'g':
				benchmark(quick_sort_t, worst_t, result, RESULT_ROWS);
				printf("todo\n");
				break;
			case 'h':
				benchmark(quick_sort_t, average_t, result, RESULT_ROWS);
				printf("todo\n");
				break;
			case 'i':
				benchmark(linear_search_t, best_t, result, RESULT_ROWS);
				printf("todo\n");
				break;
			case 'j':
				benchmark(linear_search_t, worst_t, result, RESULT_ROWS);
				printf("todo\n");
				break;
			case 'k':
				benchmark(linear_search_t, average_t, result, RESULT_ROWS);
				printf("todo\n");
				break;
			case 'l':
				benchmark(binary_search_t, best_t, result, RESULT_ROWS);
				printf("todo\n");
				break;
			case 'm':
				benchmark(binary_search_t, worst_t, result, RESULT_ROWS);
				printf("todo\n");
				break;
			case 'n':
				benchmark(binary_search_t, average_t, result, RESULT_ROWS);
				printf("todo\n");
				break;
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}
