class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        unordered_map<char, int> mpp;
        for (auto ch : magazine) {
            mpp[ch]++;
        }
        for (auto ch : ransomNote) {
            if (mpp.find(ch) != mpp.end()) {
                mpp[ch]--;
                if (mpp[ch] == 0)
                    mpp.erase(ch);
            } else
                return false;
        }
        return true;
    }
};