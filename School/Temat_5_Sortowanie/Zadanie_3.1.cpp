#include <iostream>
using namespace std;
int binarySearch(int Z[], int i_p, int i_k, int k)
{
    while (i_k >= i_p) {
        int i_sr = i_p + (i_k - i_p) / 2;

        if (k == Z[i_sr] ){
            return i_sr;
        }
           
        if (k > Z[i_sr]){
            i_p = i_sr + 1;
        } else {
           i_k = i_sr - 1;
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