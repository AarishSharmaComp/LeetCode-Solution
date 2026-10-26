class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<pair<int,int>> st;    //number, index
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            while(st.size() && temperatures[i]>=st.top().first)  st.pop();
            if(st.size())   ans[i]=st.top().second-i;
            st.push({temperatures[i],i});
        }
        return ans;
    }
};