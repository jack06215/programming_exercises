#include <iostream>
#include <vector>
#include <utility> // std::move
#include <cstddef> // std::size_t

class FenwickTree {
public:
    FenwickTree(int n): sums_(n + 1, 0) {}

    void update(int i, int delta){
        /*
            for(; i>0; i-= i&(-i))
            ans += bit[i];
        */
        while (i < sums_.size()) {
            sums_[i] = sums_[i] + delta;
            i = i + lowbit(i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum = sum + sums_[i];
            i = i - lowbit(i);
        }
        return sum;
    }

private:
    static inline int lowbit(int x) {
        return x & (-x);
    }
    std::vector<int> sums_;
};

class NumArray {
public:
    NumArray(std::vector<int> nums): nums_(std::move(nums)), trees_(nums_.size()) {
        for (int i = 0; i < nums_.size(); ++i) {
            trees_.update(i + 1, nums_[i]);
        }
    }

    int sumRange(int start, int end) {
        return trees_.query(end + 1) - trees_.query(start);
    }

    // update an element requires update the tree!
    void update(int i, int val) {
        trees_.update(i + 1, val - nums_[i]);
        nums_[i] = val;
    }
private:
    std::vector<int> nums_;
    FenwickTree trees_;
};


int main() {
    std::vector<int> inputs{50,15,10,67,65,88,77,84};
    NumArray arr = NumArray(inputs);
    int i,j;
    
    // sum of partial array from i to j
    i = 1;
    j = 5;
    std::cout << arr.sumRange(i-1, j-1) << '\n';

    // // update
    // i = 5;
    // arr.update(i-1, 10);

    // // sum of partial array from i to j
    // i = 1;
    // j = 5;
    // std::cout << arr.sumRange(i-1, j-1) << '\n';
}