#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
template<class Type> class Treap
{
   public:
       struct Node
       {
           Type key, pri;
           Node *left, *right;
       };
       Node *rightRotate(Node *u)
       {
           Node *q = u->left;
           u->left = q->right;
           q->right = u;
           return q;
       }
       Node *leftRotate(Node *u)
       {
           Node *q = u->right;
           u->right = q->left;
           q->left = u;
           return q;
       }
       Node *insert(Node *u, Type key, Type p)
       {
           if(u == nullptr)
           {
               Node *q = new Node;
               q->key = key;
               q->pri = p;
               q->left = nullptr, q->right = nullptr;
               return q;
           }
           else
           {
               if(key < u->key)
               {
                   u->left = insert(u->left, key, p);
                   if(u->left->pri > u->pri) u = rightRotate(u);
               }
               else 
               {
                   u->right = insert(u->right, key, p);
                   if(u->right->pri > u->pri) u = leftRotate(u);
               }
               return u;
           }
       }
       bool find(Node *u, Type key)
       {
           if(u == nullptr) return false;
           else if(key == u->key) return true;
           else if(key < u->key) return find(u->left, key);
           else return find(u->right, key); 
       }
       Node *remove(Node *u, Type key)
       {
           if(u == nullptr) return nullptr;
           if(key < u->key) u->left = remove(u->left, key);
           else if(key > u->key) u->right = remove(u->right, key);
           else return _remove(u, key);
           return u;
       }
       Node *_remove(Node *u, Type key)
       {
           if(u->left == nullptr && u->right == nullptr) return nullptr;
           else if(u->left == nullptr) u = leftRotate(u);
           else if(u->right == nullptr) u = rightRotate(u);
           else if(u->left->pri > u->right->pri) u = rightRotate(u);
           else u = leftRotate(u);
           return remove(u, key);
       }
       void print(Node *u)
       {
           inorder(u); cout << endl;
           preorder(u); cout << endl;
       }
       void inorder(Node *u)
       {
           if(u->left != nullptr) inorder(u->left);
           cout << " " << u->key;
           if(u->right != nullptr) inorder(u->right);
       }
       void preorder(Node *u)
       {
           cout << " " << u->key; 
           if(u->left != nullptr) preorder(u->left);
           if(u->right != nullptr) preorder(u->right);
       }
};
int main()
{
    int n; cin >> n;
    Treap<int> T;
    Treap<int>::Node *root = nullptr;
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        if(s == "insert")
        {
            int key, pri; cin >> key >> pri;
            root = T.insert(root, key, pri);
        }
        if(s == "find")
        {
            int key; cin >> key;
            cout << (T.find(root, key) ? "yes" : "no") << endl;
        }
        if(s == "delete")
        {
            int key, pri; cin >> key;
            root = T.remove(root, key);
        }
        if(s == "print") T.print(root);
    }
    return 0;
}

