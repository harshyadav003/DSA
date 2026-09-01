// class Solution {
// public:
    
//     double myPow(double x, int n) {
//        double ans=1;
           
//            if(n==0 ) return 1 ;
//            long long temp=n;
//         if(temp<0){
//             x=1/x;
//             temp=-temp;      
//         }
//         for(long long i=0;i<temp;i++){
//             ans*=x;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    double helper(double x,int n){
        if(n==0) return 1;
        if(n==1) return x;
         long long temp=n;
        if(temp<0){
            x=1/x;
            temp=-temp;      
        }
        
        if(temp%2==1) return x*helper(x,temp-1);
        else  return helper(x*x,temp/2);
    }
    double myPow(double x, int n) {
       return helper(x,n);
    }
};