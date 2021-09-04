#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> // priority_queue

// class Solution {
// public:
//     int maximumScore(int a, int b, int c) {
//         std::vector<int> piles{a, b, c};
//         std::sort(piles.begin(), piles.end());
//         int result = 0;
//         int x = piles[0];
//         int y = piles[1];
//         int z = piles[2];
//         while (x > 0 && y > 0 && x + y > z) {
//             x--;
//             y--;
//             result++;
//         }
//         result += x + y;
//         return result;
//     }
// };


// /*
//     ensure a > b > c. Then just pick from a and b and repeat the process resursively
// */
// class Solution {
// public:
//     int maximumScore(int a, int b, int c) {
//         if (a < b) {
//             return maximumScore(b, c, a);
//         }
//         if (b < c) {
//             return maximumScore(a, c, b);
//         }
//         if (b == 0) {
//             return 0;
//         }
//         int count = std::max(1, b - c);
//         return count + maximumScore(a - count, b - count, c);
//     }
// };

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        std::priority_queue<int> queue;
        queue.push(a);
        queue.push(b);
        queue.push(c);
        int result = 0;

        while (queue.size() >= 2) {
            // grab two piles
            int x = queue.top(); 
            queue.pop();
            int y = queue.top(); 
            queue.pop();

            // update state
            result++;
            x--;
            y--;

            // push new piles back again
            if (x) queue.push(x);
            if (y) queue.push(y);
        }
        return result;
    }
};

int main () {
    Solution s = Solution();
    std::cout << s.maximumScore(2, 4, 6) << std::endl;
    std::cout << s.maximumScore(4, 4, 6) << std::endl;
    std::cout << s.maximumScore(1, 8, 8) << std::endl;
    std::cout << s.maximumScore(100, 1000, 10000) << std::endl;
    return 0;
}