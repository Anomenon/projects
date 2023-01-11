#include <iostream>
using namespace std; 

int getSum(int X[], int m){ 

    int sum = 0; 

    for (int i = 0; i < m; i++) 

        sum += X[i]; 

    return sum; 
} 
 
int getTarget(int A[], int m, int B[]){ 

    int sum1 = getSum(A, m); 

    int sum2 = getSum(B, m); 

    if ((sum1 - sum2) % 2 != 0) 
        return 0; 

    return ((sum1 - sum2) / 2); 
} 

void findSwapValues(int A[], int m, int B[]){ 
    sort(A, A + m); 
    sort(B, B + m); 

    int target = getTarget(A, m, B); 

    if (target == 0) 
        return; 
    int i = 0, j = 0; 

    while (i < m && j < m) { 
        int diff = A[i] - B[j]; 

        if (diff == target) { 
            cout << A[i] << " " << B[j]; 
            return; 
        } 
        else if (diff < target) 
            i++; 
        else
            j++; 
    } 
} 

int main() 
{   
    int m;
    cin >> m;

    int A[m]; 
    int B[m];

    findSwapValues(A, m, B); 

    return 0; 
} 