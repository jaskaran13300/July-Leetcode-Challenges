class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        N=N%14;
        if(N==0){
            N=14;
        }
        vector<int>temp;
        for(int j=0;j<N;j++){
            print(cells);
            temp.clear();
            temp.push_back(0);
            for(int i=1;i<7;i++){
                if((cells[i-1]^cells[i+1])==0){
                    temp.push_back(1);
                }
                else{
                    temp.push_back(0);
                }
            }
            cells.clear();
            temp.push_back(0);
            cells=temp;
        }
        return temp;
    }
};
