#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size1 = m-1;
        int size2 = n-1;
        int total_size = m+n-1;

        while (size2 >= 0 && size1 >= 0) {
            cout << size1 << " " << size2 << " " << total_size << endl;
            if (nums1[size1] < nums2[size2]) {
                nums1[total_size] = nums2[size2];
                total_size--;
                size2--;
            }
            else {
                nums1[total_size] = nums1[size1];
                total_size--;
                size1--;
            }
        }
        
        while (size2 >= 0) {
            nums1[size2] = nums2[size2];
            size2--;
        }
        
        
        for (int i=0;i<nums1.size();++i)
            cout << nums1[i] << " ";
    }
};

//{0}, 0
//{1}, 1
int main () {
    vector<int> data1 {0};
    vector<int> data2 {1};
    
    unique_ptr<Solution> example = make_unique<Solution>();
    
    example->merge(data1, 0, data2, 1);
    
    return 0;
}