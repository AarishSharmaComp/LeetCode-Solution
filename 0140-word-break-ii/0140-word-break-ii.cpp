class Solution {
public:
    unordered_set<string> dict;
    vector<string> memo[301];

    vector<string> solve(string& s, int start) {
        if (start == s.size()) {
            return {""};
        }

        if (!memo[start].empty()) {
            return memo[start];
        }

        string word;

        for (int end = start; end < s.size(); end++) {
            word += s[end];

            if (dict.find(word) != dict.end()) {
                vector<string> remaining = solve(s, end + 1);

                for (string sentence : remaining) {
                    if (sentence.empty()) {
                        memo[start].push_back(word);
                    } else {
                        memo[start].push_back(word + " " + sentence);
                    }
                }
            }
        }

        return memo[start];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict) {
            dict.insert(word);
        }

        return solve(s, 0);
    }
};