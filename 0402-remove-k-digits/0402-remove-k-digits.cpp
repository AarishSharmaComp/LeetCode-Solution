class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        for(char c:num){
             while(!st.empty() && (st.top()-'0')>(c-'0') && k>0){
                st.pop();
                k--;
             }
             st.push(c);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()!=0 && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.size()==0) return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};