#include<iostream>

using namespace std;

int main (){
    int i = 0;
    int *p1;
    p1 = &i; //& gives the reference of i in memory
    *p1 = 14;
    cout << i << " is Data at " << p1 << endl;
}