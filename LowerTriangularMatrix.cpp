#include "LowerTriangularMatrix.h"

using std::endl;


void read_matrix_from_file(LowerTriangularMatrix *lower_triangular_matrix, int size, ifstream *fin) {

    int values_number = (size - 1)*size/2 + size; // Кол-во элементов которые необходимо считать

    int *_matrix = new int [values_number];
    for (int col = 0; col < values_number; ++col) {
        *fin >> _matrix[col];
    }

    lower_triangular_matrix->matrix = _matrix;
}

void write_matrix_to_file(LowerTriangularMatrix *lower_triangular_matrix, int size, ofstream *fout) {
    int count = 0;
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (row >= col) {
                *fout << lower_triangular_matrix->matrix[count];
                count++;
            } else {
                *fout << "0";
            }
            *fout << " ";
        }
        *fout << endl;
    }
}

int get_sum_elements_matrix(LowerTriangularMatrix *lower_triangular_matrix, int size) {

    int values_number = (size - 1)*size/2 + size; // Кол-во элементов которые необходимо считать

    int sum = 0;

    for (int col = 0; col < values_number; ++col) {
        sum += lower_triangular_matrix->matrix[col];
    }

    return sum;
}
