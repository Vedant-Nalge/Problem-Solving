class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int one = nums[i];
            int l = i + 1;
            int h = n - 1;
            while (l < h) {
                int sum = nums[l] + nums[h] + one;
                if (sum == 0) {
                    ans.push_back({one, nums[l], nums[h]});
                    while (l < h && nums[l] == nums[l + 1]) l++;
                    while (l < h && nums[h] == nums[h - 1]) h--;
                    l++;
                    h--;
                } else if (sum > 0)
                    h--;
                else
                    l++;
            }
        }
        return ans;
    }
};