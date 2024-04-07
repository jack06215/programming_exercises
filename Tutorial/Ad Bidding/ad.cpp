#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Structure for DSP ad information
class ad_info {
public:
  char id;
  int bid_price;
  int fcap;
  int limit;
  bool has_quota() {
    return this->limit > this->shown_count;
  }
  void inc_shown_count() {
    this->shown_count++;
  }
private:
  int shown_count = 0; // Count of how many times the ad has been shown in total
};

// User's properties
class props {
public:
  int inc_ad_seen_count(char ad_id) {
    return this->ad_impressions[ad_id]++;
  }
  int get_ad_seen_count(char ad_id) {
    return this->ad_impressions[ad_id];
  }
private:
  // Structure for user impressions on specific ads to manage frequency cap
  // Key: adID, Value: times shown to this user
  unordered_map<char, int> ad_impressions;
};

class Solution {
public:
  Solution() {
    cin >> n >> m;
  }

  void solve() {
    while (n && m) {
      ads.resize(n);
      requests.resize(m);
      // Input for ads
      for (int i = 0; i < n; ++i) {
        cin >> ads[i].id >> ads[i].bid_price >> ads[i].fcap >> ads[i].limit;
      }

      // Input for requests
      for (int j = 0; j < m; ++j) {
        cin >> requests[j].first >> requests[j].second;
      }

      // Process each request
      string result;
      for (const auto& req : requests) {
        char user_id = req.first;
        int min_bid_price = req.second;

        char best_ad = '_';
        int highest_bid = 0;

        for (auto& ad : ads) {
          int seen_count = users[user_id].get_ad_seen_count(ad.id);
          // Check if this ad can bid: meets price, under user's fcap, and under ad's limit
          if (
            (ad.bid_price >= min_bid_price) &&
            (seen_count < ad.fcap) &&
            (ad.has_quota())
            ) {
            if (ad.bid_price > highest_bid) {
              highest_bid = ad.bid_price;
              best_ad = ad.id;
            }
          }
        }

        // If an ad was selected, update the impressions
        if (best_ad != '_') {
          users[user_id].inc_ad_seen_count(best_ad);
          for (auto& ad : ads) {
            if (ad.id == best_ad) {
              ad.inc_shown_count();
              break;
            }
          }
        }
        result.push_back(best_ad);
      }
      cout << result << endl;
      cin >> n >> m;
      clear();
    }
  }
private:
  int n, m;
  vector<ad_info> ads;
  unordered_map<char, props> users; // Key: userID
  vector<pair<char, int>> requests; // Pair: userID, minBidPrice

  void clear() {
    ads.clear();
    requests.clear();
    users.clear();
  }
};

int main() {
  auto s = Solution();
  s.solve();
  return 0;
}
