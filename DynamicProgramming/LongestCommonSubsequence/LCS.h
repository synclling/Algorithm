#pragma once

#define EQUAL	1	// EQUAL表示c[i][j]是由c[i - 1][j - 1] + 1来的
#define UP		2	// UP表示c[i][j]是由c[i - 1][j] + 1来的
#define LEFT	3	// LEFT表示c[i][j]是由c[i][j - 1] + 1来的


int lcs_length(char *str1, char *str2, int **c, int **b);

void print_lcs(char *str1, int **b, int i, int j);

void lcs(char *str1, char *str2);