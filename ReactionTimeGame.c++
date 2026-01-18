#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

struct ReactionResult
{
    double reactionTimeMs;
    char grade;        // S A B C D F
    char difficulty;   // B N H
};

char calculateGrade(double ms)
{
    if (ms < 180)
    {
        return 'S';
    }
    else if (ms < 220)
    {
        return 'A';
    }
    else if (ms < 260)
    {
        return 'B';
    }
    else if (ms < 320)
    {
        return 'C';
    }
    else if (ms < 400)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

int getDelay(char difficulty)
{
    if (difficulty == 'B')
    {
        return rand() % 3 + 2; // 2–4 seconds
    }
    else if (difficulty == 'N')
    {
        return rand() % 4 + 2; // 2–5 seconds
    }
    else if (difficulty == 'H')
    {
        return rand() % 5 + 3; // 3–7 seconds
    }
    else
    {
        return rand() % 4 + 2; // default (normal)
    }
}

int main()
{
    srand(time(0));

    vector<ReactionResult> results;
    char choice = 'y';

    while (true)
    {
        char difficulty;

        cout << "\nPress ENTER when you are ready...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        cout << "Choose difficulty (B = Beginner, N = Normal, H = Hardcore): ";
        cin >> difficulty;
        difficulty = toupper(difficulty);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int delay = getDelay(difficulty);

        cout << "Get ready...\n";
        this_thread::sleep_for(chrono::seconds(delay));

        cout << "REACT! (Press ENTER)\n";

        auto start = chrono::high_resolution_clock::now();
        cin.get();
        auto end = chrono::high_resolution_clock::now();

        double reactionTimeMs =
            chrono::duration<double, milli>(end - start).count();

        char grade = calculateGrade(reactionTimeMs);

        results.push_back(
            {
                reactionTimeMs,
                grade,
                difficulty
            }
        );

        cout << "Reaction Time: " << reactionTimeMs << " ms\n";
        cout << "Grade: " << grade << "\n";

        if (grade == 'S')
        {
            cout << "🔥 Insane reflexes!\n";
        }
        else if (grade == 'A')
        {
            cout << "😎 Pro gamer level!\n";
        }
        else if (grade == 'B')
        {
            cout << "👍 Above average!\n";
        }
        else if (grade == 'C')
        {
            cout << "🙂 Normal reaction.\n";
        }
        else if (grade == 'D')
        {
            cout << "🐢 Slow reaction.\n";
        }
        else
        {
            cout << "💀 Too slow!\n";
        }

        cout << "\nDo you want to play another round? (y/n): ";
        cin >> choice;

        if (tolower(choice) == 'n')
        {
            break;
        }
    }

    cout << "\n========== FINAL STATS ==========\n";

    double sum = 0.0;

    for (size_t i = 0; i < results.size(); i++)
    {
        cout << "Round " << i + 1
             << " | Time: " << results[i].reactionTimeMs << " ms"
             << " | Grade: " << results[i].grade
             << " | Difficulty: " << results[i].difficulty << "\n";

        sum += results[i].reactionTimeMs;
    }

    if (!results.empty())
    {
        cout << "Average Reaction Time: "
             << sum / results.size()
             << " ms\n";
    }

    cout << "================================\n";
    cout << "Thanks for playing!\n";

    return 0;
}
