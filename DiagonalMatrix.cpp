#include "DiagonalMatrix.h"

using std::endl;


void read_matrix_from_file(DiagonalMatrix *square_matrix, int size, ifstream *fin) {
    int *_matrix = new int[size];
    for (int col = 0; col < size; ++col) {
        *fin >> _matrix[col];
    }
    square_matrix->matrix = _matrix;
}

void write_matrix_to_file(DiagonalMatrix *diagonal_matrix, int size, ofstream *fout) {
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (row == col) {
                *fout << diagonal_matrix->matrix[col];
            } else {
                *fout << "0";
            }
            *fout << " ";
        }
        *fout << endl;
    }
}

