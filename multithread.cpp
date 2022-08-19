#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

/*
    thread1, thread2 and thread3 are running concurrently.
*/

void Thread1()
{
    while (1)
    {
        this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(1));     //running every 1 second
        cout<< "Thread 1 running\n" << endl;
    }
}

void Thread2()
{
    while (1)
    {
        this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(5));     //running every 5 second
        cout<< "Thread 2 running\n" << endl;
    }
}

void Thread3()
{
    while (1)
    {
        this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(7));     //running every 7 second
        cout<< "Thread 3 running\n" << endl;
    }
}

int main()
{
    thread t1(Thread1);
    thread t2(Thread2);
    thread t3(Thread3);

    t1.join();
    t2.join();
    t3.join();

    cout<< "Main is running\n" << endl;         // this code will not work because join() of threads t1, t2 and t3 is 
                                                // defined before this line. this line would work if it was defined below this line.

    return 0;
}