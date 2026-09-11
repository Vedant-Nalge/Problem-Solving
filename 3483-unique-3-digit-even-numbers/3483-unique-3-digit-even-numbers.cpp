class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        vector<int> freq(10, 0);

        for (int x : digits) {
            freq[x]++;
        }

        for (int i = 100; i <= 998; i++) {
            if (i % 2 != 0)
                continue;
            int temp = i;
            int c = temp % 10;
            temp /= 10;
            int b = temp % 10;
            temp /= 10;
            int a = temp;

            freq[a]--;
            freq[b]--;
            freq[c]--;

            if (freq[a] >= 0 && freq[b] >= 0 && freq[c] >= 0)
                ans++;

            freq[a]++;
            freq[b]++;
            freq[c]++;
        }
        return ans;
    }
};