class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string word;
        stack<string> st;

        while(getline(ss,word,'/')){
            if(word=="" || word == ".") continue;
            else if (word==".."){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(word);
            }

        }

        string result = "";
        while(!st.empty()){
            result = "/" + st.top() + result;
            st.pop();
        }
        return result.empty() ? "/" : result;
    }
};