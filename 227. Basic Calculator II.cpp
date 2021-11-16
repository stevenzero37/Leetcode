#include <iostream>
#include <string>
#include <memory>
#include <stack>

class Solution {
public:
    int calculate(std::string s) {
        int number = 0;
        int data;
        std::stack<int> intStack;
        
        char sign = '+';
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i]))
                number = number*10 + (s[i] - '0'); //char to int
            
            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1) {
                if (sign == '+')
                    intStack.push(number);
                else if (sign == '-')
                    intStack.push(-number);
                else if (sign == '*') {
                    data = intStack.top();
                    intStack.pop();
                    number = data*number;
                    intStack.push(number);
                }
                else if (sign == '/') {
                    data = intStack.top();
                    intStack.pop();
                    number = data/number;
                    intStack.push(number);                    
                }
                
                number = 0;
                data = 0;
                sign = s[i];
            }
        }
        
        number = 0;
        while (!intStack.empty()) {
            std::cout << intStack.top() << std::endl;
            number += intStack.top();
            intStack.pop();
        }

        return number;
    }
};

int main () {
    std::unique_ptr <Solution> example = std::make_unique<Solution>();
    
    example->calculate(" 1 + 2 * 504 ");
    
    return 0;
}