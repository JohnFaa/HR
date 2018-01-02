#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int * P = new int[N];
    for(int i = 0; i < N; i++)
        cin>>P[i];
    long long dec = 0;
    long long prev = 1;
    long long curr = 1;
    long long cCount = 0;

    //initializing the values
    if(P[0] > P[1])
        dec = 1;
    else
        cCount = 1;

    for(int i = 1; i < N; i++){
        if(P[i] >= P[i - 1]){
            //to deal with decrease chain previously
            if(dec > 0){
                if(dec < prev){
                    cCount += prev;
                    long long decSum = dec * (dec - 1) / 2;
                    cCount += decSum;
                    prev = 1;
                }
                else{
                    long long decSum = dec * (dec + 1) / 2;
                    cCount += decSum;
                    prev = 1;
                }
                dec = 0;
            }
            //dealing with the current student priority
            if(P[i] > P[i - 1]){
                curr = prev + 1;
                //if the next priority starts a decrease chain then evaluate it before making changes
                if(i + 1 < N && P[i] > P[i + 1])
                    dec = 1;
                else
                    cCount += curr;
            }
            else{
                curr = 1;
                //if the next priority starts a decrease chain then evaluate it before making changes
                if(i + 1 < N && P[i] > P[i + 1])
                    dec = 1;
                else
                    cCount += 1;
            }
        }
        else{
            dec++;
            if(i == N - 1){
                if(dec < prev){
                    cCount += prev;
                    long long decSum = dec * (dec - 1) / 2;
                    cCount += decSum;
                }
                else{
                    long long decSum = dec * (dec + 1) / 2;
                    cCount += decSum;
                }
            }
        }
        prev = curr;
    }
    cout<<cCount<<endl;
}
