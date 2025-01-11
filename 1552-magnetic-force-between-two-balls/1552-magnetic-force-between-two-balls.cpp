class Solution {
public:
    // aggresive cows wala logic
    bool func(int mid, vector<int> &pos, int m){
        int cowCount=1;
        int last=pos[0];
        for(int i=0;i<pos.size();i++){
            if(pos[i]-last>=mid){
                cowCount++;
                if(cowCount==m)
                return true;
                last=pos[i];
            }
        }
        return false;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int low=1;
        int high=*max_element(pos.begin(), pos.end());
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if (func(mid, pos, m)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};