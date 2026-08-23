class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int e : nums) {
            freq[e]++;
        }
        using Element = pair<int, int>;
        priority_queue<Element, vector<Element>, greater<Element>> pq;
        for (const auto& [num, times] : freq) {
            pq.push({times, num});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> topK;
        while (!pq.empty()) {
            int top_element = pq.top().second;
            pq.pop();
            topK.push_back(top_element);
        }
        return topK;
    }
};
