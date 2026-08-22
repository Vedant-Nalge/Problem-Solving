#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string beginWord,
             unordered_map<string, vector<string>>& parent) {

        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (string p : parent[word]) {
            path.push_back(p);

            dfs(p, beginWord, parent);

            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};

        unordered_map<string, vector<string>> parent;

        queue<string> q;
        q.push(beginWord);

        st.erase(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int size = q.size();

            // Words discovered at this level
            unordered_set<string> used;

            for (int k = 0; k < size; k++) {

                string word = q.front();
                q.pop();

                string temp = word;

                for (int i = 0; i < temp.size(); i++) {

                    char original = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {

                        if (c == original)
                            continue;

                        temp[i] = c;

                        if (st.count(temp)) {

                            // First time discovering this word
                            if (!used.count(temp)) {
                                used.insert(temp);
                                q.push(temp);
                            }

                            // Store all parents at this shortest level
                            parent[temp].push_back(word);

                            if (temp == endWord)
                                found = true;
                        }
                    }

                    temp[i] = original;
                }
            }

            // Remove only after completing the entire level
            for (string word : used)
                st.erase(word);
        }

        if (!found)
            return {};

        // Reconstruct all shortest paths
        path.push_back(endWord);

        dfs(endWord, beginWord, parent);

        return ans;
    }
};