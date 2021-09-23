#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) {
            return {{1}};
        }
        
        // reserve just enough space to create triangle
        result.reserve(numRows);
        
        // base case
        result.push_back({1});
        result.push_back({1, 1});
        
        // 
        for (int i = 2; i < numRows; ++i) {
            make_new_row(i);
            result.push_back(new_row);
        }
        return result;
    }
private:
    void make_new_row(int row) {
        // flush array before creating a new one
        new_row.clear();
        
        // 1st element is always 1
        new_row.push_back(1);
        
        // get previous row
        vector<int> prev_row = result[row - 1];
        
        // starting from index 1, we add up two numbers
        for(int i = 1 ; i < row ; ++i){
            int current = prev_row[i - 1] + prev_row[i];
            new_row.push_back(current);
        }
        
        // last element is always 1
        new_row.push_back(1);
        return;
    }
    
private:
    vector<vector<int>> result;
    vector<int> new_row;
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.generate(10) << endl;
    return 0;
}
