class Solution {
    static class Pair {
        int number;
        int index;

        Pair(int number, int index) {
            this.number = number;
            this.index = index;
        }
    }
    
    public int[] twoSum(int[] nums, int target) {
        List<Pair> numToIndex = new ArrayList<>();
        int[] result = new int[2];

        for (int i = 0; i < nums.length; i++) {
            numToIndex.add(new Pair(nums[i], i));
        }

        numToIndex.sort(new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                return p1.number - p2.number;
            }
        });

        int beginPtr = 0;
        int endPtr = numToIndex.size() - 1;

        while (beginPtr < endPtr) {
            Pair p1 = numToIndex.get(beginPtr);
            Pair p2 = numToIndex.get(endPtr);
            int pairSum = p1.number + p2.number;
            if (pairSum == target) {
                return new int[] { Math.min(p1.index, p2.index), Math.max(p1.index, p2.index) };
            } else if (pairSum < target) {
                beginPtr++;
            } else {
                endPtr--;
            }
        }

        return result;
    }
}
