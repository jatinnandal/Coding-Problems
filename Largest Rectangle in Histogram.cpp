class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxm = 0;
        for(int i=0;i<heights.size();i++){
            if(st.empty() || heights[i]>=heights[i-1]){
                st.push(i+1);
            }else{
                while(!st.empty() && heights[st.top()-1]>heights[i]){
                    int x = st.top();
                    st.pop();
                    maxm = max(maxm,(st.empty()?(i):i-st.top())*heights[x-1]);
                }
                st.push(i+1);
            }
        }
        int idx = heights.size();
        while(!st.empty()){
            int x = st.top();
            st.pop();
            maxm = max(maxm, (st.empty()?(idx):idx - st.top())*heights[x-1]);
        }
        return maxm;
    }
};
