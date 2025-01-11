class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int low=1;
        int high=nums.size()-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            return mid;

            else if(nums[mid-1]<nums[mid])
            low=mid+1;
            
            else
            high=mid-1;
        }
        return -1;
    }
};