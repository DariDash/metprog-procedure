#ifndef PROCEDURE_UNITTESTS_H
#define PROCEDURE_UNITTESTS_H

#include "MatrixList.h"
#include "SquareMatrix.h"
#include "DiagonalMatrix.h"
#include "LowerTriangularMatrix.h"
#include <cassert>


void run_tests();
void test_add_matrix();
void test_read_write_from_file();
void test_get_sum_elements_matrix();
void test_sort_matrix_list();
void test_filter_matrix_list();


#endif // PROCEDURE_UNITTESTS_H
