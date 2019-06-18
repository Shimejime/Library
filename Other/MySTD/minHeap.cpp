template<class Type> class MinHeap
{
    public:
      Type *heap;
      int sz = 0;
      MinHeap(int len) { heap = new Type[len]; }
      void push(Type x)
      {
          Type nu = sz++;
          while (nu > 0)
          {
              int p = (nu - 1) / 2;
              if (heap[p] <= x) break;
              heap[nu] = heap[p]; nu = p;
          }
          heap[nu] = x;
      }
      void pop()
      {
          Type x = heap[--sz]; int nu = 0;
          while (nu * 2 + 1 < sz)
          {
              int a = nu * 2 + 1; int b = nu * 2 + 2;
              if (b < sz && heap[b] < heap[a]) a = b;
              if (heap[a] >= x) break;
              heap[nu] = heap[a]; nu = a;
          }
          heap[nu] = x;
      }
      Type top() { return heap[0]; }
};


