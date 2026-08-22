class Solution {

    public String encode(List<String> strs) {
        StringBuilder builder = new StringBuilder();
        for (String s : strs) {
            int length = s.length();
            builder.append(length);
            builder.append("😎");
            builder.append(s);
            builder.append("❤️");
        }
        return builder.toString();
    }

    public List<String> decode(String str) {
        String[] parts = str.split("❤️");
        List<String> result = new ArrayList<>();
        if (str.isEmpty()) {
            return result;
        }
        for (String part : parts) {
            String[] subParts = part.split("😎");
            int totalChars = Integer.parseInt(subParts[0]);
            if (totalChars == 0) {
                result.add("");
            } else {
                result.add(subParts[1]);
            }
        }
        return result;
    }
}
