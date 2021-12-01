#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colorsMap (3); //0, 1, 2
        for(auto num:nums) colorsMap[num]++; //record the amount of number 0,1,2 into the map
        //acording to the map, update nums
        for(int i=0, cur = 0;i<colorsMap.size();++i) {
            for(int j=0;j<colorsMap[i];++j) {
                nums[cur] = i;
                cur++;
            }
        }
    }
};

int main() {
    unique_ptr<Solution> example = make_unique<Solution> ();
    vector<int> inputData = {2,0,2,1,1,0};
    
    example->sortColors(inputData);

}