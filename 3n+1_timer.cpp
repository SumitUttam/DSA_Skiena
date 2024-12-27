#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int sequence_DP (int l, int r){
    int maxS=0;
    int dp[r-l+1] = {0};
    for (int i=l; i<=r; i++){
        int c=1;
        int j=i;
        while (j>1){
            if (j<i && j>=l){
                c += dp[j-l]-1;
                break;
            }
            if (j%2==0){
                j = j/2;
            }
            else {
                j = 3*j+1;
            }
            c++;
        }
        dp[i-l] = c;
        maxS = max(maxS,c);
    }
    return maxS;
}

int sequence(int l,int r){
    int maxS=0;
    for (int i=l; i<=r; i++){
        int c=1;
        int j=i;
        while (j>1){
            if (j%2==0){
                j = j/2;
            }
            else {
                j = 3*j+1;
            }
            c++;
        }
        maxS = max(maxS,c);
    }
    return maxS;
}


int main (){
    int l,r;
    cout <<"Enter L and R: ";

    while (cin>>l>>r){

        auto start = high_resolution_clock::now();
        cout<<sequence(l,r);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout <<" Without  DP: "<< duration.count() <<" ms"<< endl;

        auto start1 = high_resolution_clock::now();
        cout<<sequence_DP(l,r);
        auto end1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(end1 - start1);
        cout <<" With  DP: "<< duration1.count() <<" ms"<< endl;
        cout <<endl<<"####"<<endl;
        cout <<"Enter L and R: ";
    }
    return 0;
}
