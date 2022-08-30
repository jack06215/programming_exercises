#include <iostream>
#include <vector>
#include "../prettyprint.h"

using namespace std;

vector<int> vec;

void func1(int n) {
    vec.emplace_back(n);
    if (n == 0) {
        return;
    }
    func1(n - 1);
}

void func2(int n) {
    if (n == 0) {
        return;
    }
    vec.emplace_back(n);
    func2(n - 1);
}

void func3(int n) {
    if (n == 0) {
        return;
    }
    func3(n - 1);
    vec.emplace_back(n);
}

void func4(int n) {
    vec.emplace_back(n);
    if (n == 0) {
        return;
    }
    vec.emplace_back(n);
    func4(n - 1);
    vec.emplace_back(n);
}

void func5(int n) {
    if (n == 0) {
        return;
    }
    vec.emplace_back(n % 2);
    return func5(n / 2);
}

void func6(vector<int>& inbuf, vector<int>& outbuf, int left, int right) {
    if (left >= right) {
        return;
    }
    outbuf.emplace_back(inbuf[left]);
    outbuf.emplace_back(inbuf[right]);
    return func6(inbuf, outbuf, left + 1, right - 1);
}

int main(int argc, char const* argv[]) {
    vec.clear();
    func1(5);
    cout << vec << endl;

    vec.clear();
    func2(5);
    cout << vec << endl;

    vec.clear();
    func3(5);
    cout << vec << endl;

    vec.clear();
    func4(5);
    cout << vec << endl;

    vec.clear();
    func5(10);
    cout << vec << endl;

    vector<int> nums = { 1,2,3,4,5 };
    vec.clear();
    func6(nums, vec, 0, nums.size() - 1);
    cout << nums << endl;
    cout << vec << endl;

    return 0;
}
