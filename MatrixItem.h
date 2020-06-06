#ifndef PROCEDURE_MATRIXITEM_H
#define PROCEDURE_MATRIXITEM_H

#include "AbstractSquareMatrix.h"

struct MatrixItem {
    AbstractSquareMatrix *matrix;
    MatrixItem *next_matrix;
};

#endif //PROCEDURE_MATRIXITEM_H
