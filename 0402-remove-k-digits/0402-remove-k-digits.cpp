class Solution {
public:
    string removeKdigits(string num, int k) {

        string  st;
        int n = num.size();
        for(int digit : num){
        while(!st.empty() && k>0 && st.back()>digit){
            st.pop_back();
            k--;
        }
        st.push_back(digit);
        }

        while(k>0 && st.size()!=0){
            st.pop_back();
            k--;
        }

        int pos =0;

        while(pos<st.size() && st[pos]=='0'){
            pos++;
        }

        if(pos == st.size()) return "0";

        return st.substr(pos);
        
    }
};