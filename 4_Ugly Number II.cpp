class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        vector<int>arr(n,1);
        int i2=0,i3=0,i5=0;
        for(int i=1;i<n;i++){
            int ugly_no=min({arr[i2]*2,arr[i3]*3,arr[i5]*5});
            if(ugly_no==arr[i2]*2){
                i2++;
            }
            if(ugly_no==arr[i3]*3){
                i3++;
            }
            if(ugly_no==arr[i5]*5){
                i5++;
            }
            arr[i]=ugly_no;
        }
        return arr[n-1];
    }
};
