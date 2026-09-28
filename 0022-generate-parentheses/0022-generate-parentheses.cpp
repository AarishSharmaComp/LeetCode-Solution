class Solution {
public:
    vector<string> result;

    void generate(string s, int open, int close, int n) {
        if (s.size() == 2 * n) {
            result.push_back(s);
            return;
        }

        if (open < n) {
            generate(s + "(", open + 1, close, n);
        }

        if (close < open) {
            generate(s + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        generate("", 0, 0, n);
        return result;
    }
};