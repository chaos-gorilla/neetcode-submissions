class Solution {
public:
    int trap(vector<int>& height) {
        int total_water_trapped = 0;

        int l = 0;
        int r = height.size() - 1;
        int left_max = height[l];
        int right_max = height[r];

        while (l < r) {
            if (left_max < right_max) {
                l++;
                left_max = max(left_max, height[l]);
                total_water_trapped += (left_max - height[l]);
            } else {
                r--;
                right_max = max(right_max, height[r]);
                total_water_trapped += (right_max - height[r]);
            }
        }

        return total_water_trapped;
    }
};
