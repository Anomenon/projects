#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{   
    ofstream File("IN_OUT/output.txt");
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        File << "Case " << t << ": ";
        string line;
        cin >> line;
        
        int pos = 0, count = 0;
        char letter = line[pos];
        ++pos;
        for (; pos < line.size(); ++pos)
        {
            if (isalpha(line[pos]))
            {
                File << string(count, letter);
                count = 0;
                letter = line[pos];
            }
            if (isdigit(line[pos]))
            {
                count = count * 10 + line[pos] - '0';   
            }
        }
        File << string(count, letter) << '\n';
    }
}