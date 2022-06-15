#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void print(int& square_size, vector<vector<int> >& sumof_square, vector<int>& max_sum){
    ofstream outFile("IN_OUT/output.txt");
    for(int i = 0; i < square_size; i++){
        for(int j = 0; j < square_size; j++){
            outFile << sumof_square[i][j] << ' ';
        }
        outFile << '\n';
    }

    for(int j = 0; j < max_sum.size(); j++){
        cout << max_sum[j] << ' ';
    }
    cout << '\n';
}

int main(){
    ofstream outFile("IN_OUT/output.txt");
    int square_size, num, total = 0;
    cin >> square_size;
    vector<vector<int> > num_square(square_size);
    vector<vector<int> > sumof_square(square_size);
    vector<int> max_sum;

    for(int i = 0; i < square_size; i++){
        for(int j = 0; j < square_size; j++){
            cin >> num;
            total += num;
            max_sum.push_back(num);
            num_square[i].push_back(num);
            
            if(j == 0 && i == 0){
                sumof_square[i].push_back(num_square[i][j]);
            } else if(j != 0 && i == 0){
                sumof_square[i].push_back(sumof_square[i][j-1] + num_square[i][j]);
            } else if(j == 0 && i != 0){
                sumof_square[i].push_back(sumof_square[i-1][j] + num_square[i][j]);
            } else {
                sumof_square[i].push_back(sumof_square[i-1][j] + sumof_square[i][j-1] + num_square[i][j] - sumof_square[i-1][j-1]);
            }
        }
    }

    max_sum.push_back(total);

    print(square_size, sumof_square, max_sum);

    return 0;
}