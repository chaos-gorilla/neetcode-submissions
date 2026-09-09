#include <string>
#include <vector>
#include <climits>

using namespace std;

// "aaaavddsfasdfsdfasf"  "fasd" 

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.length() < t.length()) {
            return "";
        }

        // Fixed-size array covers all standard ASCII characters (faster than unordered_map)
        int target_freq[128] = {0};
        int window_freq[128] = {0};
        int unique_chars_needed = 0;

        for (char ch : t) {
            if (target_freq[ch] == 0) {
                unique_chars_needed++;
            }
            target_freq[ch]++;
        }

        int left = 0;
        int min_len = INT_MAX;
        int start_idx = 0;
        int satisfied_chars = 0;

        for (int right = 0; right < s.length(); right++) {
            unsigned char r_char = s[right];
            window_freq[r_char]++;

            // Character count matches target requirement
            if (target_freq[r_char] > 0 && window_freq[r_char] == target_freq[r_char]) {
                satisfied_chars++;
            }

            // Shrink window from the left while it is valid
            while (satisfied_chars == unique_chars_needed) {
                int current_window_len = right - left + 1;
                if (current_window_len < min_len) {
                    min_len = current_window_len;
                    start_idx = left;
                }

                unsigned char l_char = s[left];
                window_freq[l_char]--;
                if (target_freq[l_char] > 0 && window_freq[l_char] < target_freq[l_char]) {
                    satisfied_chars--;
                }
                left++;
            }
        }

        return (min_len == INT_MAX) ? "" : s.substr(start_idx, min_len);
    }
};