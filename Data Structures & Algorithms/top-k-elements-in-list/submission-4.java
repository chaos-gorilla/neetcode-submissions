class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> countOfElements = new HashMap<>();
        for (int num : nums) {
            if (!countOfElements.containsKey(num)) {
                countOfElements.put(num, 0);
            }
            countOfElements.put(num, countOfElements.get(num) + 1);
        }

        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(countOfElements.entrySet());
        list.sort(Map.Entry.comparingByValue(Comparator.reverseOrder()));

        int[] kElements = new int[k];
        for (int i = 0; i < k; i++) {
            kElements[i] = list.get(i).getKey();
        }

        return kElements;
    }
}
