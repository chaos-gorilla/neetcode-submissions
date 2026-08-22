class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_pos_seen;
        int biggest = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch_at_right = s[right];
            if (last_pos_seen.find(ch_at_right) != last_pos_seen.end()) {
                // char is already seen.
                left = max(left, last_pos_seen[ch_at_right] + 1);
            }
            last_pos_seen[ch_at_right] = right;
            biggest = max(biggest, (right - left) + 1);
        }

        return biggest;
    }
};
