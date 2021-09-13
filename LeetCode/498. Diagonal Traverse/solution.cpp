#include <vector>
#include <iostream>
#include <map>

#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        map<int, vector<int>> mp;
        
        for(int i = 0 ; i < matrix.size() ; i++) 
            for(int j = 0 ; j < matrix[0].size() ; j++)
                mp[i + j].push_back(matrix[i][j]);
        std::cout << mp << std::endl;
        for(auto i: mp) {
            if((i.first) % 2 == 0) 
                reverse(i.second.begin(), i.second.end()); 
            
            for(auto k: i.second) {
                res.push_back(k);
            }
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    auto arr = read2DVectorFromString("[[1,2,3],[4,5,6],[7,8,9]]");
    std::cout << s.findDiagonalOrder(arr) << std::endl;

    return 0;
}