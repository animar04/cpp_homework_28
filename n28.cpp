#include <iostream>

int** createMatrix(int rows, int cols) {
    int** mat = new int*[rows];
    for(int i=0;i<rows;i++){
        mat[i] = new int[cols];
        for(int j=0;j<cols;j++)
            mat[i][j] = rand()%10;
    }
    return mat;
}void printMatrix(int** mat, int rows, int cols) {
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++) std::cout << mat[i][j] << " ";
        std::cout << std::endl;
    }
}
int totalSum(int** mat, int rows, int cols){
    int sum = 0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            sum += mat[i][j];
    return sum;
}
void printMax(int** mat1, int rows1, int cols1, int** mat2, int rows2, int cols2){
    int sum1 = totalSum(mat1, rows1, cols1);
    int sum2 = totalSum(mat2, rows2, cols2);

    std::cout << "Matrix 1"<< std::endl;
    printMatrix(mat1, rows1, cols1);
    std::cout << "sum 1 " << sum1 << "\n" << std::endl;

    std::cout << "Matrix 2"<< std::endl;
    printMatrix(mat2, rows2, cols2);
    std::cout << "sum 2 " << sum2 << "\n" << std::endl;

    std::cout << "max sum matrix" << std::endl;
    if(sum1 >= sum2)
        printMatrix(mat1, rows1, cols1);
    else
        printMatrix(mat2, rows2, cols2);
}
int main(){
    int rows1=6, cols1=4, rows2=5, cols2=6;

    int** mat1 = createMatrix(rows1, cols1);
    int** mat2 = createMatrix(rows2, cols2);

    printMax(mat1, rows1, cols1, mat2, rows2, cols2);
    return 0;
}   //28