#include <iostream>
#include <sstream>
#include "UnitTests.h"

using std::cout;
using std::endl;
using std::stringstream;


void run_tests() {
    test_add_matrix();
    test_read_write_from_file();
    test_get_sum_elements_matrix();
    test_sort_matrix_list();
    test_filter_matrix_list();

    cout << "Tests passed successfully" << endl;
}

void test_add_matrix() {
    AbstractSquareMatrix *matrix1 = new AbstractSquareMatrix();
    MatrixList *matrix_list = init_matrix_list();
    assert(matrix_list->size == 0);
    add_matrix(matrix_list, matrix1);
    assert(matrix_list->size == 1);
    add_matrix(matrix_list, matrix1);
    assert(matrix_list->size == 2);
}

void test_read_write_from_file() {
    string input_path = "test_files/testReadWriteFromFile_in.txt";
    string output_path = "test_files/testReadWriteFromFile_out.txt";

    string expected = "Number of matrices is 4\n"
                      "\n"
                      "Square matrix\n"
                      "The output of the matrix by columns\n"
                      "Size of matrix is 4\n"
                      "Matrix:\n"
                      "4 5 2 6 \n"
                      "0 2 5 7 \n"
                      "1 3 2 6 \n"
                      "1 42 67 4 \n"
                      "\n"
                      "Diagonal matrix\n"
                      "The output of the matrix by rows\n"
                      "Size of matrix is 2\n"
                      "Matrix:\n"
                      "42 0 \n"
                      "0 72 \n"
                      "\n"
                      "Lower triangular matrix\n"
                      "The output of the matrix is a one-dimensional matrix\n"
                      "Size of matrix is 2\n"
                      "Matrix:\n"
                      "4 0 \n"
                      "2 1 \n"
                      "\n"
                      "Diagonal matrix\n"
                      "The output of the matrix by rows\n"
                      "Size of matrix is 3\n"
                      "Matrix:\n"
                      "1 0 0 \n"
                      "0 4 0 \n"
                      "0 0 7 \n";

    MatrixList *matrix_list = init_matrix_list();

    read_matrices_from_file(matrix_list, input_path);
    write_matrices_to_file(matrix_list, output_path);

    ifstream in_file(output_path);
    stringstream buffer;
    buffer << in_file.rdbuf();
    string real = buffer.str();
    in_file.close();

    assert(real == expected);
}

void test_get_sum_elements_matrix() {
    string tmp, size;
    AbstractSquareMatrix *matrix = new AbstractSquareMatrix();
    ifstream fin("test_files/testGetSumElementsMatrix1.txt");
    read_matrix_from_file(matrix, &fin);
    assert(get_sum_elements_matrix(matrix) == 7);
    fin.close();

    fin.open("test_files/testGetSumElementsMatrix2.txt");
    read_matrix_from_file(matrix, &fin);
    assert(get_sum_elements_matrix(matrix) == 55);
    fin.close();

    fin.open("test_files/testGetSumElementsMatrix3.txt");
    read_matrix_from_file(matrix, &fin);
    assert(get_sum_elements_matrix(matrix) == 114);
    fin.close();

}

void test_sort_matrix_list() {
    string input_path = "test_files/testSortMatrixList_in.txt";
    string output_path = "test_files/testSortMatrixList_out.txt";

    string expected = "Number of matrices is 4\n"
                      "\n"
                      "Lower triangular matrix\n"
                      "The output of the matrix is a one-dimensional matrix\n"
                      "Size of matrix is 2\n"
                      "Matrix:\n"
                      "4 0 \n"
                      "2 1 \n"
                      "\n"
                      "Diagonal matrix\n"
                      "The output of the matrix by rows\n"
                      "Size of matrix is 3\n"
                      "Matrix:\n"
                      "1 0 0 \n"
                      "0 4 0 \n"
                      "0 0 7 \n"
                      "\n"
                      "Square matrix\n"
                      "The output of the matrix by columns\n"
                      "Size of matrix is 4\n"
                      "Matrix:\n"
                      "4 5 2 6 \n"
                      "0 2 5 7 \n"
                      "1 3 2 6 \n"
                      "1 4 3 4 \n"
                      "\n"
                      "Diagonal matrix\n"
                      "The output of the matrix by rows\n"
                      "Size of matrix is 2\n"
                      "Matrix:\n"
                      "42 0 \n"
                      "0 72 \n";

    MatrixList *matrix_list = init_matrix_list();

    read_matrices_from_file(matrix_list, input_path);
    write_matrices_to_file(matrix_list, output_path);

    ifstream in_file(output_path);
    stringstream buffer;
    buffer << in_file.rdbuf();
    string real = buffer.str();
    in_file.close();

    assert(real == expected);
}

void test_filter_matrix_list() {
    string input_path = "test_files/testFilterMatrixList_in.txt";
    string output_path = "test_files/testFilterMatrixList_out.txt";

    string expected = "Number of matrices is 2\n"
                      "\n"
                      "Diagonal matrix\n"
                      "The output of the matrix by rows\n"
                      "Size of matrix is 2\n"
                      "Matrix:\n"
                      "42 0 \n"
                      "0 72 \n"
                      "\n"
                      "Diagonal matrix\n"
                      "The output of the matrix by rows\n"
                      "Size of matrix is 3\n"
                      "Matrix:\n"
                      "1 0 0 \n"
                      "0 4 0 \n"
                      "0 0 7 \n";

    MatrixList *matrix_list = init_matrix_list();

    read_matrices_from_file(matrix_list, input_path);
    write_matrices_to_file(matrix_list, output_path);

    ifstream in_file(output_path);
    stringstream buffer;
    buffer << in_file.rdbuf();
    string real = buffer.str();
    in_file.close();

    assert(real == expected);
}
