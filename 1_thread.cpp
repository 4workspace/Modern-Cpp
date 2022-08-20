/*
    "thread" allows tasks to be executed concurrency.

    - Below are 2 "for" loops that are executed simultaneously and each loop takes 5 seconds.
    - if we don't use "thread" the whole code will take 5 + 5 = 10 seconds.
*/

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void print()
{
     for (size_t i = 1; i <= 5 ; i++)                                                   // this loop will take 5 seconds in total
     {
        cout << "Thread called print() function" << endl;
        this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(1));     // sleep 1 sec.
     }
     
 
}

int main ()
{
    thread t(&print);

    for(int i = 1; i <= 5 ; i++)                                                        // this loop will take 5 seconds in total
    {
        cout << i << endl;
        this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(1));     // sleep 1 sec.
    }
    
    t.join();

 return 0;
}