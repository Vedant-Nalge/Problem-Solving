class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        while(l<n && r<n){
            int pro = 1;
            for(int i = l; i<=r;i++){
                pro*=nums[i];
            }
            if(pro<k){
                cnt+=r-l+1;
                r++;
            }
            else{
                l++;
            }
        }
        return cnt;
        
    }
};