#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Solution {
private:
    string trimWhitespaces(const string& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j && s[i] == ' ') {
            i++;
        }
        while (j >= i && s[j] == ' ') {
            j--;
        }
        return s.substr(i, j - i + 1);
    }
    string trimWhitespaces2(const string& s) {
        auto start = s.begin();
        auto end = s.end();
        while (start != s.end() && isspace(*start)) {
            start++;
        }
        while (distance(start, end) > 0 && isspace(*(end - 1))) {
            end--;
        }
        return string(start, end);
    }

    string trimWhitespaces3(const string& str) {
        const auto i = str.find_first_not_of(' ');
        if (i == string::npos) {
            return "";
        }

        const auto j = str.find_last_not_of(' ');
        return str.substr(i, j - i + 1);
    }
public:
    string reverseWords(string s) {
        // trim the input string to remove leading and trailing spaces
        s = trimWhitespaces3(s);

        // Split the trimmed string into words based on spaces
        vector<string> words;                // Create a vector to store words
        stringstream ss(s);                  // Create a stringstream with the trimmed string
        string word;
        while (ss >> word) {                 // Tokenize the string into words
            words.push_back(word);           // Store each word in the vector
        }

        // Initialize the output string
        string out = "";

        // Iterate through the words in reverse order
        for (int i = words.size() - 1; i > 0; i--) {
            // Append the current word and a space to the output
            out += words[i] + " ";
        }

        // Append the first word to the output (without trailing space)
        return out + words[0];               // Concatenate the reversed words
    }
};
