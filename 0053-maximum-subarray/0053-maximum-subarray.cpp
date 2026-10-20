class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int maxi = INT_MIN;
    int sum =0;
    int anst = -1;
    int anse = -1;
    int start=0;
    for(int i =0;i<nums.size();i++){
      if (sum < 0) {
                sum = nums[i];
                start = i; // Start new subarray
            } else {
                sum += nums[i];
            }
     if(sum>maxi){
        maxi = sum;
        anst =start;
        anse = i;
     } 

    }


return maxi;



    }
};