class Solution {
public:
    int func(vector<int> &nums, int pages){
        int stud=1;
        long long pagestud=0;

        for(int i=0;i<nums.size();i++){
            if(pagestud+nums[i]<=pages){
                pagestud=pagestud+nums[i];
            }
            else{
                stud++;
                pagestud=nums[i];
            }
        }
        return stud;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size())
        return -1;

        int low=*max_element(nums.begin(), nums.end());
        int high=accumulate(nums.begin(), nums.end(), 0);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(nums, mid)<=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};