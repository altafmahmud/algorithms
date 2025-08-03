#ifndef NQUEENS_HPP
#define NQUEENS_HPP

#include <vector>

class NQueens {
public:
    NQueens();
    ~NQueens() = default;

    int nQueens(const int n);

private:
    bool placeQueen(const int col);
    bool isSafe(const int row, const int col) const;
    void writeMatrix(std::ofstream& outfile) const;

    std::vector<std::pair<int, int>> coordinates;
    int n;
};

#endif
