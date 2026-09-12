class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            # Check if the token is a number (handles negative numbers too)
            if token.lstrip('-').isdigit():
                stack.append(int(token))
            else:
                bottom = stack.pop()
                top = stack.pop()
                
                if token == '+':
                    stack.append(top + bottom)
                elif token == '-':
                    stack.append(top - bottom)
                elif token == '*':
                    stack.append(top * bottom)
                else:
                    # Truncate toward zero for division
                    stack.append(int(top / bottom))
                    
        return stack[-1]