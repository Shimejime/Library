template<class Type> class MaxHeap
{
    public:
      Type *heap; int sz = 0; MaxHeap(int len)  { heap = new Type[len]; }
      Type& operator[](size_t n) & { return heap[n]; }
      void push(Type x)
      {
          Type nu = sz; sz++;
          while (nu > 0)
          {
              int parent = (nu - 1) / 2;
              if (heap[parent] >= x) break;
              heap[nu] = heap[parent]; nu = parent;
          }
          heap[nu] = x;
      }
      void pop()
      {
          Type x = heap[--sz]; int nu = 0;
          while (nu * 2 + 1 < sz)
          {
              int a = nu * 2 + 1; int b = nu * 2 + 2;
              if (b < sz && heap[b] > heap[a]) a = b;
              if (heap[a] <= x) break;
              heap[nu] = heap[a]; nu = a;
          }
          heap[nu] = x;
      }
      Type top() { return heap[0]; }
};


