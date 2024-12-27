// #include<iostream>
// #include<fstream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    // intead of ifstream and ofstream fstream can be used;
    fstream inputFileA;
    fstream outputFileB;
    vector<pair<string, int>> supplies(10);
    int i=0;
    outputFileB.open("ModifiedSupplies.txt", ios::app); //opening for append;
    inputFileA.open("currentSupplies.txt");
    if (!inputFileA.fail()){
        //checks if data is still available to be read;
        while (inputFileA>>supplies[i].first >> supplies[i].second){
            outputFileB<<supplies[i].first << " :- " << supplies[i].second << endl;
            i++;
        }

    }
    inputFileA.close();
    outputFileB.close();

    return 0;
}