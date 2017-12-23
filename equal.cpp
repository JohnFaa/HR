#include<iostream>
#include<cmath>

using namespace std;

//array of chocolates distribution
int C[] = {1, 2, 5};

int findMin(int * arr, int n){
    int minNum = arr[0];
    int minNumPos = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] < minNum){
            minNum = arr[i];
            minNumPos = i;
        }
    return minNumPos;
}

void printArray(int * arr, int n){
    cout<<endl;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<", ";
    }
}

int findDiff(int * dist, int n, int minNumPos){
    int diff = 0;
    for(int i = 0; i < n; i++){
        int d = abs(dist[i] - dist[minNumPos]);
        diff += d;
    }
    return diff;
}

int findSteps(int * dist, int n, int d){
    //total steps to equal the distribution
    int steps = 0;
    //finding the position of the minimum number
    int minNumPos = findMin(dist, n);
    //make a copy of the array
    int minNum = dist[minNumPos] - d;
    int offset = abs(minNum);
    if(minNum > 0)
        offset *=  -1;

    for(int i = 0; i < n; i++){
        if(i == minNumPos)
            continue;
        int d = dist[i] + offset;
        steps += (d / 5);
        d = d % 5;
        steps += (d / 2);
        d = d % 2;
        steps += d;
    }
    return steps;
}

int main(){
    int t;
    cin>>t;
    while(t-- != 0){
        int n;
        cin>>n;
        int * dist = new int[n];
        for(int i = 0; i < n; i++)
            cin>>dist[i];
        int minSteps = findSteps(dist, n, 0);
        int minNumPos = findMin(dist, n);
        for(int i = 0; i < 3; i++){
            int steps = findSteps(dist, n, C[i]) + 1;
            if(minSteps > steps){
                minSteps = steps;
            }
        }
        cout<<minSteps<<endl;
        delete[] dist;
    }
}
