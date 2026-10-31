#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastocc(26, -1);
        vector<bool> vis(26, false);
        string result = "";
        
        
        for (int i = 0; i < s.length(); i++) {
            lastocc[s[i] - 'a'] = i;
        }
        
      
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            int idx = ch - 'a';
            
         
            if (vis[idx]) continue;
            
           
            while (!result.empty() && result.back() > ch && lastocc[result.back() - 'a'] > i) {
                vis[result.back() - 'a'] = false;
                result.pop_back();
            }
        
            result.push_back(ch);
            vis[idx] = true;
        }
        
        return result;
    }
};