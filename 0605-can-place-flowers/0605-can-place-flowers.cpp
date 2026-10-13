class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        for (int i = 0; i < size; ++i) {
            // Early exit if we have already planted all required flowers
            if (n <= 0) {
                return true;
            }
            
            // Check if the current plot, the left plot, and the right plot are all empty
            if (flowerbed[i] == 0) {
                bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);
                
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1; // Plant a flower
                    n--;              // Reduce the count of flowers left to plant
                }
            }
        }
        
        return n <= 0;
    }
};