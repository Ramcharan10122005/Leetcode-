class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int count=0;
        for(auto ch:s){
            if(ch=='[')
            st.push(ch);
            else{
                if(!st.empty())
                st.pop();
                else
                count++;
            }
        }
        return (count+1)/2;
    }
};