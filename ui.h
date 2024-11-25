#ifndef UI_H
#define UI_H
#include "analyze.h"

#define MENU_WIDTH 40
#define RESULT_ROWS 6
#define RESULT_WIDTH 70

// ui_run starts a terminal-based user interface
void ui_results(int size, double *resultArr, int n, algorithm_t a, case_t c);
void ui_run();

#endif
