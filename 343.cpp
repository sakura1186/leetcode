#include "stdio.h"

#define M 16

class Solution {
public:
    int integerBreak(int n) {
        

        int dui[M];
        
        int sum=1,res=0;
        
        for (int part = 2;part<=M;part++){
            
            sum =1;
        
            for(int i=0;i<M;i++){
                dui[i]=0;
            }
        
            int p=0;
            for (int i=0;i<n;i++){
            
                dui[p++]++;
                if(p>=part){
                    p=0;
                }
            
            }
        
            for (int i=0;i<part;i++){
                sum*=dui[i];
            }
        
            if(sum>res){
                res= sum;
            }
        }
        
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    int ans;
    ans = s->integerBreak(14);
    printf("%d\n", ans);
}


