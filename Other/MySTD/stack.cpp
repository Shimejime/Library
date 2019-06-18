template<class Type> class Stack
{
    private:
        struct Node { Type num; Node *forward; };
        int sz; Node *head;
    public:
        Stack() {sz = 0; head = new Node;}
        void push(Type x)
        {
            Node *n = new Node;
            n->num = x, n->forward = head;
            head = n, sz++;
        }
        Type pop()
        {
            if(size() == 0) return -1;
            Type res = head->num;
            Node *n = head;
            head = n->forward;
            delete n, sz--;
            return res;
        }
        Type top() { if (size() != 0) return head->num; }
        Type size() { return sz; }
};