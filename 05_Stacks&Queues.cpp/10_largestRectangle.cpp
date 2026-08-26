int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int curHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && curHeight < heights[st.top()]) {
            int idx = st.top();
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;

            maxArea = max(maxArea, heights[idx] * width);
        }

        st.push(i);
    }

    return maxArea;
}