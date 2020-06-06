#ifndef PROCEDURE_DIAGONALMATRIX_H
#define PROCEDURE_DIAGONALMATRIX_H

#include <fstream>

using std::ifstream;
using std::ofstream;


struct DiagonalMatrix {
    int *matrix;
};

void read_matrix_from_file(DiagonalMatrix *diagonal_matrix, int size, ifstream *fin);
void write_matrix_to_file(DiagonalMatrix *diagonal_matrix, int size, ofstream *fout);
int get_sum_elements_matrix(DiagonalMatrix *diagonal_matrix, int size);

#endif //PROCEDURE_DIAGONALMATRIX_H
