class Solution {
public:
    int findMin(vector<int> &nums) {
        // 1. Find pivot element
        // 2. The element right to the pivot element is going to be the 
        // min element.
        return *min_element(nums.begin(), nums.end());
    }
};
