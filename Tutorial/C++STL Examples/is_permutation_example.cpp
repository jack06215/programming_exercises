#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[5] = { 9, 3, 1, 7, 5 };
    int b[5] = { 1, 3, 5, 7, 9 };

    //判斷陣列 b 是否為陣列 a 排序後的結果
    cout << is_permutation(a, a + 5, b) << "\n";

    cout << "產生下一組排列" << "\n";
    string s = "bca";
    sort(s.begin(), s.end());
    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    cout << "產生上一組排列" << "\n";
    s = "bca";
    sort(s.begin(), s.end(), greater<char>());
    do {
        cout << s << "\n";
    } while (prev_permutation(s.begin(), s.end()));
}