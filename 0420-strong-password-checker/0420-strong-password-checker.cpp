
class Solution {
public:
    int strongPasswordChecker(string s) {
        int n = (int)s.size();
        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (char c : s) {
            unsigned char uc = static_cast<unsigned char>(c);
            hasLower |= islower(uc);
            hasUpper |= isupper(uc);
            hasDigit |= isdigit(uc);
        }
        int missing = (!hasLower) + (!hasUpper) + (!hasDigit);

        vector<int> runs;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) ++j;
            int len = j - i;
            if (len >= 3) runs.push_back(len);
            i = j;
        }

        if (n < 6) return max(missing, 6 - n);

        int replacements = 0, cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int len : runs) {
            replacements += len / 3;
            if (len % 3 == 0) ++cnt0;
            else if (len % 3 == 1) ++cnt1;
            else ++cnt2;
        }

        if (n <= 20) return max(missing, replacements);

        int deletions = n - 20;

        int use = min(cnt0, deletions);
        replacements -= use; deletions -= use;

        use = min(cnt1, deletions / 2);
        replacements -= use; deletions -= use * 2;

        use = min(cnt2, deletions / 3);
        replacements -= use; deletions -= use * 3;

        if (deletions > 0) {
            int extra = min(deletions / 3, replacements);
            replacements -= extra;
        }

        return (n - 20) + max(missing, replacements);
    }
};