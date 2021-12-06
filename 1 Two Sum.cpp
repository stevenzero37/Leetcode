#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<int, int> temp;    //key:value, value:index
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map <int, int> temp;  
        for (int i=0;i<nums.size();i++) {
            if (temp.count(target - nums[i]) == 0)
                temp[nums[i]] = i;
            else {
                return {temp[target - nums[i]], i};
            }
        }
        return {};   
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