class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c in ")}]" and len(stack) == 0:
                return False

            if c == ')' and stack[-1] == '(':
                stack.pop()
                continue

            elif c == '}' and stack[-1] == '{':
                stack.pop()
                continue

            elif c == ']' and stack[-1] == '[':
                stack.pop()
                continue

            else:
                stack.append(c)
        return True if not stack else False