class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // Skip duplicate values for the first number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int one = nums[i];

            for (int j = i + 1; j < n; j++) {
                // Skip duplicate values for the second number
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int two = nums[j];
                int l = j + 1;
                int h = n - 1;

                while (l < h) {
                    // Use long long to avoid potential integer overflow
                    long long sum = (long long)one + two + nums[l] + nums[h];

                    if (sum == target) {
                        ans.push_back({one, two, nums[l], nums[h]});

                        // Skip duplicate values for 'l' and 'h'
                        while (l < h && nums[l] == nums[l + 1]) l++;
                        while (l < h && nums[h] == nums[h - 1]) h--;

                        l++;
                        h--;
                    } else if (sum > target) {
                        h--;
                    } else {
                        l++;
                    }
                }
            }
        }

        return ans;
    }
};