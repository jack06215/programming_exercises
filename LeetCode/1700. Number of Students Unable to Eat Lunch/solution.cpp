#include <vector>
#include <queue>

using namespace std;


/*
    Count students' preference of food to count
    Now we iterate the food one by one,
    and see if any one in the left students queue will take it.

    We stop at sandwiches[k] if no one wants it,
    then n - k students are unable to eat.
*/
class Solution2 {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count(2, 0);
        int n = students.size();
        int k = 0;
        for (const auto& s : students) count[s]++;
        while (k < n && count[sandwiches[k]] > 0) {
            count[sandwiches[k++]]--; // k++ perform after count get decremented
        }
        
        // for (; k < n && count[sandwiches[k]] > 0; ++k)
        //     count[sandwiches[k]]--;
        return n - k;
    }
};

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue q(std::deque<int>(students.begin(), students.end()));
        int index = 0;
        int count = 0;
        while(!q.empty()){
            int current = q.front(); q.pop();
            if(current != sandwiches[index]) {
                count++;
                q.push(current);
            }
            else {
                count= 0;
                index++;
            }
            if(count == q.size()) break;
        }
        return q.size();
    }
};
