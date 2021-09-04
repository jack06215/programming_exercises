#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class FenwickTree {
public:
    FenwickTree(int n): sums_(n + 1, 0) {}
    
    // update all branches at given index i
    // until it reaches the top of tree
    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] = sums_[i] + delta;
            // go to next branch: bin(i) + bin(LSB(i))
            i = i + lowbit(i);
        }
    }
    
    // query will return sum at i-position
    // the operation is opposite of update
    // meaning i is subtract from its LSB at each step
    // until it reaches 0 (bottom of tree)
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum = sum + sums_[i];
            // go to next branch: bin(i) - bin(LSB(i))
            i = i - lowbit(i);
        }
        return sum;
    }
private:
    vector<int> sums_;
    // extract the lowest binary bit of an integer
    static inline int lowbit(int x) {
        return x & (-x);
    }
};


class NumArray {
public:
    // std::move() to transfer ownership
    NumArray(vector<int>& nums): nums_(std::move(nums)), trees_(nums_.size()) {
        // update tree
        for (int i = 0; i < nums_.size(); i++) {
            trees_.update(i + 1, nums_[i]);
        }
    }
    
    // sum range is easy with Fenwick Tree:
    // query(j - 1) and query(j), then just take the difference
    int sumRange(int i, int j) {
        return trees_.query(j + 1) - trees_.query(i);
    }
private:
    vector<int> nums_;
    FenwickTree trees_;
};

int main() {
    std::vector<int> inputs{-2,0,3,-5,2,-1};
    NumArray arr = NumArray(inputs);

    // [1,-1,-3] 
    std::cout << arr.sumRange(0,2) << '\n';
    std::cout << arr.sumRange(2,5) << '\n';
    std::cout << arr.sumRange(0,5) << '\n';

    return 0;
}