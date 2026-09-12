class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        const int n = temps.size();
        vector<int> results(n, 0);
        stack<int> temp_stack;

        for (int i = 0; i < n; i++) {
            // get the temperature of today.
            int current_temp = temps[i];
            while (!temp_stack.empty() and current_temp > temps[temp_stack.top()]) {
                const int top_index = temp_stack.top();
                temp_stack.pop();
                results[top_index] = i - top_index;
            }
            temp_stack.push(i);
        }
        return results;
    }
};
