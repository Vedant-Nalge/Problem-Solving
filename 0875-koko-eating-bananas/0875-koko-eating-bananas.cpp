class Solution {
public:
    long long helper(int k,vector<int>&piles){
        long long hrs = 0;
        for(auto it : piles){
            hrs = hrs + (it+k-1)/k;
        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = 0;
        int low = 1;
        int high =*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid = low + (high - low)/2;
            long long hrs = helper(mid,piles);
            if(hrs<=h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
        
    }
};