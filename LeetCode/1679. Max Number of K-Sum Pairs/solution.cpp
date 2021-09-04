#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> m;
		int ans = 0;
		for(int i = 0; i < nums.size(); i++){
			if(m[k - nums[i]] > 0){
			   m[k - nums[i]]--;
				ans++;
			}
			else{
				m[nums[i]]++;
			}
		}
		return ans;
    }
};

int main() {
    Solution s = Solution();
    std::vector<int> input_seq{1,2,3,4};
    int k = 5;
    std::cout << s.maxOperations(input_seq, k) << std::endl;

    return 0;
}
