class Solution {
public:
    int helper(int n) {
        int sum = 0;
        while (n > 0) {
            int digi = n % 10;
            sum += digi * digi;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> seen;
        while (n != 1) {
            if (seen.find(n) != seen.end()) {
                return false;
            }
            seen.insert(n);
            n = helper(n);
        }
        return true;
    }
};