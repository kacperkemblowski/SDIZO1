#include <iostream>
#include "Double_Linked_List.h"

using namespace std;

//Konstruktor listy
Double_Linked_List::Double_Linked_List( )
{
    head  = tail  = nullptr;
    node_counter = 0;
}

// Destruktor listy
Double_Linked_List::~Double_Linked_List( )
{
    while( node_counter ) pop_front( );
}

// Wyświetla zawartość elementów listy
//----------------------------------------------
void Double_Linked_List::print_list( )
{
    Node * p;
    p = head;
    while( p )
    {
        cout << p->key ;
        if(p->next)
            cout << " <-> ";
        p = p->next;
    }
    cout << endl;
}

// Dodanie nowego elementu na początek listy
void Double_Linked_List::push_front (int v )
{
    Node * p;

    p = new Node;
    p->key = v;
    p->prev = nullptr;
    p->next = head;
    head  = p;
    node_counter++;
    if( p->next ) p->next->prev = p;
    else tail = p;
}

// Dodanie nowego elementu na koniec listy
void Double_Linked_List::push_back (int v )
{
    Node * p;

    p = new Node;
    p->key = v;
    p->next = nullptr;
    p->prev = tail;
    tail  = p;
    node_counter++;
    if( p->prev ) p->prev->next = p;
    else head = p;
}

// Dodanie nowego elementu przed wybranym
void Double_Linked_List::insert_before (Node * e, int v )
{
    Node * p;

    if( e == head ) push_front ( v );
    else
    {
        p = new Node;
        p->key = v;
        p->next = e;
        p->prev = e->prev;
        node_counter++;
        e->prev->next = p;
        e->prev = p;
    }
}

// Dodanie nowego elementu za wybranym
void Double_Linked_List::insert_after (Node * e, int v )
{
    Node * p;
    if (e) {
        if (e == tail) push_back(v);
        else {
            p = new Node;
            p->key = v;
            p->next = e->next;
            p->prev = e;
            node_counter++;
            e->next->prev = p;
            e->next = p;
        }
    }
}

// Usuwanie wybranego elementu z listy
void Double_Linked_List::remove (Node * e )
{
    if(e) {
        node_counter--;
        if (e->prev) e->prev->next = e->next;
        else head = e->next;
        if (e->next) e->next->prev = e->prev;
        else tail = e->prev;
        delete e;
    }
}

// Usuwanie elementu z początku listy
void Double_Linked_List::pop_front( )
{
    if( node_counter ) remove (head );
}

// Usuwanie elementu z końca listy
void Double_Linked_List::pop_back( )
{
    if( node_counter ) remove (tail );
}

// Wyszukanie pierwszego wystąpienia elementu v
Double_Linked_List::Node * Double_Linked_List::find_first (int v )
{
    Node * p;
    push_back ( v );
    p = head;
    while(p->key != v ) p = p->next;
    if( p == tail ) p = nullptr;
    pop_back( );
    return p;
}

//Inicjalizacja listy wartościami losowymi do testowania
void Double_Linked_List::initialize(int t)
{
    srand(time(NULL));
    for (int i = 0; i < t; i++)
    {
        push_front(rand() % RAND_MAX - (RAND_MAX/2));
    }
}

//Usuwanie listy po zakończeniu na niej testów
void Double_Linked_List::delete_list()
{
    while (node_counter)
        pop_front();
}

//Testowanie reczne listy
void Double_Linked_List::operate()
{
    int choice;
    bool exit = false;
    do
    {
        cout << "############################## DOSTEPNE OPCJE ##############################" << endl;
        cout << "1 - Dodawanie elementu na poczatek" << endl;
        cout << "2 - Dodawanie elementu na koniec" << endl;
        cout << "3 - Dodawanie elementu po wybranym miejscu w tablicy" << endl ;
        cout << "4 - Dodawanie elementu przed wybranym miejscem w tablicy" << endl;
        cout << "5 - Usuwanie elementu z poczatku" << endl;
        cout << "6 - Usuwanie elementu z konca" << endl;
        cout << "7 - Usuwanie elementu o wybranej wartosci " << endl;
        cout << "8 - Wyszukanie pierwszego wystapienia elementu" << endl;
        cout << "9 - Wydrukowanie zawartosci listy" << endl << endl;

        cout << "0 - Wyjscie z programu" << endl;

        cout << endl << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                int v;
                cout << "Podaj wartosc do wstawienia : ";
                cin >> v;
                cout << endl;
                push_front(v);
                print_list();
                break;
            }

            case 2:
            {
                int v;
                cout << "Podaj wartosc do wstawienia : ";
                cin >> v;
                cout << endl;
                push_back(v);
                print_list();
                break;
            }

            case 3:
            {
                int v, e;
                cout << "Podaj wartosc do wstawienia : ";
                cin >> v;
                cout << endl << "Podaj wartosc elementu po ktorym chcesz wstawic element";
                cin >> e;
                cout << endl;
                insert_after(find_first(e), v);
                print_list();
                break;
            }

            case 4:
            {
                int v, e;
                cout << "Podaj wartosc do wstawienia : ";
                cin >> v;
                cout << endl << "Podaj wartosc elementu po ktorym chcesz wstawic element";
                cin >> e;
                cout << endl;
                insert_before(find_first(e), v);
                print_list();
                break;
            }

            case 5:
            {
                pop_front();
                print_list();
                break;
            }

            case 6:
            {
                pop_back();
                print_list();
                break;
            }

            case 7:
            {
                int v;
                cout << endl << "Podaj wartosc elementu, ktory chcesz usunac";
                cin >> v;
                cout << endl;
                remove(find_first(v));
                print_list();
                break;
            }

            case 8:
            {
                int v;
                cout << "Podaj wartosc, ktora chcesz znalezc: ";
                cin >> v;
                cout << endl;
                cout << "Miejsce w pamieci wybranego elementu: "<< find_first(v) << endl;
                break;
            }

            case 9:
            {
                print_list();
                break;
            }

            case 0:
            {
                exit = true;
                cout << "Wychodzenie z programu" << endl;
                break;
            }

            default:
                cout << "Brak wybranej opcji!" << endl << endl;
                break;
        }
        system("PAUSE");
    }

    while(!exit);
}