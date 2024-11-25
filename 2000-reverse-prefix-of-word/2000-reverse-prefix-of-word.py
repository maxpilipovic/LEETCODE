class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:


        stack = []
        count = 1
        for i in range(len(word)):

            if ch == word[i] and count != 0:
                pointer = i
                stack.append(word[i])
                stack.reverse()
                count -= 1
            else:
                stack.append(word[i])

        return "".join(str(item) for item in stack)
        