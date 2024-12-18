class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums.size()<4)
        return {};
        set<vector<int>> st;
        for(int i=0;i<nums.size()-3;i++){
            long long int el1=nums[i];
            for(int j=i+1;j<nums.size()-2;j++){
                long long int el2=nums[j];
                long long int low=j+1;
                long long int high=nums.size()-1;
                while(low<high){
                    long long int tar=nums[low]+nums[high]+el1+el2;
                    if(tar==target){
                        st.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                    }
                    else if(tar>target){
                        high--;
                    }
                    else{
                        low++;
                    }
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