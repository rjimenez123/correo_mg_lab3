#include "aux_lib.h"
#include <iostream>
#include <iomanip>

using namespace std;

void print_line(char c, int n) {
        for (int i = 0; i < n; i++) {
                cout.put(c);
        }
        cout.put('\n');
}
