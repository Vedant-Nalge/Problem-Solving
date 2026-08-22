class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int cnd = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                cnd = nums[i];
                count++;
            } else {
                if (nums[i] == cnd)
                    count++;
                else
                    count--;
            }
        }
        return cnd;
    }
};