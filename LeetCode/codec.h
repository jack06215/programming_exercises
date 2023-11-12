#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

template<typename T> void _R(T &x) { cin >> x; }

// template <class T>
// inline void hash_combine(std::size_t & seed, const T & v) {
//     std::hash<T> hasher;
//     seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
// }

// template<typename S, typename T> struct pair_hash<std::pair<S, T>> {
//     inline std::size_t operator()(const std::pair<S, T> & v) const {
//          std::size_t seed = 0;
//          hash_combine(seed, v.first);
//          hash_combine(seed, v.second);
//          return seed;
//     }
// };

// struct Hash {
//     size_t operator()(const vec2d& x) const {
//         return hash<long long>()(((long long)x.first)^(((long long)x.second) << 32));
//     }
// };

// template <class T> struct MyHash;
// template<> struct MyHash<std::string> {
//     std::size_t operator()(std::string const& s) const noexcept
//     {
//         size_t seed = static_cast<size_t>(0xdeadbeef);
//         return MurmurHash2 ( s.data(), s.length(), seed );
//     }
// };

template<typename T>
string vectorToString(vector<T> v){
	auto i = v.begin();
	ostringstream ans;
    ans << "[";
	for(; i != v.end(); ++i) {
		ans << *i;
		if (i + 1 != v.end()) {
            ans << ",";
        }
	}
	ans << "]";
	return ans.str();
}

vector<string> stringToVector(string str) {
	str = str.substr(1, str.size() - 2);
	istringstream ss(str);
	string token;
	vector<string> ans;
	while (getline(ss, token, ',')) {
        ans.push_back(token);
    }
	return ans;
}

vector<int> stringToIntVector(string str) {
	str = str.substr(1, str.size() - 2);
	istringstream ss(str);
	string token;
	vector<int> ans;
	while (getline(ss, token, ',')) {
        ans.push_back(stoi(token));
    }
	return ans;
}

vector<double> stringToDoubleVector(string str) {
	str = str.substr(1, str.size() - 2);
	istringstream ss(str);
	string token;
	vector<double> ans;
	while (getline(ss, token, ',')) {
        ans.push_back(stod(token));
    }
	return ans;
}

vector<int> toIntVector(vector<string> v) {
	vector<int> ans(v.size(), 0);
	for (int i = 0; i < v.size(); ++i) {
        ans[i] = stoi(v[i]);
    }
	return ans;
}

template<typename T>
void printVector(vector<vector<T>> v){
    cout << "[" << endl;
    for (int i = 0; i < v.size(); ++i) {
        auto &row = v[i];
        cout << "[";
        for (int j = 0; j < row.size(); ++j) {
            auto &val = row[j];
            cout << val;
            if (j < row.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < v.size() - 1) {
            cout << ", ";
        }
        cout << endl;
    }
    cout << "]" << endl;
}

vector<vector<int>> read2DVector() {
    vector<vector<int>> ans;
	int i = 0;
    cin.get(); // outer [
    while (cin.peek() != ']') {
        cin.get(); // inner [
        if (ans.size() <= i) ans.emplace_back();
        int k = 0;
        while (cin.peek() != ']') {
            int n;
            cin >> n;
            ans[i].push_back(n);
            if (cin.peek() == ',') {
                cin.get();
            }
        }
        cin.get(); // inner ]
        if (cin.peek() == ',') {
            cin.get();
        }
        ++i;
    }
    cin.get(); // outer ]
    return ans;
}

vector<vector<int>> read2DVectorFromString(string str_vector) {
    istringstream oss(str_vector);
    cin.rdbuf(oss.rdbuf());

    vector<vector<int>> ans;
	int i = 0;
    cin.get(); // outer [
    while (cin.peek() != ']') {
        cin.get(); // inner [
        if (ans.size() <= i) {
            ans.emplace_back();
        }
        int k = 0;
        while (cin.peek() != ']') {
            int n;
            cin >> n;
            ans[i].push_back(n);
            if (cin.peek() == ',') {
                cin.get();
            }
        }
        cin.get(); // inner ]
        if (cin.peek() == ',') {
            cin.get();
        }
        ++i;
    }
    cin.get(); // outer ]
    return ans;
}
