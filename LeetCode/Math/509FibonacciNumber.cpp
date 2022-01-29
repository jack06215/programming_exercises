#include <vector>

using namespace std;

class Solution {
public:
    using mat2d = vector<vector<int>>;
    int fib(int n) {
        if (n == 1) {
            return 1;
        }
        mat2d F = { { 1, 1 }, { 1, 0 } };
        if (n == 0) {
            return 0;
        }
        mat2d result = expo(F, n - 1);
        return result[0][0];
    }

private:
    mat2d multiply(const mat2d& A, const mat2d& B) {
        mat2d C(A.size(), vector<int>(B[0].size(), 0));
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                for (int k = 0; k < A[0].size(); k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }
    mat2d expo(mat2d const& M, uint32_t n) {
        if (n < 1) {
            throw;
        }
        if (n == 1) {
            return M;
        }
        return multiply(M, expo(M, n - 1));
    }
};
