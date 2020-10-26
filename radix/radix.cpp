#include <iostream>
#include <algorithm>
#include <sstream>

int getMax(int * arr, int n){
    int max = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] > arr[max]){
            max = i;
        }
    }
    return arr[max];
}

void countSort(int * arr, int n, int e){
    int * count = new int[10];
    for (int i = 0; i < 10; i++){
        count[i] = 0;
    }

    for (int i = 0; i < n; i++){
        count[(arr[i]/e) % 10]++;
    }

    for (int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }

    int * output = new int[n];

    for (int i = n-1; i >= 0; i--){
        output[count[(arr[i]/e) % 10] - 1] = arr[i];
        count[(arr[i]/e) % 10]--;
    }
    for (int i = 0; i < n; i++){
        arr[i] = output[i];
    }
    delete [] output;
    delete [] count;
}

void radix(int * arr, int  n){
    int max = getMax(arr, n);
    for (int e = 1; max/e > 0; e*=10){
        countSort(arr, n, e);
    }
}

void printArray(int * arr, int n){
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void parseInput(int * arr, int n, char * argv[]){
    for (int i = 0; i < n; i++){
        arr[i] = std::stoi(argv[i+1]);
    }
}

int main(int argc, char * argv[]){

    int * arr = new int[argc-1];
    int n = argc-1; 
    parseInput(arr, n, argv);

    radix(arr, n);

    printArray(arr, n);

    delete [] arr;
    return 0;
}