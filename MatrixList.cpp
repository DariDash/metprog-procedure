
#include "MatrixList.h"

using std::endl;


MatrixList *init_matrix_list() {
    MatrixList *matrix_list = new MatrixList();
    matrix_list->size = 0;
    matrix_list->first_matrix = nullptr;
    matrix_list->last_matrix = nullptr;
    return matrix_list;
}

void add_matrix(MatrixList *matrix_list, AbstractSquareMatrix *matrix) {
    MatrixItem *new_matrix_item = new MatrixItem();
    new_matrix_item->matrix = matrix;
    new_matrix_item->next_matrix = nullptr;

    if (matrix_list->size == 0) {
        matrix_list->first_matrix = new_matrix_item;
    } else if (matrix_list->size == 1) {
        matrix_list->first_matrix->next_matrix = new_matrix_item;
        matrix_list->last_matrix = new_matrix_item;
    } else {
        matrix_list->last_matrix->next_matrix = new_matrix_item;
        matrix_list->last_matrix = new_matrix_item;
    }

    matrix_list->size++;
}

bool read_matrices_from_file(MatrixList *matrix_list, string filename) {

    ifstream fin(filename);

    if (!fin.is_open()) {
        return false;
    }

    bool do_sort;
    int num_matrices;
    string type_matrix, sort, filter;
    fin >> num_matrices; // Кол-во матриц

    fin >> sort;

    if (sort == "Sort") {
        do_sort = true;
    } else if (sort != "NoSort") {
        return false;
    }

    fin >> filter;

    for (int i = 0; i < num_matrices; ++i) {
        AbstractSquareMatrix *square_matrix = new AbstractSquareMatrix();
        read_matrix_from_file(square_matrix, &fin);

        if (filter == "All" or filter == get_struct_name(square_matrix)) {
            add_matrix(matrix_list, square_matrix);
        }
    }

    if (do_sort) {
        sort_list(matrix_list);
    }

    fin.close();
    return true;
}

bool write_matrices_to_file(MatrixList *matrix_list, string filename) {
    ofstream fout(filename);

    fout << "Number of matrices is " << matrix_list->size << endl; // Вывод размера списка в файл

    if (!matrix_list->size) {
        fout.close();
        return true;
    }

    MatrixItem *current_film_item = matrix_list->first_matrix;

    for (int i = 0; i < matrix_list->size; ++i) {
        write_matrix_to_file(current_film_item->matrix, &fout);
        current_film_item = current_film_item->next_matrix;
    }

    fout.close();
    return true;
}

void sort_list(MatrixList *matrix_list) {
    for(MatrixItem* matrix_item2 = matrix_list->first_matrix; matrix_item2; matrix_item2 = matrix_item2->next_matrix) {
        for(MatrixItem* matrix_item1 = matrix_list->first_matrix; matrix_item1->next_matrix; matrix_item1 = matrix_item1->next_matrix) {
            if(get_sum_elements_matrix(matrix_item1->matrix) > get_sum_elements_matrix(matrix_item1->next_matrix->matrix)) {
                std::iter_swap(&matrix_item1->matrix, &matrix_item1->next_matrix->matrix);
            }
        }
    }
}