#include <iostream>

#include "MatrixList.h"
#include "UnitTests.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;


int main(int argc, char* argv[]) {

//    run_tests();

    if (argc != 3) {
        cerr << "Type input and output files" << endl;
        return -1;
    }

    MatrixList *matrix_list = init_matrix_list();

    string input_path = argv[1];
    try {
        read_matrices_from_file(matrix_list, input_path);
    } catch (const char* msg) {
        cerr << msg << endl;
        return -1;
    }

    string output_path = argv[2];
    try {
        write_matrices_to_file(matrix_list, output_path);
    } catch (const char* msg) {
        cerr << msg << endl;
        return -1;
    }

    cout << "Success" << endl;
    return 0;
}