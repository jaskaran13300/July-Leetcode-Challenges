// Input: x = 1, y = 4

// Output: 2

// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x^y); // count number of set bits by xor
    }
};
