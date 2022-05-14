class Binary_Heap
{
public:
    int* heap;
    int size;

    Binary_Heap();
    ~Binary_Heap();
    void heapify(int i);
    void max_heapify();
    void add(int v);
    void add_node(int v);
    void pop();
    void print();
    int find_first(int v);
    void initialize(int t);
    void delete_heap();

    void operate();
};
