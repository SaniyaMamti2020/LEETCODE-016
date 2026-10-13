class Solution:
    def maximum69Number(self, num: int) -> int:
        # Convert the number to a string
        numStr = str(num)

        # Change the first '6' to '9'
        for i in range(len(numStr)):
            if numStr[i] == '6':
                numStr = numStr[:i] + '9' + numStr[i + 1:]
                break

        # Convert back to integer
        return int(numStr)