class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int beginPtr = 0;
        int endPtr = numbers.length - 1;
        int[] result = new int[2];

        while (beginPtr < endPtr) {
            int sum = numbers[beginPtr] + numbers[endPtr];
            if (sum == target) {
                result[0] = beginPtr + 1;
                result[1] = endPtr + 1;
                return result;
            } else if (sum < target) {
                beginPtr++;
            } else {
                endPtr--;
            }
        }

        return result;
    }
}
