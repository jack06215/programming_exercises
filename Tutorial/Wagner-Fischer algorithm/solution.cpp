#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class edit_distance {
public:
  string word;
  int distance;
};

vector<string> load_dictionary(const string& file_path) {
  vector<string> dictionary;
  ifstream file(file_path);
  string line;

  if (!file.is_open()) {
    cerr << "Failed to open the file" << endl;
    return dictionary;
  }

  while (getline(file, line)) {
    dictionary.push_back(line);
  }

  file.close();
  return dictionary;
}

int wagner_fischer(const string& s1, const string& s2) {
  int len_s1 = s1.length();
  int len_s2 = s2.length();

  vector<int> current_row(len_s1 + 1);

  // Initialize the current row
  for (int i = 0; i <= len_s1; ++i) {
    current_row[i] = i;
  }

  for (int i = 1; i <= len_s2; ++i) {
    vector<int> previous_row = current_row;
    current_row[0] = i;
    for (int j = 1; j <= len_s1; ++j) {
      int add = previous_row[j] + 1;
      int del = current_row[j - 1] + 1;
      int change = previous_row[j - 1];
      if (s1[j - 1] != s2[i - 1]) {
        change += 1;
      }
      current_row[j] = min({ add, del, change });
    }
  }
  return current_row[len_s1];
}

vector<edit_distance> spell_check(const string& word, const vector<string>& dictionary) {
  vector<edit_distance> suggestions;

  for (const auto& correct_word : dictionary) {
    int distance = wagner_fischer(word, correct_word);
    suggestions.push_back({ correct_word, distance });
  }

  // Sort suggestions based on the distance
  sort(suggestions.begin(), suggestions.end(),
    [](const edit_distance& a, const edit_distance& b) {
      return a.distance < b.distance;
    }
  );

  if (suggestions.size() > 10) {
    suggestions.resize(10);
  }

  return suggestions;
}

int main() {
  vector<string> dictionary = load_dictionary("words.txt");
  string misspelled_word = "wrlod";
  auto suggestions = spell_check(misspelled_word, dictionary);

  cout << "Top 10 suggestions for '" << misspelled_word << "':" << endl;
  for (const auto& [word, distance] : suggestions) {
    cout << word << " (Distance: " << distance << ")" << endl;
  }

  return 0;
}
