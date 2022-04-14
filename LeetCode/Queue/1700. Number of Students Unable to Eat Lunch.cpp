#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue que(deque<int>(students.begin(), students.end()));
        int index = 0;
        int count = 0;
        while (!que.empty()) {
            int current = que.front(); que.pop();
            if (current != sandwiches[index]) {
                que.push(current);
                count++;
            }
            else {
                count = 0;
                index++;
            }

            if (count == que.size()) {
                break;
            }
        }
        return que.size();
    }
};