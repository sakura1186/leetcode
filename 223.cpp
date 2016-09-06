#include "stdio.h"
#include "stdlib.h"


class Solution {
public:
    
    struct P {
        int x;
        int which;
    };
    
    static int cmp( const void *a , const void *b )
    {
        struct P *c = (P *)a;
        struct P *d = (P *)b;
        return c->x - d->x;
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int weight=0, height=0;
        
        weight = cross(A, C, E, G);
        height = cross(B, D, F, H);
        
        int area = (C-A)*(D-B) + (G-E)*(H-F) - weight*height;
        
        return area;
    }
    
    int cross(int x1, int x2, int y1, int y2) {
        
        P poi[4];
        poi[0].x = x1;
        poi[1].x = x2;
        poi[2].x = y1;
        poi[3].x = y2;
        
        poi[0].which = 1;
        poi[1].which = 1;
        poi[2].which = 2;
        poi[3].which = 2;
        
        qsort(poi,4,sizeof(poi[0]),this->cmp);
        
        if (poi[0].which == poi[1].which) {
            return 0;
        }else {
            return poi[2].x - poi[1].x;
        }
        
        
    }
    
};

int main() {
    Solution *s = new Solution();
    int ans;
    ans = s->computeArea(0,0,0,0,-1,-1,1,1);
    printf("%d\n", ans);
}


