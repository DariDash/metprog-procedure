#ifndef PROCEDURE_LOWERTRIANGULARMATRIX_H
#define PROCEDURE_LOWERTRIANGULARMATRIX_H

#include <fstream>

using std::ifstream;
using std::ofstream;


struct LowerTriangularMatrix {
    int *matrix;
};

void read_matrix_from_file(LowerTriangularMatrix *lower_triangular_matrix, int size, ifstream *fin);
void write_matrix_to_file(LowerTriangularMatrix *lower_triangular_matrix, int size, ofstream *fout);
int get_sum_elements_matrix(LowerTriangularMatrix *lower_triangular_matrix, int size);

#endif //PROCEDURE_LOWERTRIANGULARMATRIX_H
