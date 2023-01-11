#include <iostream>
using namespace std;
int binarySearch(int Z[], int i_k, int i_p, int k)
{
    if (i_p >= i_k) {
        int i_sr = i_k + (i_p - i_k) / 2;

        if (Z[i_sr] == k){
            return i_sr;
        }
           
        if (Z[i_sr] > k){
            return binarySearch(Z, i_k, i_sr - 1, k);
        } else {
            return binarySearch(Z, i_sr + 1, i_p, k);
        }
    }
    return -1;
}
 
int main(void)
{
    int Z[] = { 1, 2, 3, 4, 5 };
    int k = 4;
    int n = sizeof(Z) / sizeof(Z[0]);
    int p = binarySearch(Z, 0, n - 1, k);
    cout << p << '\n';
    return 0;
}