#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

string infix2postfix(string infix);
int eval(string postfix);

int main() {
  string infixExpression, postfixExpression;
  infixExpression = "(8-1+3)*6+5^3-((3+7)*2)";

  postfixExpression = infix2postfix(infixExpression);
  int result = eval(postfixExpression);

  cout << "Input expression : " << infixExpression << endl;
  cout << "Postfix : " << postfixExpression << endl;
  cout << "Result : " << result << endl;
  return 0;
}

// INFIX to POSTFIX conversion
string infix2postfix(string infix) {
  string postfix = "";
  stack<char> stk;
  char ch;

  for (int i = 0; infix[i]; i++) {
    // getting a character
    ch = infix[i];

    // if it is an opening bracket, push it to the stack
    if (ch == '(') stk.push(ch);

    // if it is a closing bracket, append all the inclusive literals(i.e. till
    // the next opening bracket is found)
    else if (ch == ')') {
      while (!stk.empty() && stk.top() != '(') {
        // append and pop it off
        postfix = postfix + stk.top();
        stk.pop();
      }

      // pop the corresponding opening bracket off
      if (!stk.empty() && stk.top() == '(') stk.pop();

    }

    // found operator or operand
    else {
      // pow() is highest, then mul() and div(), then add() and sub()
      auto precedence = [](char literal) {
        if (literal == '^')
          return 3;  // highest priority for exponential operator
        else if (literal == '/' || literal == '*')
          return 2;  // high priority than + or - operator
        else if (literal == '+' || literal == '-')
          return 1;  // lowest priority among operators
        else
          return 0;
      };
      int priority = precedence(ch);

      // found operand
      if (priority == 0) postfix = postfix + ch;

      // found operator
      else {
        // no need to check, just push it to the stack
        if (stk.empty())
          stk.push(ch);

        else {
          // append (and pop) lower literals
          while (!stk.empty() && stk.top() != '(' &&
                 priority <= precedence(stk.top())) {
            postfix = postfix + stk.top();
            stk.pop();
          }
          // then push the literal with highest priority
          stk.push(ch);
        }
      }
    }
  }
  // append the remainding literals
  while (!stk.empty()) {
    postfix += stk.top();
    stk.pop();
  }
  return postfix;
}

int eval(string postfix) {
  stack<int> myStack;
  char ch;
  auto eval = [](int a, int b, char operatorSign) {
    if (operatorSign == '+')
      return a + b;
    else if (operatorSign == '-')
      return a - b;
    else if (operatorSign == '*')
      return a * b;
    else if (operatorSign == '/')
      return a / b;
    else if (operatorSign == '^')
      return static_cast<int>(pow(a, b));
  };
  for (int i = 0; postfix[i]; i++) {
    ch = postfix[i];
    if (ch >= '0' && ch <= '9')  // found operand
      myStack.push(ch - '0');    // char to int conversion
    else                         // found operator
    {
      int a, b;
      b = myStack.top();
      myStack.pop();

      a = myStack.top();
      myStack.pop();

      myStack.push(eval(a, b, ch));
    }
  }

  return myStack.top();
}