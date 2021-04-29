#ifndef INTARR_H_
#define INTARR_H_

    int sum(int *array, int len);
    int max(int *array, int len);
    int min(int *array, int len);

    float average(int *array, int len);

    void display(int *array, int len);

    int contains(int *array, int *sequence, int arr_len, int seq_len);

    void cumsum(int *array, int *sums, int len);

    void display_2d(int **array, int outer_len, int inner_len);

    void flatten_2d(int **array_2d, int *array, int outer_len, int inner_len);
    void unflatten_2d(int **array_2d, int *array, int outer_len, int inner_len);

    void display_3d(int ***array_3d, int dim1_len, int dim2_len, int dim3_len);

    void flatten_3d(int ***array_3d, int *array, int dim1_len, int dim2_len, int dim3_len);
    void unflatten_3d(int ***array_3d, int *array, int dim1_len, int dim2_len, int dim3_len);

#endif
