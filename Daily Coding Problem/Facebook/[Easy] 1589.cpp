#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#include <vector>

int minQuxesRemaining(const vector<char>& quxes) {
    unordered_map<char, int> counts;
    for (char c : quxes) {
        counts[c]++;
    }

    if (counts['R'] == quxes.size() ||
        counts['G'] == quxes.size() ||
        counts['B'] == quxes.size()) {
        return quxes.size();
    }

    if (counts['R'] % 2 == counts['G'] % 2 && counts['R'] % 2 == counts['B'] % 2) {
        return 2;
    }

    return 1;
}


int main() {
    vector<char> quxes = { 'R', 'R', 'R', 'R', 'R' };
    cout << minQuxesRemaining(quxes) << endl;
    return 0;
}
