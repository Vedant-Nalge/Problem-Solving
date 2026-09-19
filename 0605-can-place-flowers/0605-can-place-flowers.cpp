class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int t = flowerbed.size();
        int cnt = 0;
        if (n == 0)
            return true;
        if (t == 1) {
            if (n > 1)
                return false;
            else {
                if (flowerbed[0] == 0)
                    return true;
                else
                    return false;
            }
        }
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            cnt++;
        }
        for (int i = 1; i < t - 1; i++) {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 &&
                (flowerbed[i - 1] == flowerbed[i + 1])) {
                flowerbed[i] = 1;
                cnt++;
            }
        }
        if (flowerbed[t - 1] == 0 && flowerbed[t - 2] == 0) {
            flowerbed[t - 1] = 1;
            cnt++;
        }

        return (cnt >= n);
    }
};