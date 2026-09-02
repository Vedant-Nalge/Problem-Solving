class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> mpp;
        int left = 0;
        int maxi = 0;

        for (int right = 0; right < fruits.size(); right++) {
            mpp[fruits[right]]++;
            if (mpp.size() > 2) {
                mpp[fruits[left]]--;

                if (mpp[fruits[left]] == 0)
                    mpp.erase(fruits[left]);

                left++;
            }

            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};