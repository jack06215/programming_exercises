#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;
using mat2d = std::vector<std::vector<int>>;

class Solution {
public:
    int fib(int n) {
        mat2d F = { { 1, 1 }, { 1, 0 } };
        if (n == 0)
            return 0;
         
        int result = fib_i_term(F, n - 1);
        return result;
    }
    
    mat2d multiply(const mat2d& A, const mat2d& B) {
        mat2d C(A.size(), std::vector<int> (B[0].size(), 0));
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                for (int k = 0; k < A[0].size(); k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }
    
    mat2d expo(const mat2d& M, uint32_t n) {
        if (n < 1) {
            throw;
        }
        if (n == 1) {
            return M;
        }
        return multiply(M, expo(M, n - 1));
    }

    int fib_i_term(mat2d &M, uint32_t n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        mat2d A = { { 1, 1 }, { 1, 0 } };
        mat2d F = expo(M, n / 2);
        F = multiply(F, F);
        if (n % 2 != 0) {
            F = multiply(F, A);
        }
        return F[0][0];
    }
};

int main() {
    Solution s;
    cout << s.fib(32) << endl;
    return 0;
}