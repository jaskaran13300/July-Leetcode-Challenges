
// n = 8

// The coins can form the following rows:
// ¤
// ¤ ¤
// ¤ ¤ ¤
// ¤ ¤



// Complexity O(n)

class Solution {
public:
    int arrangeCoins(int n) {
        long long int s=0,k=1,i=0;
        for(i=0;i<n;i++){
            if(s>=n){
                return i;
            }
            k++;
            s=s+k;
        }
        return i;
    }
};


// Another Method
// Complexity O(1)
// As a reminder, the constraint of the problem can be expressed as follows:
// k(k+1)≤2N

// This could be solved by completing the square technique
// (k+1/2)^2-1/4 <= 2N
// k=sqrt(2N+1/4)-1/2

// java soln
class Solution {
  public int arrangeCoins(int n) {
    return (int)(Math.sqrt(2 * (long)n + 0.25) - 0.5);
  }
}
