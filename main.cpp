//
//  main.cpp
//  AoC22_2
//
//  Created by Matthew Bache on 12/2/22.
//

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char * argv[]) {
    fstream inputFile;
    inputFile.open("/Users/matthewbache/Documents/AoC22/AoC22_2/AoC22_2 Input.txt");
    if (!inputFile.is_open()) {
        cout << "Could not open file\n";
        return 1;
    }
    int totalScorePart1 = 0;
    int totalScorePart2 = 0;
    
    // PART 1
    // shape you selected
    // 1 for Rock X
    // 2 for Paper Y
    // 3 for Scissors Z
    // outcome of the round
    // 0 if you lost
    // 3 if you drew
    // 6 if you won
    // PART 2
    // X means you need to lose 0
    // Y means you need to draw 3
    // Z means you need to win 6
    string combos[] = {"A X", "A Y", "A Z",
                       "B X", "B Y", "B Z",
                       "C X", "C Y", "C Z"};
    int scoresPart1[] = {1+3,2+6,3+0,
                         1+0,2+3,3+6,
                         1+6,2+0,3+3};
    int scoresPart2[] = {3+0,1+3,2+6,
                         1+0,2+3,3+6,
                         2+0,3+3,1+6};
    int plays = 9;
    string line;
    while (getline(inputFile, line)) {
        int i;
        for (i = 0; i < plays; i++) {
            if (line.compare(combos[i])==0) {
                totalScorePart1 += scoresPart1[i];
                totalScorePart2 += scoresPart2[i];
                break;
            }
        }
        if (i > plays)
            cout << "could not compute score for " << line << "\n";
    }

    cout << "Total Score part 1: " << totalScorePart1 << "\n";
    cout << "Total Score part 2: " << totalScorePart2 << "\n";
    
    inputFile.close();
    return 0;
}
