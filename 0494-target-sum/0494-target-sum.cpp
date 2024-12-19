class Solution {
public:
    int func(vector<int> &nums, int ind, int c_sum, int target){
        if(ind==nums.size()){
            if(c_sum==target)
            return 1;
            else
            return 0;
        }

        int add=func(nums, ind+1, c_sum+nums[ind], target);
        int substract=func(nums, ind+1, c_sum-nums[ind], target);
        
        return add+substract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return func(nums, 0, 0, target);
    }
};