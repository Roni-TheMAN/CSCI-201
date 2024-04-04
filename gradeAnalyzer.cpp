/* gradeAnalyzer.cpp
 * Ronit Patel
 * 4/3/24
 * Analyzes the gradeof studenst and provide valuable insights.
 */

#include <iostream>
#include <array>

using namespace std;

const int MODULES = 16;

// Function to get quiz scores for 16 weeks
void getData(array<int, MODULES>& scores) {
    cout << "Enter quiz scores for 16 weeks:" << endl;
    for (int i = 0; i < MODULES; i++) {
        cout << "Module " << (i + 1) << ": ";
        cin >> scores[i];
    }
}

// Function to find the highest quiz score and return its module number
int highScore(const array<int, MODULES>& scores) {
    int highest = scores[0];
    int module = 1;
    for (int i = 1; i < MODULES; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
            module = i + 1;
        }
    }
    return module;
}

// Function to find the lowest quiz score and return its module number
int lowScore(const array<int, MODULES>& scores) {
    int lowest = scores[0];
    int module = 1;
    for (int i = 1; i < MODULES; i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
            module = i + 1;
        }
    }
    return module;
}

int main() {
    array<int, MODULES> quizScores;

    getData(quizScores);

    int highestModule = highScore(quizScores);
    int lowestModule = lowScore(quizScores);

    cout << "\nFall 2019 Quiz Grades:\n\n";
    for (int i = 0; i < MODULES; i++) {
        cout << "Module " << (i + 1) << ": " << quizScores[i] << endl;
    }

    int average = 0;
    for (int score : quizScores) {
        average += score;
    }
    average /= MODULES;

    cout << "\nAverage Grade: " << average << endl;
    cout << "\nYour lowest score was in Module " << lowestModule << " with " << quizScores[lowestModule - 1] << "." << endl;
    cout << "Your highest score was in Module " << highestModule << " with " << quizScores[highestModule - 1] << "." << endl;

    return 0;
}

