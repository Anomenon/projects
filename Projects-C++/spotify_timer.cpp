#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main(){
    std::this_thread::sleep_for(std::chrono::minutes(20));
    system("pkill -x Spotify");
    return 0;
}