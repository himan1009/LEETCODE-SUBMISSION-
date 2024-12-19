class Solution {
public:
    void func(vector<int> &nums, int ind, vector<vector<int>> &ans, vector<int> &temp){
        if(ind==nums.size()){
            ans.push_back(temp);
            return;
        }
        func(nums, ind+1, ans, temp);
        temp.push_back(nums[ind]);
        func(nums, ind+1, ans, temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(nums, 0, ans, temp);
        return ans;
    }
};