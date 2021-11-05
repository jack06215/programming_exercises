#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        _plusOne(digits);
        return digits;
    }
private:
    void _plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        for (int i = n; i > -1; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i]++;
                return;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
    }
};