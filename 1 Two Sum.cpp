#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> cache;
        std::vector<int> answer;
        
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int needed_num = target - nums[i];
            
            if (cache.find(needed_num) != cache.end())
            {
                // We found it
                answer.push_back(cache[needed_num]);
                answer.push_back(i);
                return answer;
            }
            else
            {
                // Didn't find it
                cache.insert(std::make_pair(nums[i], i));
            }
        }
        return answer;
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