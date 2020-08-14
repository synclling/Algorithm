#pragma once

void collecting_apples(int n, int m);

// Recursively1
// start with: collecting_apples_recursively1(0, 0);
// recursively: from (0, 0) to (n - 1, m - 1)
void collecting_apples_recursively1(int x, int y);

// Recursively2
// start with: collecting_apples_recursively2(n - 1, m - 1);
// recrusively: from (n - 1, m - 1) to (0, 0)
void collecting_apples_recursively2(int x, int y);