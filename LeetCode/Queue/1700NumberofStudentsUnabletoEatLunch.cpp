#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue q(deque<int>(students.begin(), students.end()));
        int index = 0;
        int count = 0;
        while (!q.empty()) {
            int current = q.front(); q.pop();
            if (current != sandwiches[index]) {
                count++;
                q.push(current);
            }
            else {
                count = 0;
                index++;
            }
            if (count == q.size()) {
                break;
            }
        }
        return q.size();
    }
};
