#include "Binary_Heap.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

//Konstruktor kopca
Binary_Heap::Binary_Heap()
{
    heap = nullptr;
    size=0;
    srand(time(NULL));
}

//Destruktor kopca
Binary_Heap::~Binary_Heap()
{
    free(heap);
}

//Algorytm do kopcowania
void Binary_Heap::heapify(int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left<size && heap[left]>heap[largest])
        largest = left;

    if (right<size && heap[right]>heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

//Kopcowanie od ostatniego rodzica
void Binary_Heap::max_heapify()
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(i);
    }
}

//Dodanie elementu do kopca zachowując warunek kopca
void Binary_Heap::add_node(int v)
{
    add(v);
    max_heapify();
}

//Dodanie elementu do tabicy kopca bez wstawiania go w odpowiednie miejsce (do stworzenia kopca do testowania czasów operacyjnych)
void Binary_Heap::add(int v)
{
    if (!size)
        heap = (int *) realloc(NULL, (size + 1) * sizeof(int));

    else
        heap = (int *) realloc(heap, (size + 1) * sizeof(int));

    heap[size] = v;
    size++;
}

//Usuwanie korzenia z kopca
void Binary_Heap::pop( )
{
    for (int i=0; i < size; i++)
    {
        heap[i] = heap[i+1];
    }
    heap = (int *) realloc(heap, (size - 1) * sizeof(int));
    size--;

    max_heapify();
}

//Wyświetlenie kopca w prostej postaci, kolejne poziomy przedzielone |, a kolejne elementy należące do kolejnego rodzica .
void Binary_Heap::print()
{
    int separator=0, power=0;
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
        if (!i || (separator == pow(2, power)))
        {
            cout << "| ";
            separator = 0;
            power++;
            separator++;
            continue;
        }
        separator++;
        if (!(i%2))
            cout <<". ";
    }
    cout << endl << endl;
}

//Znalazienie pierwszego wystąpienia elementu w kopcu
int Binary_Heap::find_first(int v)
{
    for (int i=0; i < size; i++)
    {
        if(heap[i]==v)
            return i;
    }
    return -1;
}

//Inicjalizacja kopca wartościami losowymi do testowania
void Binary_Heap::initialize(int t)
{
    for (int i = 0; i < t; i++)
    {
        add(rand() % RAND_MAX - (RAND_MAX/2));
    }
    max_heapify();
}

//Usuwanie kopca po zakończeniu na nim testów
void Binary_Heap::delete_heap()
{
    while (size)
        pop();
}

//Testowanie reczne kopca
void Binary_Heap::operate()
{
    int choice;
    bool exit = false;
    do
    {
        cout << "############################## DOSTEPNE OPCJE ##############################" << endl;
        cout << "1 - Dodawanie elementu " << endl;
        cout << "2 - Usuwanie korzenia" << endl;
        cout << "3 - Wyszukanie wartosci" << endl;
        cout << "4 - Wydrukowanie kopca" << endl << endl;

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
                add_node(v);
                print();
                break;
            }

            case 2:
            {
                pop();
                print();
                break;
            }

            case 3:
            {
                int v;
                cout << "Podaj wartosc do wyszukania : ";
                cin >> v;
                cout << endl;
                cout << "Indeks w tablicy wybranego elementu: " << find_first(v) << endl;
                print();
                break;
            }

            case 4:
            {
                print();
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




