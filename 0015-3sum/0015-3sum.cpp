class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i=0;i<nums.size()-2;i++){
            int el1=nums[i];
            int target=-nums[i];
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                if(nums[low]+nums[high]==target){
                    st.insert({el1, nums[low], nums[high]});
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high]<target){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};