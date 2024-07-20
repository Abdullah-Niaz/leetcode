#include <bits/stdc++.h>
using namespace std;

int findDays(vector<int> &weights, int cap) {
    // vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6}; 
    // cap
        // 1 -> 6
        // 2 -> 
    
    // Days
    // 1
    // 2
    // 
    int days = 1; 
    
    //1. 6
    //2. 4
    int load = 0;
    
    int n = weights.size(); //size of array. 8

    // 0,1,2
    for (int i = 0; i < n; i++) {
        // if:
            // 0 -> 0 + 5 > 6 -> False
            // 1 -> 6 + 4 > 6 -> True
            // 2 -> 4 + 5 > 6 -> True
        if (load + weights[i] > cap) {
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            // 1 -> load = 0 + 5 = 6
            // 2 -> load = 0 + 5 = 6
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d) {
    //Find the maximum and the summation:
    // maxi = 6
    int maxi = *max_element(weights.begin(), weights.end()); 
    // sum = 34
    int sum = accumulate(weights.begin(), weights.end(), 0); 

    for (int i = maxi; i <= sum; i++) { // ( 6 to 34)
    
        if (findDays(weights, i) <= d) {
            return i;
        }
    }
    //dummy return statement:
    return -1;
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}

