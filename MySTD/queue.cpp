template<class Type> class Queue
{
    private:
        struct Node { Type num; Node *back; };
        Node *head, *tail; int sz;
    public:
        Queue() { head = tail = new Node; sz = 0; }
        void push(Type x)
        {
            Node *n = new Node;
            n->num = x;
            tail->back = n; tail = n;
            if(empty()) head = tail; sz++;
        }
        Type pop()
        {
            Type res = head->num;
            Node *_head = head;
            head = head->back;
            delete _head; sz--;
            return res;
        }
        Type front() { if(not empty()) return head->num; }
        bool empty() { return sz == 0; }
};