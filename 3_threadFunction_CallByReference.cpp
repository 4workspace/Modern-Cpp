/*
    "Call by reference" example with function and pass it as a parameter to the thread.
    CBV: Call By Value
    CBR: Call By Reference
*/

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void threadFunction_CBV(string str1)                                                  // Call By Value
{   
    str1 = "Hello with Call By Value";
}

void threadFunction_CBR(string &str2)                                                // Call By Reference
{
    str2 = "Hello with Call By Reference";
}

int main()
{
    string str1 = "Hello thread";
    string str2 = "Hello thread";

    thread t1(&threadFunction_CBV, str1);
    thread t2(&threadFunction_CBR, ref(str2));

    t1.join();
    t2.join();

    cout << "threadFunction_CBV: str = " << str1 << endl;
    cout << "threadFunction_CBR: str = " << str2 << endl;


    return 0;
}