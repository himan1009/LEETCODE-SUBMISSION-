class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int psum=0;
        int ans=0;
        unordered_map<int, int> mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            psum=psum+1;
            else
            psum=psum-1;
            if(mp.find(psum)==mp.end()){
                mp[psum]=i;
            }
            ans=max(ans, i-mp[psum]);
        }
        return ans;
    }
};