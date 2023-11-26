#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(const string& s) {
  stack<char> brackets;

  for (char ch : s) {
    switch (ch) {
    case '(':
    case '[':
    case '{':
      brackets.push(ch);
      break;
    case ')':
      if (brackets.empty() || brackets.top() != '(') return false;
      brackets.pop();
      break;
    case ']':
      if (brackets.empty() || brackets.top() != '[') return false;
      brackets.pop();
      break;
    case '}':
      if (brackets.empty() || brackets.top() != '{') return false;
      brackets.pop();
      break;
    default:
      // Ignore other characters
      break;
    }
  }

  return brackets.empty();
}

int main() {
  cout << boolalpha; // print bools as true/false
  cout << "([])[]({}): " << isBalanced("([])[]({})") << endl;
  cout << "([)]: " << isBalanced("([)]") << endl;
  cout << "(((): " << isBalanced("((()") << endl;

  return 0;
}
