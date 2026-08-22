class Solution {

    public String encode(List<String> strs) {
        StringBuilder builder = new StringBuilder();
        for (String str : strs) {
            String lengthOfString = String.valueOf(str.length());
            builder.append(lengthOfString);
            builder.append("#");
            builder.append(str);
        }
        String encodedString = builder.toString();
        return encodedString;
    }

    public List<String> decode(String str) {
        List<String> decodedStrings = new ArrayList<>();
        char[] characterArray = str.toCharArray();

        StringBuilder numberOfCharactersToGet = new StringBuilder();
        for (int position = 0; position < characterArray.length;) {
            char charAtPosition = characterArray[position];
            if (Character.isDigit(charAtPosition)) {
                numberOfCharactersToGet.append(charAtPosition);
                position++;
            } else if (charAtPosition == '#') {
                int totalCharsToGet = Integer.parseInt(numberOfCharactersToGet.toString());
                String subString = getStringOfKCharactersFromIndex(str, position + 1, totalCharsToGet);
                decodedStrings.add(subString);
                position = position + 1 + totalCharsToGet;
                numberOfCharactersToGet = new StringBuilder();
            }
        }
        return decodedStrings;
    }

    private String getStringOfKCharactersFromIndex(String encodedString, int indexToGetFrom, int totalCharacters) {
        return encodedString.substring(indexToGetFrom, indexToGetFrom + totalCharacters);
    }
}
