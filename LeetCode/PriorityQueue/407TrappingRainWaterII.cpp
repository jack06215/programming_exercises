#include <vector>
#include <queue>
#include <iostream>
#include "../prettyprint.h"

using namespace std;
/*
    The approach here is that we start from the outermost boundary
    and go on shrinking it from the current weakest link (minimum height).

    This weakest link concept can be implemented using a minimum heap priority queue,
    in which we push the boundary heights and get the minimum each time.

    We get the trapped water when we find a building with height smaller than the current weakest link,
    the reason is that when even the weakest link in the boundary is not allowing the water to pass through it,
    then the water stays. The units of water is the difference in heights of the current weakest link
    and the other smaller height visited just now.
*/
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<Height> minHeap;
        Height top;

        int m = heightMap.size();
        int n = heightMap.size() == 0 ? 0 : heightMap[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        int water = 0;

        // Pushes column boundary in min heap
        for (int i = 0; i < n; i++) {
            minHeap.push(Height(heightMap[0][i], 0, i));
            visited[0][i] = 1;

            minHeap.push(Height(heightMap[m - 1][i], m - 1, i));
            visited[m - 1][i] = 1;
        }

        // Pushes row boundary in min heap
        for (int j = 1; j < m - 1; j++) {
            minHeap.push(Height(heightMap[j][0], j, 0));
            visited[j][0] = 1;

            minHeap.push(Height(heightMap[j][n - 1], j, n - 1));
            visited[j][n - 1] = 1;
        }

        while (!minHeap.empty()) {
            top = minHeap.top();
            minHeap.pop();

            int x = top.position.x, y = top.position.y;
            int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

            // Checks the directions - top, bottom, right, left for unvisited elements
            for (int p = 0; p < 4; p++) {
                int row = x + directions[p][0];
                int col = y + directions[p][1];

                // If a valid unvisited element is found
                if (row >= 0 && row < m && col >= 0 && col < n && !visited[row][col]) {
                    Height next(heightMap[row][col], row, col);

                    // If water can be trapped (when height of this new element is less than the current weakest link) 
                    if (next.h < top.h) {
                        water += top.h - next.h;
                        next.h = max(next.h, top.h);
                    }

                    // Shrinks the boundary by pushing the new element
                    minHeap.push(next);
                    visited[row][col] = 1;
                }
            }
        }

        return water;
    }
private:
    struct Position {
        int x;
        int y;
        Position(int a = 0, int b = 0) : x(a), y(b) {}
    };

    // The height and its position in one place
    struct Height {
        int h;
        Position position;
        Height(int p = -1, int a = -1, int b = -1) : h(p), position(a, b) {}
        bool operator<(const Height& h1) const {
            return h > h1.h;
        }
    };
};