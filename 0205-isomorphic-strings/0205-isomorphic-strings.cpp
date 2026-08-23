class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n =s.size();
        int m =t.size();
        if(m!=n) return false;

        vector<int> st(256);
        vector<int> ts(256);

        for(int i =0;i<n;i++){

            if(st[s[i]]!=0 && st[s[i]]!=t[i]) return false;
             if  (ts[t[i]]!=0 && ts[t[i]]!=s[i]) return false;
            st[s[i]]=t[i];
            ts[t[i]] = s[i];
        
        } 
        return true;       
    }
};