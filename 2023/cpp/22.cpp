#include <bits/stdc++.h>
using namespace std;

int minvalcubes(vector<string> words);

vector<string> linesplit(string line) {
    string part;
    vector<string> words;
    istringstream iss(line);
    while (iss>>part) words.emplace_back(part);

    return words;
}

int main(void) 
{
    ifstream inpfile;
    inpfile.open("../test-cases/inp2.txt");

    int id = 0, result = 0, power;
    string line;

    while (getline(inpfile, line)) {
        vector<string> words;
        id++;

        words = linesplit(line);
        power = minvalcubes(words);

        result += power;
    }

    cout << "Sum of power: " << result << endl;
}

int minvalcubes(vector<string> words) {
    int minR = 0, minG = 0, minB = 0;

    for (auto it = words.begin(); it != words.end(); it++) {

        if ((*it == "red" || *it == "red;" || *it == "red,") && (stoi(*(it-1)) > minR)) minR = stoi(*(it-1));

        else if ((*it == "green" || *it == "green;" || *it == "green,") && (stoi(*(it-1)) > minG)) minG = stoi(*(it-1));

        else if ((*it == "blue" || *it == "blue;" || *it == "blue,") && (stoi(*(it-1)) > minB)) minB = stoi(*(it-1));

    }

    return minR*minG*minB;
}