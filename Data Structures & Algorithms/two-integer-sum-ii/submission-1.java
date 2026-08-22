class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int beginPtr = 0;
        int endPtr = numbers.length - 1;

        while (beginPtr < endPtr) {
            int sum = numbers[beginPtr] + numbers[endPtr];
            if (sum == target) {
                return new int[]{beginPtr + 1, endPtr + 1};
            } else if (sum < target) {
                beginPtr++;
            } else {
                endPtr--;
            }
        }

        return new int[]{-1, -1};
    }
}
