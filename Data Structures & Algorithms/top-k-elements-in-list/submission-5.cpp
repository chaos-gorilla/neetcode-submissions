class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> counts(2001, 0);
        for (int num : nums) {
            counts[num + 1000]++;
        }

        vector<int> answer(k);
        for (int i = 0; i < k; i++) {
            int max_seen = 0;
            int max_index = 0;

            for (int j = 0; j < 2001; j++) {
                if (counts[j] > max_seen) {
                    max_seen = counts[j];
                    max_index = j;
                }
            }

            answer[i] = max_index - 1000;
            counts[max_index] = 0;
        }

        return answer;
    }
};
