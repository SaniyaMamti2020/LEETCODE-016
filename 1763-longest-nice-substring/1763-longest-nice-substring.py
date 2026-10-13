class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        if len(s) < 2:
            return ""

        st = set(s)

        for i in range(len(s)):
            c = s[i]

            if c.lower() in st and c.upper() in st:
                continue

            left = self.longestNiceSubstring(s[:i])
            right = self.longestNiceSubstring(s[i + 1:])

            return left if len(left) >= len(right) else right

        return s