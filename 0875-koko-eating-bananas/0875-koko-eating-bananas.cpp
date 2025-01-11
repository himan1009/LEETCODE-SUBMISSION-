class Solution {
public:
    long long int func(int mid, vector<int> &piles, int h){
        long long int tot_hrs=0;
        for(int i=0;i<piles.size();i++){
            tot_hrs+=ceil((double)piles[i]/mid);
        }
        return tot_hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int low=1;
        long long int high=*max_element(piles.begin(), piles.end());
        long long int ans=INT_MAX;
        while(low<=high){
            long long int mid=low+(high-low)/2;
            if(func(mid, piles, h)<=h){
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