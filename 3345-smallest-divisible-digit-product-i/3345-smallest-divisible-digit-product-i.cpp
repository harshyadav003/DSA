class Solution {
public:
    int smallestNumber(int n, int t) {
       
        while(true){ 
        int no=n;
        int prd=1; 
        while(no!=0){
            int sn=no%10;
            no=no/10;
            prd*=sn;
        }
        if(prd%t==0){
            return n;
        }
        n++;
        }
    return -1;
    }
};