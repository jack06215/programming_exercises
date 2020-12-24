#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = nums[0] == 1 ? 1: 0;
    int max_count = count;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == 1) {
            count++;
            max_count = max(max_count, count);
        }
        else {
            count = 0;
        }
    }
    return max_count;
}

int main(void) {
    vector<int> my_list{1,1,0,1,1,1};
    std::cout << findMaxConsecutiveOnes(my_list) << std::endl;
    return 0;
}