// buy[i] represents What is the net profit you have when you perform buy operation on i'th day.
// Similarly sell[i] and cool[i] denotes profit you earn after performing sell and cool operation on i'th day


class Solution {
public:
    int maxProfit(vector<int>& prices) {

    int n = prices.size();
    vector<int>buy(n+1, INT_MIN) , sell(n+1, 0), cool(n+1, 0);
    
    for (int i =1;i<=n;i++)
    {
        buy[i]=max(buy[i-1], cool[i-1]-prices[i-1]);
        sell[i] = buy[i-1]+prices[i-1];
        cool[i]= max(cool[i-1], sell[i-1]);
    }
    return max(buy[n], max(sell[n], cool[n]));
    }
};
