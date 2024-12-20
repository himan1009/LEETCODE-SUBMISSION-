class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int psum=0;
        int count=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            psum=psum+nums[i];
            // for handling negative cases when psum becomes negative.
            if(psum<0){
                psum=k-((-1*psum)%k);
            }
            count=count+mp[psum%k];
            mp[psum%k]++;
        }
        return count;
    }
};