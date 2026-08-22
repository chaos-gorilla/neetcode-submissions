class Solution {
    public boolean isAnagram(String s, String t) {
        int[] countsFirst = new int[26];
        int[] countsSecond = new int[26];

        for (char ch : s.toCharArray()) {
            countsFirst[ch - 'a']++;
        }
        for (char ch : t.toCharArray()) {
            countsSecond[ch - 'a']++;
        }
        return Arrays.equals(countsFirst, countsSecond);
    }
}
