class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int psum=0;
        int ans=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        for(auto it:nums){
            psum=psum+it;
            if(mp.find(psum-k)!=mp.end()){
                ans=ans+mp[psum-k];
            }
            mp[psum]++;
        }
        return ans;
    }
};