class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> keyToAnagramsMapping = new HashMap<>();
        for (String str : strs) {
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);
            if (!keyToAnagramsMapping.containsKey(key)) {
                keyToAnagramsMapping.put(key, new ArrayList<>());
            }
            keyToAnagramsMapping.get(key).add(str);
        }
        return new ArrayList<>(keyToAnagramsMapping.values());
    }
}
