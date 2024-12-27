#include <bits/stdc++.h>

using namespace std;

int main (){
    bitset<4> a ("1001");
    bitset<4> b ("0110");

    if ( (a&b) == 0) {
        cout<<"fuck yes" << endl;
    }
    else {
        cout<<"well fuck"<<endl;
    }


    return 0;
}