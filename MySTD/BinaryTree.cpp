//insert, find, removeでroot指定するの忘れず
template<class Type> class BinaryTree
{
    struct Node { Type val; Node *left, *right; };
    public:
        Node *root = nullptr;
        Node *insert(Node *p, Type x)
        {
            if(p == nullptr) { Node *q = new Node; q->val = x; q->left = q->right = nullptr; if(root == nullptr) root = q; return q; }
            else { if(x < p->val) p->left = insert(p->left, x); else p->right = insert(p->right, x); return p; }
        }
        bool find(Node *p, Type x)
        {
            if(p == nullptr) return false;
            else if(x == p->val) return true;
            else if(x < p->val) return find(p->left, x);
            else return find(p->right, x);
        }
        Node *remove(Node *p, Type x)
        {
            if(p == nullptr) return nullptr;
            else if(x < p->val) p->left = remove(p->left, x);
            else if(x > p->val) p->right = remove(p->right, x);
            else if(p->left == nullptr && p->right == nullptr) { delete p; return nullptr; }
            else if(p->right == nullptr) { Node *q = p->left; delete p; return q; }
            else if(p->left == nullptr) { Node *q = p->right; delete p; return q; }
            else if(p->right->left == nullptr) { Node *q = p->right; q->left = p->left; delete p; return q; }
            else
            {
                Node *q;
                for(q = p->right; q->left->left != nullptr; q = q->left);
                Node *r = q->left;
                q->left = r->right;
                r->left = p->left, r->right = p->right;
                delete p;
                return r;
            }
            return p;
        }
        void print() { inorder(root); cout << "\n"; preorder(root); cout << "\n"; }
        void inorder(Node *p) { if(p->left != nullptr) inorder(p->left); cout << " " << p->val;if(p->right != nullptr) inorder(p->right); }
        void preorder(Node *p) { cout << " " << p->val; if(p->left != nullptr) preorder(p->left); if(p->right != nullptr) preorder(p->right); }
};
