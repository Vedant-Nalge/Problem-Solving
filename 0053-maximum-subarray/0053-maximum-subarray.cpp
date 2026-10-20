class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0 ; i< n ;i++){
            sum +=nums[i];
            if(sum<0){
                maxi = max(maxi,sum);
                sum = 0;
                continue;
            }
            else{
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};