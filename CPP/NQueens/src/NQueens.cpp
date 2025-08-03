#include "NQueens.hpp"

#include <cmath>
#include <fstream>

int NQueens::nQueens(const int n) {
    this->n = n;
    coordinates.clear();
    coordinates.reserve(n);
    auto count = 0;
    std::ofstream outfile;
    std::ifstream infile;
    infile.open("mat.txt", std::ifstream::out | std::ifstream::trunc);
    infile.close();
    outfile.open("mat.txt", std::ofstream::app);
    for (auto row = 0; row < n; ++row) {
        coordinates.emplace_back(std::make_pair(row, 0));
        if (placeQueen(1)) {
            ++count;
            writeMatrix(outfile);
        }
        coordinates.clear();
    }
    outfile.close();
    return count;
}

bool NQueens::placeQueen(const int col) {
    if (col >= n) {
        return true;
    }
    for (auto row = 0; row < n; ++row) {
        coordinates.emplace_back(std::make_pair(row, col));
        if (isSafe(row, col) && placeQueen(col + 1)) {
            return true;
        }
        coordinates.pop_back();
    }
    return false;
}

bool NQueens::isSafe(const int row, const int col) const {
    if (col == 0) {
        return true;
    }
    const int coord_length = coordinates.size();
    for (auto i = 0; i < coord_length - 1; ++i) {
        const auto& elem = coordinates.at(i);
        const auto r = elem.first;
        const auto c = elem.second;
        if (row == r) {
            return false;
        }
        const auto abs_r = std::abs(row - r);
        const auto abs_c = std::abs(col - c);
        if (abs_r == abs_c) {
            return false;
        }
    }
    return true;
}

void NQueens::writeMatrix(std::ofstream& outfile) const {
    std::vector<std::vector<char>> mat(n, std::vector<char>(n, '0'));
    for (const auto& pair : coordinates) {
        const auto row = pair.first;
        const auto col = pair.second;
        mat[row][col] = 'X';
    }
    for (const auto& vect : mat) {
        for (const char c : vect) {
            outfile << c << ' ';
        }
        outfile << '\n';
    }
    outfile << '\n';
}

NQueens::NQueens(): n(0) {}
