#include <iostream>
#include <algorithm>

using namespace std;

int subsetSum(int n, int weights[], int sum){
    int subset[n + 1][sum + 1];
    for(int i = 1; i <= sum; i++){
        subset[0][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(j < weights[i-1]){
                subset[i][j] = subset[i-1][j];
            }else{
                subset[i][j] = max(subset[i-1][j], subset[i-1][j - weights[i-1]] + weights[i-1]);
            }
        }
    }
    return subset[n][sum];
}

int subsetSumGreedy(int n, int sum, int weights[], size_t sizeWeights){
    int weight = 0;
    int length = sizeWeights / sizeof(weights[0]);
    sort(weights, weights + length, greater<int>());
    for(int i = 0; i < n; i++){
        weight += weights[i];
        if(weight > sum){
            weight -= weights[i];
        }
    }
    return weight;
}



int main(){
    srand((unsigned) time(NULL));
    int items[100];
    for(int i = 0; i < 100; i++){
        int random = rand() % 601;
        items[i] = random;
    }
    size_t size = sizeof(items);

    // using random 100 random numbers with goal weight of 1000
    cout << subsetSum(100, items, 1000) << endl;
    cout << subsetSumGreedy(100, 1000, items, size) << endl;
    
    return 0;
}