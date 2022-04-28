#include <iostream>
#include <vector>
#include "../prettyprint.h"

using namespace std;

void backtrack_not_good(int n, vector<int>& nums) {
    cout << nums << endl;
    if (n >= 2) {
        return;
    }
    vector<int> new_nums = { 1 };
    move(nums.begin(), nums.end(), back_inserter(new_nums));
    backtrack_not_good(n + 1, new_nums);
}

void combinations(int n, vector<int>& nums, vector<vector<int>>& ans) {
    if (n >= 3) {
        cout << nums << endl;
        ans.push_back(nums);
        return;
    }
    for (int i = 1; i < 4; i++) {
        nums.push_back(i);
        combinations(n + 1, nums, ans);
        nums.pop_back();
    }
}

void recursion(int n) {
    if (n >= 5) {
        return;
    }
    cout << n << endl;
    recursion(n + 1);
    cout << n << endl;
}

void backtrack(int n, vector<int>& nums) {
    cout << nums << endl;
    if (n >= 4) {
        return;
    }
    nums.push_back(n);
    backtrack(n + 1, nums);
    nums.pop_back();
}

void backtrack_with_loop(int n, vector<int>& nums) {
    cout << nums << endl;
    if (n >= 2) {
        return;
    }
    for (int i = 1; i < 3; i++) {
        nums.push_back(i);
        backtrack_with_loop(n + 1, nums);
        nums.pop_back();
    }
}

int main() {
    vector<int> vec;
    vector<vector<int>> res;
    // combs(0, vec, res);
    backtrack_with_loop(0, vec);
    // recursion(0);
    return 0;
}