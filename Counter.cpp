#include "Counter.h"
#include "Binary_Heap.h"
#include "Double_Linked_List.h"
#include "Dynamic_Table.h"
#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

long long int Counter::read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

//Przeprowadzanie pomiarów czasu wykonwania operacji
void Counter::count_time()
{
    Binary_Heap bh;
    Double_Linked_List dll;
    Dynamic_Table dt;
    srand(time(NULL));
    long long int frequency, start, elapsed, mean_time;
    long long int total_time = 0;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);


    //dt.initialize(50000);
    //dll.initialize(50000);
    bh.initialize(50000);

    //Pętla do przeprowadzenia 100 pomiarów czasu i obliczenia średniego czasu wykonania operacji
    for (int i = 0; i < 100; ++i)
    {
        start = read_QPC();
        bh.add_node(rand() % RAND_MAX - (RAND_MAX/2));
                                //miejsce na kod do zmierzenia czasu

        elapsed = read_QPC() - start;
        total_time += (1000000000.0 * elapsed) /frequency;
    }

    //dt.delete_table();
    //dll.delete_list();
    bh.delete_heap();

    mean_time = total_time/100;

    cout << "Sredni czas ze 100 pomiarow [ns] = " << fixed << setprecision(0) << mean_time << endl << endl;
    system("PAUSE");
}