class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> numberCounts = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int number = nums[i];
            int totalOccurrence = numberCounts.getOrDefault(number, 0);
            numberCounts.put(number, totalOccurrence + 1);
        }

        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>(Map.Entry.comparingByValue(Comparator.reverseOrder()));
        pq.addAll(numberCounts.entrySet());
        int[] results = new int[k];
        for (int i = 0; i < k; i++) {
            results[i] = pq.poll().getKey();;
        }
        return results;
    }
}
