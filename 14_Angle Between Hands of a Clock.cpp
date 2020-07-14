class Solution {
public:
    double angleClock(int h, int m) {
        if(h==12){
            h=0;
        }
        if(m==60){
            m=0;
            h++;
            if(h>12){
                h=h-12;
            }
        }
        double hAngle=(h*60+m)*0.5;
        double mAngle=m*6;
        double ans=abs(hAngle-mAngle);
        ans=min(360-ans,ans);
        return ans;
    }
};
