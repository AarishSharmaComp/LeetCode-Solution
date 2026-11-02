class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        remove(s, ans, 0, 0, '(', ')');
        return ans;
    }

    void remove(string s, vector<string>& ans, int i, int j, char open, char close) {
        int count = 0;

        for (int k = i; k < s.size(); k++) {
            if (s[k] == open)
                count++;

            if (s[k] == close)
                count--;

            if (count < 0) {
                for (int x = j; x <= k; x++) {
                    if (s[x] == close && (x == j || s[x - 1] != close)) {
                        remove(
                            s.substr(0, x) + s.substr(x + 1),
                            ans,
                            k,
                            x,
                            open,
                            close
                        );
                    }
                }
                return;
            }
        }

        reverse(s.begin(), s.end());

        if (open == '(') {
            remove(s, ans, 0, 0, ')', '(');
        }
        else {
            ans.push_back(s);
        }
    }
};