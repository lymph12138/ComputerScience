/*
There is a kind of balanced binary search tree named red-black tree in the data structure.
It has the following 5 properties:
(1) Every node is either red or black.
(2) The root is black.
(3) Every leaf (NULL) is black.
(4) If a node is red, then both its children are black.
(5) For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
For example, the tree in Figure 1 is a red-black tree, while the ones in Figure 2 and 3 are not.
         (7b)                           (11b)                          (10b)   
          /\                             /\                              /\
   (2r)        (11r)              (2r)        (14r)              (7r)         (15b)          
    /\          /\                 /\          /\                 /\           /\
(1b)  (5b)  (8b)  (14b)        (1b)  (7r)        (15r)        (5b)  (8b)  (11r)  (17b)                     
       /             \                /\                        \                 
   (4r)               (15r)       (5b)  (8b)                    (6r)
                                   /                            
                                (4r)                          
       Figure 1	                      Figure 2	                      Figure 3
For each given binary search tree, you are supposed to tell if it is a legal red-black tree.
Input Specification:
Each input file contains several test cases. The first line gives a positive integer K (≤30) 
which is the total number of cases. For each case, the first line gives a positive integer N (≤30),
the total number of nodes in the binary tree. The second line gives the preorder traversal sequence of the tree.
While all the keys in a tree are positive integers, we use negative signs to represent red nodes.
All the numbers in a line are separated by a space.
The sample input cases correspond to the trees shown in Figure 1, 2 and 3.
Output Specification:
For each test case, print in a line "Yes" if the given tree is a red-black tree, or "No" if not.
Sample Input:
3
9
7 -2 1 5 -4 -11 8 14 -15
9
11 -2 1 -7 5 -4 8 14 -15
8
10 -7 5 -6 8 15 -11 17
Sample Output:
Yes
No
No
*/
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector <int> arr;
struct node
{
    int value;
    struct node *left, *right;
};
node* bulid(node *root, int v)
{
    if(root == NULL)
    {
        root = new node();
        root->value = v;
        root->left = NULL;
        root->right = NULL;
    }
    else if(abs(root->value) >= abs(v))
        root->left = bulid(root->left, v);
    else
        root->right = bulid(root->right, v);
    return root;
}
bool judge1(node *root)
{
    if(root == NULL)
        return true;
    if(root->value < 0)
    {
        if(root->left!=NULL && root->left->value<0)
            return false;
        if(root->right!=NULL && root->right->value<0)
            return false;
    }
    return judge1(root->left) && judge1(root->right);
}
int getblacknum(node *root)
{
    if(root == NULL)
        return 0;
    int l = getblacknum(root->left);
    int r = getblacknum(root->right);
    return root->value>0 ? max(l, r)+1 : max(l, r);
}
bool judge2(node *root)
{
    if(root == NULL)
        return true;
    int l = getblacknum(root->left);
    int r = getblacknum(root->right);
    if(l != r)
        return false;
    return judge2(root->left) && judge2(root->right);
}
int main()
{
    int K;
    scanf("%d", &K);
    for(int i=0; i<K; i++)
    {
        int N;
        node *root = NULL;
        scanf("%d", &N);
        arr.resize(N);
        for(int j=0; j<N; j++)
        {
            scanf("%d", &arr[j]);
            root = bulid(root, arr[j]);
        }
        if(judge1(root)==false || judge2(root)==false || arr[0]<0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    
    return 0;
}