#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> cities;

void read() {
    cin >> n >> k;
    cities.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }
}

bool is_feasible(int distance) {
    int curr_loc = cities[0];  // "starting point" city
    int index = 1;             // begin from cities[1]
    int upgrade = -1;          // "upgrade cities[index]", initially -1 for none.
    int count = 0;             // "number of upgrade" counter
    while (index < n) {
        /* 
            (1) Search the next city to upgrade form some "starting point" city
                - Cover as many cities as possible within the distance of X unit 
        */
        if(upgrade == -1 && cities[index] - curr_loc > distance) {
            // [index - 1] as [index] has already exceeded the distance
            upgrade = cities[index - 1];
            // upgrade count + 1
            count++;
            // go back 1 step
            index--;
        }
        /* 
            (2) Search the next "starting point" city
                - It should be the first city where distance is longer than X unit
        */
        else if (upgrade != -1 && cities[index] - upgrade > distance) {
            // the new "starting point" city
            curr_loc = cities[index];
            // reset upgrade index
            upgrade = -1;
        }
        index++;
    }
    // corner case where only 1 update can cover rest of the cities
    if (upgrade == -1) {
        count++;
    }

    // does it satisfy the constraint?
    return count <= k;
}

void solve() {
    int left = 0;
    int right = static_cast<int>(1e9);
    sort(cities.begin(), cities.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (is_feasible(mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}

int main() {
    read();
    solve();
    return 0;
}
