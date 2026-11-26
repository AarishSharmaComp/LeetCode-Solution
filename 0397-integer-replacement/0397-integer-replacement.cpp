class Solution {
public:
    // please upvote :)
    int integerReplacement(int tn) {
        long long n = tn;  // use long long to avoid overflow on n+1
        int cnt = 0;
        while (n > 1) {
            if (n == 3) n--;
            else if (n % 2 == 0) n /= 2;
            else if (n % 4 == 1) n--;
            else n++;
            cnt++;
        }
        return cnt;
    }
};