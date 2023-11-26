#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int lengthLongestPath(const string& input) {
  istringstream ss(input);
  string token;
  stack<int> pathLengths;
  int maxLen = 0, currentLen = 0;

  while (getline(ss, token, '\n')) {
    int depth = token.find_last_of('\t') + 1; // depth of current file/dir

    // If depth is smaller than stack size, pop from stack
    while (pathLengths.size() > depth) {
      currentLen -= pathLengths.top();
      pathLengths.pop();
    }

    int len = token.length() - depth; // actual length of the file/dir name
    currentLen += len + 1; // +1 for the '/' in the path

    if (token.find('.') != string::npos) {
      // It's a file, update maxLen if this path is longer
      maxLen = max(maxLen, currentLen - 1); // -1 to remove extra '/'
    }

    pathLengths.push(len + 1); // +1 for the '/' in the path
  }

  return maxLen;
}

int main() {
  string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
  cout << "Length of the longest path: " << lengthLongestPath(input) << endl;
  return 0;
}
