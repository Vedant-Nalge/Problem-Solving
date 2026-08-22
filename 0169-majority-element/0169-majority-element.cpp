class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> hash;

        int ans = -1;


        for (int it = 0; it < n; it++) {
            hash[nums[it]]++;
            if (hash[nums[it]] > n/2) {
               return nums[it];
            }
        }
   return -1;
       
    }
};