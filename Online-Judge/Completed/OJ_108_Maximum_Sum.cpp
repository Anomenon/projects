#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
const int SIZE = 101;

int solve(int& N, vector<vector<int> >& sumof_square, vector<vector<int> >& input){
    int maximum = -128;

    for (int x = 0; x <= N; x++){
        for (int y = 0; y <= N; y++){
            for (int i = 0; i <= x; i++){
                for (int j = 0; j <= y; j++){
                    int square = sumof_square[x][y] - sumof_square[i][y] - sumof_square[x][j] + sumof_square[i][j];
                    maximum = max(maximum, square);
                }
            }
        }
    }

    if(maximum != 0){
        return maximum;
    } else {
        maximum = -128;
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                maximum = max(maximum, input[i][j]);
            }
        }
        return maximum;
    }
}

int main(){
    ofstream outFile("IN_OUT/output.txt");
    int N, num;
    cin >> N;
    vector<vector<int> > sumof_square(N + 1, vector<int>(N + 1, 0));
    vector<vector<int> > input(N + 1, vector<int>(N + 1, 0));

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> num;
            input[i][j] = num;
            sumof_square[i][j] = sumof_square[i-1][j] + sumof_square[i][j-1] + num - sumof_square[i-1][j-1];
        }
    }

    outFile << solve(N, sumof_square, input) << '\n';

    return 0;
}