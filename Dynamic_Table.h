class Dynamic_Table
{
public:
    int* tab;
    int size;

    Dynamic_Table();
    ~Dynamic_Table();
    void add_last(int v);
    void add_first(int v);
    void add_after(int m, int v);
    void add_before(int m, int v);
    void delete_first();
    void delete_last();
    void delete_index(int m);
    void print_tab();
    int find_first(int v);
    void delete_first_appearance(int v);
    void initialize(int t);
    void delete_table();

    void operate();
};