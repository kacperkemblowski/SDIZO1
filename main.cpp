#include "Dynamic_Table.h"
#include "Double_Linked_List.h"
#include "Binary_Heap.h"
#include "Counter.h"
#include <iostream>

using namespace std;

int main( )
{
    int choice;

    cout << "############################## DOSTEPNE STRUKTURY DANYCH ##############################" << endl;
    cout << "1 - Lista dwukierunkowa " << endl;
    cout << "2 - Tablica dynamiczna" << endl;
    cout << "3 - Kopiec binarny" << endl << endl;
    cout << "4 - Pomiary czasu" << endl << endl;
    cout << "Dowolny inny przycisk - wyjscie z programu" << endl;
    cout << endl << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            Double_Linked_List dll;
            dll.operate();
            break;
        }

        case 2:
        {
            Dynamic_Table dt;
            dt.operate();
            break;
        }

        case 3:
        {
            Binary_Heap bh;
            bh.operate();
            break;
        }

        case 4:
        {
            Counter c;
            c.count_time();
            break;
        }

        default:
            cout << "Wychodzenie z programu" << endl << endl;
            system("PAUSE");
            break;
    }
}