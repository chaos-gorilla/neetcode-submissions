class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            counts[s[right] - 'A']++;
            int max_occurence = *max_element(counts.begin(), counts.end());
            while ((right - left + 1) - max_occurence > k) {
                counts[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, (right - left) + 1);
        }
        return ans;
    }
};
