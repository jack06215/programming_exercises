#include <vector>
#include <iostream>
#include "../prettyprint.h"

/*       

*/

class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded) {
        const int n = encoded.size() + 1;
        std::vector<int> perm(n);
        for (int i = 1; i <= n; ++i) {
            perm[0] ^= i;
        }
        for (int i = 1; i < n; i += 2) {
            perm[0] ^= encoded[i];
        }
        for (int i = 1; i < n; ++i) {
            perm[i] = perm[i - 1] ^ encoded[i - 1];
        }
        return perm; 
    }
};

int main() {
    Solution s = Solution();
    std::vector<int> encoded;
    
    encoded = {3,1};
    std::cout << s.decode(encoded) << std::endl;

    encoded = {6,5,4,6};
    std::cout << s.decode(encoded) << std::endl;

    return 0;
}