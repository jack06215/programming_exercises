#include <vector>
#include <queue>
#include <iostream>
#include "../../prettyprint.h"

using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), ans = 0;

        auto bfs = [&](int& i) {
            vector<bool> visited(n, false);
            queue<int> q;
            int detonated = 0;

            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                detonated += 1;

                for (int j = 0; j < n; j++) {
                    if (!visited[j]) {
                        // circle equation : (x - h) ^ 2 + (y - k) ^ 2 - r ^ 2 = 0
                        // if point lie inside the circle then >= 0 else < 0. (simple elementry maths)
                        int64_t h = bombs[curr][0], k = bombs[curr][1], r = bombs[curr][2];
                        int64_t a = (bombs[j][0] - h) * (bombs[j][0] - h);
                        int64_t b = (bombs[j][1] - k) * (bombs[j][1] - k);
                        int64_t c = r * r;
                        if (a + b <= c) {   
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
            return detonated;
        };

        for (int i = 0; i < n; i++) {
            ans = max(ans, bfs(i));
        }
        return ans;
    }
};
