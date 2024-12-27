// #include<iostream>
// #include<fstream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream inputFile;
    ofstream outputFile;
    outputFile.open("failPhase.txt");
    
    string passPhrase;
    int guess=0;

    inputFile.open("passPhrase.txt");
    if (!inputFile.fail()){
        //checks if data is still available to be read;
        while (inputFile>>passPhrase){
            cout << "passPhrase is " << passPhrase << endl << "enter your guess: ";
            cin >> guess;
            if (guess == passPhrase.length()){
                cout<< "correct Guess!\n" << endl;
            }
            else {
                cout<< "Wrong guess!\n" << endl;
                outputFile << passPhrase << endl;
            }
        }
    }
    inputFile.close();
    outputFile.close();
    return 0;
}