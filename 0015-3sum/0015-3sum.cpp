class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int one = nums[i];
            int l = i + 1;
            int h = n - 1;
            while (l < h) {
                int sum = one + nums[l] + nums[h];
                if (sum == 0) {
                    ans.push_back({one, nums[l], nums[h]});
                    while (l < h && nums[l] == nums[l + 1])
                        l++;
                    while (l < h && nums[h] == nums[h - 1])
                        h--;
                    l++;
                    h--;
                } else if (sum < 0)
                    l++;
                else
                    h--;
            }
        }
        return ans;
    }
};