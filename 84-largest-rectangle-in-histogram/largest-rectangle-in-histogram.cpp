class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size(),area=heights[0];
        //keep area as default heights[0], else if kept INT_MIN handle single element case [0]
        stack<int> st;
        int current_height;
        for(int i=0;i<=size;i++){
            current_height = (i==size) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] > current_height){
                int top = st.top(); st.pop();
                if(!st.empty())
                area = max(area,(i-st.top()-1)*heights[top]);
                else
                area = max(area,(i)*heights[top]);
            }
            st.push(i);
        }
        return area;
    }
};