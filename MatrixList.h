#ifndef PROCEDURE_MATRIXLIST_H
#define PROCEDURE_MATRIXLIST_H

#include "AbstractSquareMatrix.h"
#include "MatrixItem.h"

using std::string;

struct MatrixList {
    int size;
    MatrixItem *first_matrix;
    MatrixItem *last_matrix;
};

MatrixList* init_matrix_list();
void add_matrix(MatrixList *matrix_list, AbstractSquareMatrix *matrix);
bool read_matrices_from_file(MatrixList *matrix_list, string filename);
bool write_matrices_to_file(MatrixList *matrix_list, string filename);

#endif //PROCEDURE_MATRIXLIST_H