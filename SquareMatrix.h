#ifndef PROCEDURE_SQUAREMATRIX_H
#define PROCEDURE_SQUAREMATRIX_H

#include <fstream>

using std::ifstream;
using std::ofstream;


struct SquareMatrix {
    int **matrix;
};

void read_matrix_from_file(SquareMatrix *square_matrix, int size, ifstream *fin);
void write_matrix_to_file(SquareMatrix *square_matrix, int size, ofstream *fout);

#endif //PROCEDURE_SQUAREMATRIX_H
