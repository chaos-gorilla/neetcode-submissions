class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        result = 0
        for token in tokens:
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
                    stack.append(int(top / bottom))
            
        return stack[-1]
