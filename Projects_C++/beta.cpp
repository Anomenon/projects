#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h> 

using namespace std;

int main()
{   
	system("clear");
	srand( time(NULL) );
	int how = 0;

	for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
			int random = rand() % 2;
			if(random == 1){
				how++;
			}
        }
    }
	cout << how << '\n';
	return 0;
}