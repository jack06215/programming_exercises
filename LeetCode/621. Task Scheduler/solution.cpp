#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);        
        for (const auto& task : tasks) {
            ++count[task - 'A'];
        }
        const int max_count = *max_element(count.begin(), count.end());
        size_t ans = (max_count - 1) * (n + 1);
        ans += count_if(count.begin(), count.end(), [max_count] (int c) { return c == max_count; });
        return max(tasks.size(), ans);
    }
};

int main(int argc, char const *argv[]) {
    
    return 0;
}

