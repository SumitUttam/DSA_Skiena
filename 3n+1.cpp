#include<iostream>
#include <ctime>
using namespace std;

int main (){
    int l,r;
    while (cin>>l>>r){
        if (l>r){
            l = l+r;
            r = l-r;
            l = l-r;
        }
        int maxS=0;
//         int dp[r-l+1] = {0};
        for (int i=l; i<=r; i++){
            int c=1;
            int j=i;
            while (j>1){
//                 if (j<i && j>=l){
//                     c += dp[j-l]-1;
// //                     cout<<"weird"<<j<<endl;
//                     break;
//                 }
                if (j%2==0){
                    j = j/2;
                }
                else {
                    j = 3*j+1;
                }
                c++;
            }
//             dp[i-l] = c;
            maxS = max(maxS,c);
        }
        cout<<l<<" "<<r<<" "<<maxS<<endl;
    }
}
