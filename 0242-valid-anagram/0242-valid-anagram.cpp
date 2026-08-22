class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m!=n) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t) return true;
        else return false;
        
    }
};