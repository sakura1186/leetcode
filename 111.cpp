#include "stdio.h"
#include "stdlib.h"
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    Solution():level(1) {}
    
    deque<TreeNode *> queue;
    
    int level;
    
    int minDepth(TreeNode* root) {
        
        if (root == NULL) {
            return 0;
        }
        queue.push_back(root);
        return bfs();
    }
    
    int bfs() {
        
        TreeNode * tmp;
        unsigned long num = queue.size();
        
        for (int i = 0; i<num; i++) {
            tmp = queue[0];
            if (tmp->left == NULL && tmp->right == NULL) {
                return level;
            }else {
                
                if(tmp->left!=NULL) {
                    queue.push_back(tmp->left);
                }
                if(tmp->right!=NULL) {
                    queue.push_back(tmp->right);
                }
            }
        
            queue.pop_front();
        }
        
        level++;
        
        return bfs();
    }
    

    
};

int main() {
    Solution *s = new Solution();
    int ans;
    ans = s->minDepth(NULL);
    printf("%d\n", ans);
}


