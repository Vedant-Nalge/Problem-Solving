class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1;
        int end = -2;

        int max_seen = nums[0];
        int min_seen = nums[n -1];

        for(int i = 1; i<n ; i++){
             max_seen = max(max_seen,nums[i]);
            if(nums[i]< max_seen){
              end = i;
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            min_seen = min(min_seen, nums[i]);
            if (nums[i] > min_seen) {
                start = i;
            }
        }

  return end - start +1;
    }
};