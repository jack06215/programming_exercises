#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
#include "../prettyprint.h"

using namespace std;
using minpq = priority_queue<int, vector<int>, greater<int>>;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // all elements on same diagonal have same i - j result.
        unordered_map<int, minpq> map; // min priority queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[i - j].push(mat[i][j]);
                std::cout << (i - j) << " ";
            }
            std::cout << std::endl;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = map[i - j].top(); map[i - j].pop();
            }
        }
        return mat;
    }
};

int main(){
    Solution s = Solution();
    std::vector<std::vector<int>> input_seq{{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    std::cout << s.diagonalSort(input_seq) << std::endl;
    return 0;
}
