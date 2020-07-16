// how can we evaluate x^20? We can just multiply x in loop 20 times
// but we also can evaluate x^10 and multiply it by itself!
// Similarly, x^10 = x^5 * x^5.
// Now we have odd power, but it is not a problem, we evaluate x^5 = x^2 * x^2 * x

class Solution {
public:
    double myPow(double x, int y) {
        double temp;  
        if(y == 0)  
            return 1;  
        temp = myPow(x, y / 2);  
        if (y % 2 == 0)  
            return temp * temp;  
        else
        {  
            if(y > 0)  
                return x * temp * temp;  
            else
                return (temp * temp) / x;  
        }  
    }
};
