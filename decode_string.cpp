#include <iostream>
#include <stack>
#include <string>

/*

Input : str[] = "1[b]"
Output : b

Input : str[] = "2[ab]"
Output : abab

Input : str[] = "2[a2[b]]"
Output : abbabb

Input : str[] = "3[b2[ca]]"
Output : bcacabcacabcaca

*/

std::string string_decode(const std::string& in_str)
{
    std::stack<int> int_stack;
    std::stack<char> char_stack;
    std::string result{""};
    std::string temp_str{""};
    int in_str_size = in_str.size();
    
    for (int i = 0; i < in_str_size; i++)
    {
        int count = 0;
        // if a number is found, convert to int and push to int_stack
        if (in_str[i] >= '0' && in_str[i] <= '9')
        {
            for (; in_str[i] >= '0' && in_str[i] <= '9'; i++)
                count = count * 10 + in_str[i] - '0'; 
            
            i--;
            int_stack.push(count);
        }
        // if '[' is found, push it to char_stack
        else if (in_str[i] == '[')
        {
            if (in_str[i - 1] >= '0' && in_str[i - 1] <= '9')
                char_stack.push(in_str[i]);
            
            else
            {
                int_stack.push(1);
                char_stack.push(in_str[i]);
            }
            
        }
        // if ']' is found, pop elements till '[' is found
        else if (in_str[i] == ']')
        {
            count = 0;
            temp_str = "";
            if (!int_stack.empty())
            {
                count = int_stack.top();
                int_stack.pop();
            }

            while (char_stack.top() != '[' && !char_stack.empty())
            {
                temp_str = char_stack.top() + temp_str;
                char_stack.pop();
            }
            if (char_stack.top() == '[' && !char_stack.empty())
                char_stack.pop();
            
            for (int j = 0; j < count; j++)
                result = result + temp_str;
            
            for (auto ch: result)
                char_stack.push(ch);
            
            result.clear();        
        }

        // if string, puch it to the char stack
        else
            char_stack.push(in_str[i]);
    }
    
    // convert to result
    while (!char_stack.empty())
    {
        result = char_stack.top() + result;
        char_stack.pop();
    }
    return result;
}

int main()
{
    std::cout << string_decode("3[b2[ca]]") << '\n';

    return 0;
}