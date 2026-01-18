#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

struct ReactionResult {
    double reactionTimeMs;
    char grade;          // S, A, B, C, D, F each grad has its own credit
    char difficulty;     // B, N, H
};  

int main()
{
    vector<double> reactionTimeMs;
    vector<char> grade;
    vector<char> diff;
    char diffi;
    char choice = 'y';
    int delay;
    unordered_map<int, int> map_score ={{'B', 1}, {'N', 2}, {"H", 3}};
    
    while (true)
    {
        cout << "Press ENTER to continue..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        cout << "Enter difficulty (B beginer /N normal /H hardcore): " << endl;
        cin >> diffi;
        diffi = toupper(diffi);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (diffi == 'B')
        {
            delay = rand() % 3 + 2;
        }
        else if (diffi == 'N')
        {
            delay = rand() % 4 + 2;
        }
        else if (diffi == 'H')
        {
            delay = rand() % 5 + 3;
        }
        else
        {
            delay = rand() % 4 + 2;
        }

        this_thread::sleep_for(chrono::seconds(delay));

        cout << "react by pressing enter !" << endl;

        auto start = chrono::high_resolution_clock::now();
        cin.get();
        auto end = chrono::high_resolution_clock::now();

        double ms = chrono::duration<double, milli>(end - start).count();

        if (ms < 180)
        {
            cout << "🔥 Insane reflexes! Are you human?\n";
        }
        else if (ms < 220)
        {
            cout << "😎 Pro gamer level reaction!\n";
        }
        else if (ms < 260)
        {
            cout << "👍 Above average reaction.\n";
        }
        else if (ms < 320)
        {
            cout << "🙂 Normal human reaction.\n";
        }
        else if (ms < 400)
        {
            cout << "🐢 A bit slow, focus up!\n";
        }
        else
        {
            cout << "💀 Too slow! Were you sleeping?\n";
        }

        cout << "Do you wish to continue? (y/n): " << endl;
        cin >> choice;

        if (tolower(choice) == 'n')
        {
            break;
        }
    }
    //out of while printing stats 

    cout<<"========== Stats ==========";
    
    return 0;
}