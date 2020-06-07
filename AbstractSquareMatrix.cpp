#include <fstream>

#include "AbstractSquareMatrix.h"

using std::endl;


string get_type_matrix(AbstractSquareMatrix *matrix) {
    switch (matrix->type_matrix) {
        case typeMatrix::SQUARE:
            return "Square";
        case typeMatrix::DIAGONAL:
            return "Diagonal";
        case typeMatrix::LOWERTRIANGULAR:
            return "Lower triangular";
    }
}

int get_size(AbstractSquareMatrix *matrix) {
    return matrix->size;
}

void read_matrix_from_file(AbstractSquareMatrix *matrix, ifstream *fin) {
    string type_matrix;
    *fin >> type_matrix;  // Тип матрицы


    string type_print;
    *fin >> type_print;

    if (type_print == "Row") {
        matrix->type_print = typePrint ::ROW;
    } else if (type_print == "Column") {
        matrix->type_print = typePrint::COLUMN;
    } else if (type_print == "One-dimensional") {
        matrix->type_print = typePrint::ONE_DIMENSIONAL_MATRIX;
    }

    *fin >> matrix->size; // Размерность матрицы

    if (type_matrix == "Square") {
        matrix->type_matrix = typeMatrix::SQUARE;
        read_matrix_from_file(&matrix->square_matrix, matrix->size, fin);
    } else if (type_matrix == "Diagonal") {
        matrix->type_matrix = typeMatrix::DIAGONAL;
        read_matrix_from_file(&matrix->diagonal_matrix, matrix->size, fin);
    } else if (type_matrix == "LowerTriangular") {
        matrix->type_matrix = typeMatrix::LOWERTRIANGULAR;
        read_matrix_from_file(&matrix->lower_triangular_matrix, matrix->size, fin);
    }
}

void write_matrix_to_file(AbstractSquareMatrix *matrix, ofstream *fout) {
    string type_film, optional_string;

    *fout << endl; // Пустая строка для читабельности

    *fout << get_type_matrix(matrix) << " matrix" << endl;
    *fout << "The output of the matrix " << get_type_print(matrix) << endl;
    *fout << "Size of matrix is " << matrix->size << endl;
    *fout << "Matrix:" << endl;

    switch (matrix->type_matrix) {
        case typeMatrix::SQUARE:
            write_matrix_to_file(&matrix->square_matrix, matrix->size, fout);
            break;
        case typeMatrix::DIAGONAL:
            write_matrix_to_file(&matrix->diagonal_matrix, matrix->size, fout);
            break;
        case typeMatrix::LOWERTRIANGULAR:
            write_matrix_to_file(&matrix->lower_triangular_matrix, matrix->size, fout);
            break;
    }

}

string get_type_print(AbstractSquareMatrix *matrix) {
    string type_print;
    switch (matrix->type_print) {
        case typePrint::ROW:
            return "by rows";
        case typePrint::COLUMN:
            return "by columns";
        case typePrint::ONE_DIMENSIONAL_MATRIX:
            return "is a one-dimensional matrix";
        default:
            return "";
    }
}
