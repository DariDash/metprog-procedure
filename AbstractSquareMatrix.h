#ifndef PROCEDURE_ABSTRACTSQUAREMATRIX_H
#define PROCEDURE_ABSTRACTSQUAREMATRIX_H

#include <iostream>
#include <fstream>

#include "DiagonalMatrix.h"
#include "SquareMatrix.h"
#include "DiagonalMatrix.h"
#include "LowerTriangularMatrix.h"

using std::ifstream;
using std::ofstream;
using std::string;

enum typeMatrix {DIAGONAL, SQUARE, LOWERTRIANGULAR};

struct AbstractSquareMatrix {
    int size;
    typeMatrix type_matrix;
    DiagonalMatrix diagonal_matrix;
    SquareMatrix square_matrix;
    LowerTriangularMatrix lower_triangular_matrix;
};

void read_matrix_from_file(AbstractSquareMatrix *matrix, ifstream *fin);
void write_matrix_to_file(AbstractSquareMatrix *matrix, ofstream *fout);
string get_type_matrix(AbstractSquareMatrix *matrix);
int get_size(AbstractSquareMatrix *matrix);

#endif //PROCEDURE_ABSTRACTSQUAREMATRIX_H
