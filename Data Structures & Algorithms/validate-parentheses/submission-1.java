class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack();
        // push, pop(), peek(), empty()
        HashMap<Character, Character> matchingBracket = new HashMap<>(
            Map.of('}', '{', ')', '(', ']', '[')
        );
        for (char ch : s.toCharArray()) {
            if (isOpeningBracket(ch)) {
                st.add(ch);
            } else {
                if (st.isEmpty()) {
                    return false;
                }
                if (st.peek() != matchingBracket.get(ch)) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.isEmpty();
    }
    
    private boolean isOpeningBracket(char ch) {
        return ch == '{' || ch == '(' || ch == '[';
    }
}
