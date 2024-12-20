class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int psum=0;
        int count=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            psum=psum+nums[i];
            int remove=psum-k;
            count=count+mp[remove];
            mp[psum]++;
        }
        return count;
    }
};