#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1, mid;

        while(start<=end){
            mid = (start + end)/2;
            if (nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }

        return start;
    }
};

int main() {
    std::vector<int> data1 {1,3,5,6};
    std::unique_ptr<Solution> example = std::make_unique<Solution> ();

    cout << example->searchInsert(data1, 2);

}