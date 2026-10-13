class Solution:
    def diStringMatch(self, s: str) -> list[int]:
        n = len(s)

        low = 0
        high = n

        perm = []

        for c in s:
            if c == 'I':
                perm.append(low)
                low += 1
            else:  # c == 'D'
                perm.append(high)
                high -= 1

        # Add the last remaining number
        perm.append(low)

        return perm