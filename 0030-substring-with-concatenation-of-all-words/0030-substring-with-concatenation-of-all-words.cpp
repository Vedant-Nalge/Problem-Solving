#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int sLen = s.size();
        int numWords = words.size();
        int wordLen = words[0].size();
        int totalLen = numWords * wordLen;

        if (sLen < totalLen) return ans;

        // Build target frequency map
        unordered_map<string, int> wordCounts;
        for (const string& w : words) {
            wordCounts[w]++;
        }

        // Run wordLen sliding windows for offsets 0 to wordLen - 1
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int right = i;
            int matched = 0;
            unordered_map<string, int> windowCounts;

            while (right + wordLen <= sLen) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                // If word exists in target map
                if (wordCounts.count(word)) {
                    windowCounts[word]++;
                    matched++;

                    // If frequency exceeds target count, shrink window from left
                    while (windowCounts[word] > wordCounts[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowCounts[leftWord]--;
                        matched--;
                        left += wordLen;
                    }

                    // Complete permutation matched
                    if (matched == numWords) {
                        ans.push_back(left);
                    }
                } else {
                    // Invalid word encountered: reset window state
                    windowCounts.clear();
                    matched = 0;
                    left = right;
                }
            }
        }

        return ans;
    }
};