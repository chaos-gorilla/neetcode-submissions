class Solution {
    private static String getSanitizedString(String s) {
        StringBuilder builder = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (Character.isLetterOrDigit(ch)) {
                builder.append(ch);
            }
        }
        return builder.toString().toLowerCase();
    }

    public boolean isPalindrome(String s) {
        String sanitisedString = getSanitizedString(s);

        int beginPtr = 0;
        int endPtr = sanitisedString.length() - 1;

        while (beginPtr <= endPtr) {
            if (sanitisedString.charAt(beginPtr) != sanitisedString.charAt(endPtr)) {
                return false;
            } else {
                beginPtr++;
                endPtr--;
            }
        }
        return true;
    }
}
