#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-- != 0){
        //size of the input
        int N;
        cin>>N;
        //input array B
        int * B = new int[N];
        for(int i = 0; i < N; i++){
            cin>>B[i];
        }
        //array storing the optimal cost for 0 to i if A[i] is 1
        int * L = new int[N];
        //array storing the optimal cost for 0 to i if A[i] is B[i]
        int * H = new int[N];

        L[0] = 0;
        H[0] = 0;
        for(int i = 1; i < N; i++){
            L[i] = max(L[i - 1], H[i - 1] + abs(B[i - 1] - 1));
            H[i] = max(L[i - 1] + abs(B[i] - 1), H[i - 1] + abs(B[i - 1] - B[i]));
        }
        cout<<max(L[N - 1], H[N - 1])<<endl;
        return 0;
    }
}
