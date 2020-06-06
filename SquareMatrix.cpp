#include "SquareMatrix.h"

using std::endl;


void read_matrix_from_file(SquareMatrix *square_matrix, int size, ifstream *fin) {
    int **_matrix = new int *[size];
    for (int row = 0; row < size; ++row) {
        _matrix[row] = new int[size];
        for (int col = 0; col < size; ++col) {
            *fin >> _matrix[row][col];
        }
    }
    square_matrix->matrix = _matrix;
}

void write_matrix_to_file(SquareMatrix *square_matrix, int size, ofstream *fout) {
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            *fout << square_matrix->matrix[row][col] << " ";
        }
        *fout << endl;
    }
}
