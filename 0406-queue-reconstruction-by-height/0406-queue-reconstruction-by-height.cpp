class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        // Height descending
        // k ascending when heights are equal
        sort(people.begin(), people.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] < b[1];

                return a[0] > b[0];
            });

        vector<vector<int>> result;

        for (auto& person : people) {
            result.insert(result.begin() + person[1], person);
        }

        return result;
    }
};