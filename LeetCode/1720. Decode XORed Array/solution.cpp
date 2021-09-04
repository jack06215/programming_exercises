#include <vector>
#include <iostream>
#include "../prettyprint.h"

/*       
    Given:
            encoded[i] = arr[i] ^ arr[i + 1]
    
            encoded[i] ^ arr[i] = arr[i] ^ arr[i] ^ arr[i + 1]
            encoded[i] ^ arr[i] = [0] ^ arr[i + 1]
    Finally we get:
            encoded[i] ^ arr[i] = arr[i + 1]
*/

class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded, int first) {
        const int size = encoded.size() + 1;
        std::vector<int> arr(size);
        arr[0] = first;

        for (int i = 1; i < size; ++i) {
            arr[i] = arr[i - 1] ^ encoded[i - 1];
        }   
        return arr;
    }
};

int main() {
    Solution s = Solution();
    std::vector<int> encoded;
    int first;
    
    encoded = {1,2,3};
    first = 1;
    std::cout << s.decode(encoded, first) << std::endl;

    encoded = {6,2,7,3};
    first = 4;
    std::cout << s.decode(encoded, first) << std::endl;

    return 0;
}