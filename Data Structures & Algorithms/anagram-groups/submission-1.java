class NormalizedKey {
    String originalKey;
    int[] charCounts;
    
    NormalizedKey(String key) {
        this.originalKey = key;
        this.charCounts = new int[26];
        this.evaluateCharacterCounts();
    }

    private void evaluateCharacterCounts() {
        for (char ch : originalKey.toCharArray()) {
            this.charCounts[ch - 'a']++;
        }
    }

    public String getKeyCountsRepresentations() {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            builder.append(i + 'a');
            builder.append(charCounts[i]);
        }
        return builder.toString();
    }
}

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        // We maintain a frequency array with strings.
        Map<String, List<String>> anagramsCollections = new TreeMap<>();
        for (String str : strs) {
            NormalizedKey normalizedKey = new NormalizedKey(str);
            String charCountRepresentation = normalizedKey.getKeyCountsRepresentations();
            anagramsCollections.computeIfAbsent(charCountRepresentation, (k) -> new ArrayList<>()).add(str);
        }
        return new ArrayList<>(anagramsCollections.values());
    }
}
