#include "NQueens.hpp"

#include <iostream>

int main() {
    int n;
    std::cout << "No. of queens: ";
    std::cin >> n;
    NQueens nq;
    const auto queens = nq.nQueens(n);
    std::cout << queens << '\n';
    return 0;
}
