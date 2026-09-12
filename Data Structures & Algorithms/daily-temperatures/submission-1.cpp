class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        const int n = temps.size();
        vector<int> results(n, 0);
        
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            int current_temp = temps[i];
            while (!st.empty() and current_temp > st.top().second) {
                results[st.top().first] = i - st.top().first;
                st.pop();
            }
            st.push({i, current_temp});
        }

        return results;
    }
};
