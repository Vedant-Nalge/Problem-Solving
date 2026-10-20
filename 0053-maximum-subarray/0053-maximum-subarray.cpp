class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        int ans_st = 0;
        int ans_e = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            if(sum<0) {
                sum = nums[i];
                start = i;
            }
            else sum+=nums[i];

            if(maxi<sum){
                maxi = sum;
                ans_st = start;
                ans_e = i;
            }
        }
        return maxi;
    }
};