#include <iostream>

#include "MatrixList.h"
#include "UnitTests.h"

using std::cout;
using std::endl;
using std::string;


int main(int argc, char* argv[]) {

    run_tests();

    if (argc != 3) {
        cout << "Type input and output files" << endl;
        return -1;
    }

    MatrixList *matrix_list = init_matrix_list();

    string input_path = argv[1];
    bool is_success_read = read_matrices_from_file(matrix_list, input_path);
    if (!is_success_read) {
        cout << "Failed to open file for reading" << endl;
        return -1;
    }

    string output_path = argv[2];
    bool is_success_write = write_matrices_to_file(matrix_list, output_path);
    if (!is_success_write) {
        cout << "Failed to open file for writing" << endl;
        return -1;
    }

    cout << "Success" << endl;
    return 0;
}