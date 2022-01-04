#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count(2, 0);
        int n = students.size();
        int k = 0;
        for (const auto& s : students) {
            count[s]++;
        }
        while (k < n && count[sandwiches[k]] > 0) {
            count[sandwiches[k++]]--; // k++ perform after count get decremented
        }
        return n - k;
    }
};