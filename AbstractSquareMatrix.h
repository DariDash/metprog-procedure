#ifndef PROCEDURE_ABSTRACTSQUAREMATRIX_H
#define PROCEDURE_ABSTRACTSQUAREMATRIX_H

#include <iostream>
#include <fstream>

#include "DiagonalMatrix.h"
#include "SquareMatrix.h"
#include "DiagonalMatrix.h"

using std::ifstream;
using std::ofstream;
using std::string;

enum typeMatrix {DIAGONAL, SQUARE};
enum typePrint {ROW, COLUMN, ONE_DIMENSIONAL_MATRIX};

struct AbstractSquareMatrix {
    int size;
    typeMatrix type_matrix;
    typePrint type_print;
    DiagonalMatrix diagonal_matrix;
    SquareMatrix square_matrix;
};

void read_matrix_from_file(AbstractSquareMatrix *matrix, ifstream *fin);
void write_matrix_to_file(AbstractSquareMatrix *matrix, ofstream *fout);
string get_type_matrix(AbstractSquareMatrix *matrix);
int get_size(AbstractSquareMatrix *matrix);
string get_type_print(AbstractSquareMatrix *matrix);

#endif //PROCEDURE_ABSTRACTSQUAREMATRIX_H
