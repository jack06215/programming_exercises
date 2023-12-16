#include <queue>

using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> queue;
        queue.push(a);
        queue.push(b);
        queue.push(c);

        int result = 0;
        while (queue.size() >= 2) {
            // grab two piles
            int x = queue.top(); queue.pop();
            int y = queue.top(); queue.pop();

            // update state
            result++;
            x--;
            y--;

            // push new piles back again
            if (x) {
                queue.push(x);
            }
            if (y) {
                queue.push(y);
            }
        }
        return result;
    }
};