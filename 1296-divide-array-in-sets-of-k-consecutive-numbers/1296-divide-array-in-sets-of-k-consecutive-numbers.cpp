class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0)
            return false;

        map<int, int> mpp;

        for (int x : nums) {
            mpp[x]++;
        }

        while (!mpp.empty()) {
            int start = mpp.begin()->first;

            for (int i = start; i < start + k; i++) {
                if (mpp[i] == 0)
                    return false;
                mpp[i]--;

                if (mpp[i] == 0)
                    mpp.erase(i);
            }
        }
        return true;
    }
};