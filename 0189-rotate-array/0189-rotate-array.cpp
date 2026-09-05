class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        int a = k%n;
        reverse(nums.begin(), nums.begin() + n - a);
        reverse(nums.begin() + n - a, nums.begin() + n );

        reverse(nums.begin(),nums.end());
    }
};