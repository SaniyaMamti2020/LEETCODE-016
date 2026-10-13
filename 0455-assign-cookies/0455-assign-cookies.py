class Solution:
    def findContentChildren(self, g: list[int], s: list[int]) -> int:
        # Sort both greed factors and cookie sizes
        g.sort()
        s.sort()

        child_i = 0
        cookie_j = 0

        # Loop until we run out of children or cookies
        while child_i < len(g) and cookie_j < len(s):

            # If the current cookie can satisfy the current child
            if s[cookie_j] >= g[child_i]:
                child_i += 1  # Move to the next child

            # Always move to the next cookie
            cookie_j += 1

        # Number of content children
        return child_i