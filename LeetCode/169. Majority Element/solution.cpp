#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    virtual int majorityElement (vector<int>& nums) = 0;
};

class SolutionHashTable: public Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq_count;
        for (const int& val: nums) {
            freq_count[val]++;
        }
        auto most_freq = std::max_element(
            freq_count.begin(), freq_count.end(),
            [](const auto& x, const auto& y){ return x.second < y.second; });
        return most_freq->first;
    }
};

class SolutionSort: public Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

class SolutionPartialSort: public Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    }
};

class SolutionDivideAndConquer: public Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size() - 1);
    }
private:
    int majorityElement(const vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        const int m = l + (r - l) / 2;
        const int ml = majorityElement(nums, l, m);
        const int mr = majorityElement(nums, m + 1, r);
        if (ml == mr) {
            return ml;
        }
        return count(nums.begin() + l, nums.begin() + r + 1, ml) >
               count(nums.begin() + l, nums.begin() + r + 1, mr)
               ? ml : mr;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size() - 1).first;
    }
private:
    // number, freq
    pair<int, int> majorityElement(const vector<int>& nums, int l, int r) {
        // freq is 1 because left and right are pointing at the same position
        if (l == r) {
            return {nums[l], 1};
        }
        
        // divide problem into smaller chunks
        int mid = l + (r - l) / 2;
        auto ml = majorityElement(nums, l, mid);
        auto mr = majorityElement(nums, mid + 1, r);
        
        // if left and right are the same, the freq is the sum of two sides
        if (ml.first == mr.first) {
            return { ml.first, ml.second + mr.second };
        }
        // LHS has greater freq
        // count the freq on the RHS where value is ml.second
        if (ml.second > mr.second) {
            return { ml.first, ml.second + count(nums.begin() + mid + 1, nums.begin() + r + 1, ml.first) };
        }
        // RHS has greater freq
        else {
            return { mr.first, mr.second + count(nums.begin() + l, nums.begin() + mid + 1, mr.first) };
        }
    }
};

int main(void) {
    Solution *s;
    // s = new SolutionHashTable();
    // s = new SolutionSort();
    // s = new SolutionPartialSort();
    s = new SolutionDivideAndConquer();

    vector<int> input = { 3, 2, 3 };
    cout << s->majorityElement(input) << endl;

    return 0;
}
