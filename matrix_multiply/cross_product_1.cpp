#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
using namespace std;

// Cross product of matrices
vector<vector<int>> crossProduct(vector<vector<int>> A, vector<vector<int>> B) {
    int rows_A = A.size();          
    int cols_A = A[0].size();       
    int rows_B = B.size();
    int cols_B = B[0].size();       

    // Check if the matrices are compatible for multiplication
    if (rows_B != cols_A) {
        throw runtime_error("Matrices incompatible, rows of B not equal to cols of A");
    }

    vector<vector<int>> result_matrix(rows_A, vector<int>(cols_B, 0));

    // multiplication logic
    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < cols_B; j++) {
            for (int k = 0; k < cols_A; k++) {
                result_matrix[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result_matrix;
}

int main() {
    try {
        ifstream ifs("input.txt");
        int n, m1, m2, p;
        ifs >> n >> m1 >> m2 >> p;
        
        // Create Matrix A
        vector<vector<int>> A(n, vector<int>(m1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m1; ++j) {
                ifs >> A[i][j];
            }
        }

        // Create Matrix B
        vector<vector<int>> B(m2, vector<int>(p));
        for (int i = 0; i < m2; ++i) {
            for (int j = 0; j < p; ++j) {
                ifs >> B[i][j];
            }
        }

        // Perform matrix multiplication
        vector<vector<int>> result = crossProduct(A, B);

        // Display the result
        cout << "Result of Matrix Multiplication:" << endl;
        for (const auto& row : result) {
            for (const auto& val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
