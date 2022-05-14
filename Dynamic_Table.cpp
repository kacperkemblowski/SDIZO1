#include <cstdlib>
#include <iostream>
#include "Dynamic_Table.h"

using namespace std;

//Konstruktor tablicy
Dynamic_Table::Dynamic_Table()
{
    tab = nullptr;
    size=0;
}

//Destruktor tablicy
Dynamic_Table::~Dynamic_Table()
{
    free(tab);
}

//Dodanie elementu na koniec tablicy
void Dynamic_Table::add_last(int v)
{
    tab = (int *) realloc(tab, (size + 1) * sizeof(int));
    tab[size]=v;
    size++;
}

//Dodanie elementu na początek tablicy
void Dynamic_Table::add_first(int v)
{
    if (!size)
    {
        tab = (int *) realloc(NULL, (size + 1) * sizeof(int));
    }
    else
    {
        tab = (int *) realloc(tab, (size + 1) * sizeof(int));
        for (int i=size; i >= 0; i--)
        {
            tab[i+1] = tab[i];
        }
    }

    tab[0]=v;
    size++;
}

//Dodanie elementu po wybranym miejscu w tablicy
void Dynamic_Table::add_after(int m, int v)
{
    if(m > (-1) && m < size) {
        tab = (int *) realloc(tab, (size + 1) * sizeof(int));
        for (int i = size; i >= m; i--) {
            tab[i + 1] = tab[i];
        }
        tab[m] = v;
        size++;
    }
}

//Dodanie elementu przed wybranym miejscem w tablicy
void Dynamic_Table::add_before(int m, int v)
{
    if(m > -1 && m < size)
    {
        tab = (int *) realloc(tab, (size + 1) * sizeof(int));
        for (int i=size; i >= m - 1; i--)
        {
            tab[i+1] = tab[i];
        }
        tab[m-1]=v;
        size++;
    }
}

//Usunięcie pierwszego elementu z tablicy
void Dynamic_Table::delete_first()
{
    if(size)
    {
        for (int i=0; i < size; i++)
        {
            tab[i] = tab[i+1];
        }
        tab = (int *) realloc(tab, (size - 1) * sizeof(int));
        size--;
    }
}

//Usunięcie ostatniego elementu z tablicy
void Dynamic_Table::delete_last()
{
    if(size)
    {
        tab = (int *) realloc(tab, (size - 1) * sizeof(int));
        size--;
    }
}

//Usunięcie elementu na wybranym miejscu w tablicy
void Dynamic_Table::delete_index(int m)
{
    if(m > -1 && m < size)
    {
        for (int i=m; i < size; i++)
        {
            tab[i] = tab[i+1];
        }
        tab = (int *) realloc(tab, (size - 1) * sizeof(int));
        size--;
    }
}

//Wypisanie elementów tablicy
void Dynamic_Table::print_tab()
{
    for (int i=0; i < size; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl << endl;
}

//Wyszukiwanie pierwszego wystąpienia elementu w tablicy
int Dynamic_Table::find_first(int v)
{
    for (int i=0; i < size; i++)
    {
        if(tab[i]==v)
            return i;
    }
    return -1;
}

//Usuwanie pierwszego wystąpienia elementu w tablicy
void Dynamic_Table::delete_first_appearance(int v)
{
    delete_index(find_first(v));
}

//Inicjalizacja tablicy wartościami losowymi do testowania
void Dynamic_Table::initialize(int t)
{
    srand(time(NULL));
    for (int i = 0; i < t; ++i)
    {
        add_last(rand() % RAND_MAX - (RAND_MAX/2));
    }
}

//Usuwanie tablicy po zakończeniu na niej testów
void Dynamic_Table::delete_table()
{
    while (size)
        delete_first();
}

//Testowanie reczne tablicy
void Dynamic_Table::operate()
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
        cout << "7 - Usuwanie elementu na wybranym miejscu " << endl;
        cout << "8 - Usuwanie pierwszego wystapienia elementu" << endl;
        cout << "9 - Wyszukanie pierwszego wystapienia elementu" << endl;
        cout << "10 - Wydrukowanie zawartosci tablicy" << endl << endl;

        cout << "0 - wyjscie z programu" << endl;

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
                add_first(v);
                print_tab();
                break;
            }

            case 2:
            {
                int v;
                cout << "Podaj wartosc do wstawienia: ";
                cin >> v;
                cout << endl;
                add_last(v);
                print_tab();
                break;
            }

            case 3:
            {
                int v,m;
                cout << "Podaj wartosc do wstawienia : ";
                cin >> v;
                cout << endl << "Podaj index w tablicy po ktorym chcesz wstawic element";
                cin >> m;
                cout << endl;
                add_after(m, v);
                print_tab();
                break;
            }

            case 4:
            {
                int v,m;
                cout << "Podaj wartosc do wstawienia : ";
                cin >> v;
                cout << endl << "Podaj index w tablicy przed ktorym chcesz wstawic element";
                cin >> m;
                cout << endl;
                add_before(m, v);
                print_tab();
                break;
            }

            case 5:
            {
                delete_first();
                print_tab();
                break;
            }

            case 6:
            {
                delete_last();
                print_tab();
                break;
            }

            case 7:
            {
                int m;
                cout << endl << "Podaj indeks w tablicy z ktorego chcesz usunac element";
                cin >> m;
                cout << endl;
                delete_index(m);
                print_tab();
                break;
            }

            case 8:
            {
                int v;
                cout << "Podaj wartosc, ktorej pierwsze wystapienie chcesz usunac: ";
                cin >> v;
                cout << endl;
                delete_first_appearance(v);
                print_tab();
                break;
            }

            case 9:
            {
                int v;
                cout << "Podaj wartosc, ktora chcesz znalezc: ";
                cin >> v;
                cout << endl;
                cout << "Indeks w tablicy wybranego elementu: " << find_first(v) << endl;
                break;
            }

            case 10:
            {
                print_tab();
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