class Double_Linked_List
{
public:
    struct Node
    {
        Node * next;   // następnik
        Node * prev;   // poprzednik
        int key;
    };
    Node * head;  // początek listy
    Node * tail;  // koniec listy
    unsigned node_counter;  // licznik elementów

    Double_Linked_List( );         // konstruktor
    ~Double_Linked_List( );        // destruktor
    void print_list( );
    void push_front ( int v );
    void push_back ( int v );
    void insert_before (Node * e, int v );
    void insert_after (Node * e, int v );
    void remove (Node * e );
    void pop_front( );
    void pop_back( );
    Node * find_first (int v );
    void initialize(int t);
    void delete_list();

    void operate();
};