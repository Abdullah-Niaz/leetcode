#include <iostream>
using namespace std;

int max(int A[], int n ){
    int maxi = INT32_MIN; // 60
                        // INT_MIN = –2147483648   (for 32-bit Integers)
                        // INT_MIN = –9,223,372,036,854,775,808   (for 64-bit Integers)
    for (int i = 0; i < n; i++)
    // 10,30,20,44,50,60
    {
        if(maxi < A[i]){
            maxi  = A[i];
        }
    }
    return maxi;
}

int min(int A[], int n ){
    int mini = INT32_MAX; // 10
                        // INT_MAX = 2147483647   (for 32-bit Integers)
                        // INT_MAX = 9,223,372,036,854,775,807   (for 64-bit Integers)
    for (int i = 0; i < n; i++){
           // 10,30,20,44,50,60
        if(mini > A[i]){
            mini = A[i];
        }
    }
    return mini;
}



int main(){
    int A[] = { 10,30,20,44,50,60} ;
    int n = sizeof(A) / sizeof(A[0]);

    int minimum_element = min(A,n);
    int maximum_element = max(A,n);
    cout<<"Minimum Element in Array: "<<minimum_element<<endl;
    cout<<"Maximum Element in Array: "<<maximum_element<<endl;
    return 0;
}