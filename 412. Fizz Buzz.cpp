#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<string> temp;
public:
    vector<string> fizzBuzz(int n) {
        for (int i = 1; i <= n; ++i) {
            if ((i % 3 == 0) && (i % 5 == 0))
                temp.push_back("FizzBuzz");
            else if (i % 3 == 0)
                temp.push_back("Fizz");
            else if (i % 5 == 0)
                temp.push_back("Buzz");
            else
                temp.push_back(to_string(i));
        }
        
        for (int i = 0; i < temp.size(); ++i) 
            cout << temp[i] << endl;
        
        return temp;
    }
};

int main () {
    std::unique_ptr<Solution> example = std::make_unique<Solution> ();
    
    example->fizzBuzz(15);
    
    return 0;
}