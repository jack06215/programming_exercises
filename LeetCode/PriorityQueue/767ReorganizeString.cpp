#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> pq;
        string result;

        for (const auto& ch : s) {
            freq[ch]++;
        }
        for (const auto& f : freq) {
            pq.push({ f.second, f.first });
        }

        while (pq.size() > 1) {
            auto [count1, letter1] = pq.top(); pq.pop();
            auto [count2, letter2] = pq.top(); pq.pop();

            result += letter1;
            result += letter2;

            count1--;
            count2--;

            if (count1 > 0) {
                pq.push({ count1, letter1 });
            }
            if (count2 > 0) {
                pq.push({ count2, letter2 });
            }
        }

        if (!pq.empty()) {
            if (pq.top().first > 1) {
                return "";
            }
            else {
                result += pq.top().second;
            }
        }
        return result;
    }
};