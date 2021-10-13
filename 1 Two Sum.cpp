#include <iostream>
#include <vector>
#include <map>

class Solution {
private:
    int temp;
    std::map<int, int> dict;    //key:value, value:index
public:
    Solution () : temp(0) {}

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); ++i) {
            temp = target - nums[i];
            if (dict[temp] == )
                dict[temp] = 
        }
    }
};

int main() {
    Solution *example = new Solution();
    
    std::vector<int> input {2,7,11,15};
    std::vector<int> output;
    std::vector<int>::iterator it;    
    output = example->twoSum (input, 9);
    
    for (it=output.begin();it!=output.end();++it) {
        std::cout << *it << std::endl;
    }
    
    delete example;
}