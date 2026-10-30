class Solution {
public:
    int helper(int day, const vector<int>& bloomDay, int k) {
        int bouquets = 0;
        int consecutive = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                consecutive++;
                if (consecutive == k) {
                    bouquets++;
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
            }
        }
        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        if ((long long)m * k > bloomDay.size()) return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (helper(mid, bloomDay, k) >= m) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};