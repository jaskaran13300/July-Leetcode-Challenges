class Solution {
public:
    string addBinary(string a, string b) {
        int p=a.size()-1,q=b.size()-1;
        string ans ="";
        int carry = 0;
        while(p>=0 || q>=0 || carry == 1) {
            int m = p>=0 ? (a[p--]-'0') : 0;
            int n = q>=0 ? (b[q--]-'0') : 0;
            int sum  = (m^n^carry);
            carry = m + n + carry >= 2;
            ans = to_string(sum) + ans;
        }
        return ans;
    }
};
