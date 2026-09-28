class Solution {
public:
    string below1000(int n) {
        vector<string> ones = {
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
            "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };

        vector<string> tens = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety"
        };

        string ans;

        if (n >= 100) {
            ans += ones[n / 100] + " Hundred";
            n %= 100;
            if (n) ans += " ";
        }

        if (n >= 20) {
            ans += tens[n / 10];
            n %= 10;
            if (n) ans += " " + ones[n];
        } 
        else if (n > 0) {
            ans += ones[n];
        }

        return ans;
    }

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        vector<string> scale = {
            "", "Thousand", "Million", "Billion"
        };

        string ans;
        int group = 0;

        while (num > 0) {
            int part = num % 1000;

            if (part != 0) {
                string current = below1000(part);

                if (!scale[group].empty())
                    current += " " + scale[group];

                if (!ans.empty())
                    ans = current + " " + ans;
                else
                    ans = current;
            }

            num /= 1000;
            group++;
        }

        return ans;
    }
};