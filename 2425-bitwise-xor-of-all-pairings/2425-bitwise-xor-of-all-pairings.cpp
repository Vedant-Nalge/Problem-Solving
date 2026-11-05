class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n % 2 == 0 && m % 2 == 0)
            return 0;
        else if (n % 2 != 0 && m % 2 != 0) {
            int xor1 = 0;
            int xor2 = 0;
            for (auto it : nums1)
                xor1 ^= it;
            for (auto it : nums2)
                xor2 ^= it;

            return xor1 ^ xor2;
        } else {
            if (n & 2 != 0 && m % 2 == 0) {
                int xor1 = 0;
                for (auto it : nums2)
                    xor1 ^= it;
                return xor1;
            } else {
                int xor1 = 0;
                for (auto it : nums1)
                    xor1 ^= it;
                return xor1;
            }
        }
        return 0;
    }
};