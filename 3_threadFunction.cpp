/*
    We can create a function and pass it as a parameter to the thread.
*/

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void threadFunction_1(int parameter1, int parameter2, int parameterN)
{
    while (1)
    {
        cout<< "\nthreadFunction_1"<<endl;
        cout<< "parameter1: "<< parameter1 <<endl;
        cout<< "parameter2: "<< parameter2 <<endl;
        cout<< "parameterN: "<< parameterN <<endl;

        this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(1));     // sleep 1 sec.
    }
}

void threadFunction_2(int parameter1, int parameter2, int parameterN)
{
    while (1)
    {
        cout<< "\nthreadFunction_2"<< endl;
        cout<< "parameter1: "<< parameter1 <<endl;
        cout<< "parameter2: "<< parameter2 <<endl;
        cout<< "parameterN: "<< parameterN <<endl;

        this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(1));     // sleep 1 sec.
    }
}

int main()
{
    int parameter1 = 10;
    int parameter2 = 20;
    int parameterN = 30;

    cout<< "We can pass more than 3 parameteer to thread"<<endl;

    thread t1(&threadFunction_1, parameter1, parameter2, parameterN);
    thread t2(&threadFunction_2, parameter1*2, parameter2*2, parameterN*2);

    t1.join();
    t2.join();


    return 0;
}