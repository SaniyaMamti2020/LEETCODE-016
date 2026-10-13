class Solution:
    def longestPalindrome(self, s: str) -> int:
        # Frequency map to store the count of each character
        charCounts = {}

        for c in s:
            charCounts[c] = charCounts.get(c, 0) + 1

        length = 0
        hasOdd = False

        for count in charCounts.values():
            # Add the maximum even part of the frequency
            length += (count // 2) * 2

            # If count is odd, one character can be placed in the center
            if count % 2 != 0:
                hasOdd = True

        # One odd-frequency character can be placed in the center
        if hasOdd:
            length += 1

        return length
