#include <iostream>
#include <string>

using namespace std;

void print_triangle(int n) {
    for (int i = 1; i <= n; ++i) {
        string row = "";
        for (int j = 1; j <= i; ++j) {
            row += to_string(i * j) + " "; 
        }
        cout << row << endl;
    }
}

int main() {
    int n = 3; 
    print_triangle(n);
    return 0;
}