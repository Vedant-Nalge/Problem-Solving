class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        int g = groupSize;
        if (n % g != 0)
            return false;

        map<int, int> mpp;

        for (int x : hand) {
            mpp[x]++;
        }

        while (!mpp.empty()) {
            int start = mpp.begin()->first;

            for (int i = start; i < start + g; i++) {
                if (mpp[i] == 0)
                    return false;
                else {
                    mpp[i]--;
                }
                if (mpp[i] == 0)
                mpp.erase(i);
            }
            
        }

        return true;
    }
};