#include <vector>
#include <algorithm>
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> low;
        vector<int> equal;
        vector<int> high;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==pivot){
                equal.push_back(pivot);
            }else if(nums[i]<pivot){
                low.push_back(nums[i]);
            }else{
                high.push_back(nums[i]);
            }
        }
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(j<low.size()){
                nums[i]=low[j];
            }else if(j<low.size()+equal.size()){
                nums[i]=equal[j-low.size()];
            }else{
                nums[i]=high[j-low.size()-equal.size()];
            }
            j++;
        }
        return nums;
    }
};