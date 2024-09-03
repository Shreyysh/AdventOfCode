#include <bits/stdc++.h>
using namespace std;

bool validcubes(vector<string> words);

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

    int id = 0, result = 0;
    bool isValid;
    string line;

    while (getline(inpfile, line)) {
        vector<string> words;
        id++;

        words = linesplit(line);
        isValid = validcubes(words);

        if (isValid) result += id;
    }

    cout << "Sum of valid games: " << result << endl;
}

bool validcubes(vector<string> words) {

    for (auto it = words.begin(); it != words.end(); it++) {

        if ((*it == "red" || *it == "red;" || *it == "red,") && (stoi(*(it-1)) > 12)) return false;

        else if ((*it == "green" || *it == "green;" || *it == "green,") && (stoi(*(it-1)) > 13)) return false;

        else if ((*it == "blue" || *it == "blue;" || *it == "blue,") && (stoi(*(it-1)) > 14)) return false;

    }

    return true;
}