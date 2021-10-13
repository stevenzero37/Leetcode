#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
private:
    std::unordered_map<char, int> dict;
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int>::iterator it;
        bool flag = true;
        
        if (s.size() != t.size()) {
            flag = false;
            return flag;
        }

        for(int i=0; i<s.size();++i) {
            dict[s[i]]++;
            dict[t[i]]--;
        }
        
        for (it=dict.begin(); it!=dict.end(); ++it) {
            if(it->second != 0) 
                flag = false;
        }
        
        return flag;
    }
};

int main() {
    Solution *example = new Solution();
    
    std::cout << example->isAnagram("anagram", "ngraaam") << std::endl;
}