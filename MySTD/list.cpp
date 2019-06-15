template<class Type> class List 
{
    struct Node { Type val; Node *next, *pre; };
    Node *origin;
    public:
        List() { origin = new Node; origin->next = origin; origin->pre = origin; }
        Node *find(Type num)
        {
            Node *n = origin->next; while(n != origin && n->val != num) n = n->next;
            return n;
        }
        void push_front(Type num)
        {
            Node *n = new Node;
            n->val = num; n->next = origin->next;
            origin->next->pre = n; origin->next = n;
            n->pre = origin;
        }
        void _erase(Node *n)
        {
            if(n == origin) return;
            n->pre->next = n->next; n->next->pre = n->pre;
            delete n;
        }
        void erase(Type num){ _erase(find(num)); }
        void pop_front() { _erase(origin->next); }
        void pop_back() { _erase(origin->pre); }
        void print()
        {
            Node *n = origin->next;
            bool flag = false;
            while(n != origin)
            {
                if(flag) cout << " " << n->val;
                else cout << n->val, flag = true;
                n = n->next;
            }
            cout << "\n";
        }
};