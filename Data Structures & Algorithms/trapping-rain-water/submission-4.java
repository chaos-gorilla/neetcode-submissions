class Solution {
    public int trap(int[] height) {
        int[] maxHeightLeft = new int[height.length];
        int[] maxHeightRight = new int[height.length];

        maxHeightLeft[0] = 0;
        int maxHeightSeenSoFar = 0;
        for (int i = 0; i < height.length; i++) {
            maxHeightLeft[i] = maxHeightSeenSoFar;
            maxHeightSeenSoFar = Math.max(maxHeightSeenSoFar, height[i]);
        }

        maxHeightSeenSoFar = 0;
        maxHeightRight[height.length - 1] = 0;
        for (int i = height.length - 1; i >= 0; i--) {
            maxHeightRight[i] = maxHeightSeenSoFar;
            maxHeightSeenSoFar = Math.max(maxHeightSeenSoFar, height[i]);
        }

        int totalWaterTrapped = 0;
        for (int i = 0; i < height.length; i++) {
            int waterTrappedAtI = Math.min(maxHeightLeft[i], maxHeightRight[i]) - height[i];
            if (waterTrappedAtI > 0) {
                totalWaterTrapped += waterTrappedAtI;
            }
        }
        return totalWaterTrapped;
    }

    private static void displayArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + ",");
        }
        System.out.println(); 
    }
}
