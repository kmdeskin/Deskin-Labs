#include <iostream>
#include <fstream>
const int MAX_SIZE = 100; 
void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int& N, const std::string& filename);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int N, const std::string& matrixName);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N);
int main() {
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int N1;
    int N2;
    std::cout << "Kara Deskin" << std::endl;
    std::cout << "Lab 6: Matrix Manipulation" << "\n";
   
    readMatrixFromFile(matrix1, N1, "matrix_input.txt"); 
    std::cout << "Size of the first matrix (N1): " << N1 << std::endl;
    std::cout << "Matrix A:" << std::endl;

    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N1; ++j) {
            std::cout << matrix1[i][j] << "";
        }
        std::cout << std::endl;
    }
    std::ifstream inputFile("matrix_input.txt");
    inputFile >> N2; 
    for (int i = 0; i < N2; ++i) {
        for (int j = 0; j < N2; ++j) {
            int value;
            inputFile >> value; 
        }
    }
    for (int i = 0; i < N2; ++i) {
        for (int j = 0; j < N2; ++j) {
            if (!(inputFile >> matrix2[i][j])) {
                std::cerr << "Error: Not enough data in the file for the second matrix." << std::endl;
                exit(1);
            }
        }
    }
    std::cout << "Size of the second matrix (N2): " << N2 << std::endl;
    std::cout << "Matrix B:" << std::endl;

    for (int i = 0; i < N2; ++i) {
        for (int j = 0; j < N2; ++j) {
            std::cout << matrix2[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    if (N1 != N2) {
        std::cout << "Matrix addition is not possible due to different sizes." << std::endl;
        std::cout << "Matrix multiplication is not possible due to different sizes." << std::endl;
        std::cout << "Matrix subtraction is not possible due to different sizes." << std::endl;
    } else {
        addMatrices(matrix1, matrix2, result, N1);
        std::cout << "Matrix Sum (A + B):" << std::endl;

        printMatrix(result, N1, "");
        multiplyMatrices(matrix1, matrix2, result, N1);
        std::cout << "Matrix Product (A * B):" << std::endl;
        
        printMatrix(result, N1, "");
        subtractMatrices(matrix1, matrix2, result, N1);
        std::cout << "Matrix Difference (A - B):" << std::endl;
        printMatrix(result, N1, "");
    }
    return 0;
}
void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int& N, const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        exit(1);
    }
    inputFile >> N; 
    if (N <= 0 || N > MAX_SIZE) {
        std::cerr << "Error: Invalid matrix size." << std::endl;
        exit(1);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(inputFile >> matrix[i][j])) {
                std::cerr << "Error: Not enough data in the file for a " << N << "x" << N << " matrix." << std::endl;
                exit(1);
            }
        }
    }
}
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int N, const std::string& matrixName) {
    std::cout << matrixName << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = 0; 
            for (int k = 0; k < N; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}







