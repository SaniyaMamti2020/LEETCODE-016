class Solution:
    def balancedStringSplit(self, s: str) -> int:
        balance = 0
        max_splits = 0

        for c in s:
            if c == 'R':
                balance += 1
            else:
                balance -= 1

            if balance == 0:
                max_splits += 1

        return max_splits