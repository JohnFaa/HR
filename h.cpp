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
    /*
    //calculating the sum of difference between every number and the least number
    int diff = findDiff(distCopy, n, minNumPos);
    while(diff != 0){
        for(int i = 0; i < n; i++){
            if(i == minNumPos || distCopy[i] == distCopy[minNumPos])
                continue;
            int minC = 0;
            int minDiff = diff;
            //calculate the best reduction for every one
            for(int j = 0; j < 3; j++){
                if(distCopy[i] - C[j] < distCopy[minNumPos])
                    continue;
                int newDiff = diff - abs(distCopy[i] - distCopy[minNumPos]) +
                    abs(distCopy[i] - C[j] - distCopy[minNumPos]);
                if(newDiff < minDiff){
                    minDiff = newDiff;
                    minC = C[j];
                }
            }
            diff = minDiff;
            distCopy[i] -= minC;
            //printArray(distCopy, n);
            steps += 1;
            if(diff == 0){
                delete[] distCopy;
                return steps;
            }

        }
    }*/
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
