#include <iostream>

void printFibonacci(int n) {
    int a = 0, b = 1, next;
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = a + b;
            a = b;
            b = next;
        }
        std::cout << next << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of Fibonacci terms: ";
    std::cin >> n;
    printFibonacci(n);
    return 0;
}