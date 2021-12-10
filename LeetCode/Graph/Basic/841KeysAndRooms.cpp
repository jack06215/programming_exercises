#include <vector>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <list>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited = { 0 };
        dfs(0, rooms, visited);
        return rooms.size() == visited.size();
    }

    void dfs(int node, vector<vector<int>>& edges, unordered_set<int>& visited) {
        for (auto next : edges[node]) {
            if (visited.count(next) == 0) {
                visited.insert(next);
                dfs(next, edges, visited);
            }
        }
    }
};

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> dfs;
        unordered_set<int> visited;

        dfs.push(0);
        visited.insert(0);

        while (!dfs.empty()) {
            auto next = dfs.top();
            dfs.pop();
            for (int i = 0; i < rooms[next].size(); i++) {
                if (visited.count(rooms[next][i]) == 0) {
                    dfs.push(rooms[next][i]);
                    visited.insert(rooms[next][i]);
                    if (rooms.size() == visited.size()) {
                        return true;
                    }
                }
            }
        }
        return rooms.size() == visited.size();
    }
};

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        list<int> bfs;
        unordered_set<int> visited;

        bfs.push_back(0);
        visited.insert(0);

        while (!bfs.empty()) {
            auto next = bfs.front();
            bfs.pop_front();
            for (int i = 0; i < rooms[next].size(); i++) {
                int node = rooms[next][i];
                if (visited.count(node) == 0) {
                    bfs.push_back(node);
                    visited.insert(node);
                    if (rooms.size() == visited.size()) {
                        return true;
                    }
                }
            }
        }
        return rooms.size() == visited.size();
    }
};
