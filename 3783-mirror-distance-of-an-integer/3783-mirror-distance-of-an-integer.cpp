class Solution {
public:
    int mirrorDistance(int n) {
        string s =to_string(n);
        string t = s;
        reverse(t.begin(),t.end());
        int m =stoi(t);

        return abs(m-n);
        
    }
};