#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ifstream inpfile;
    inpfile.open("../test-cases/inp1.txt");

    map<string, string> wordtonum;
    wordtonum.insert({
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"}
    });

    int sumofcalibval = 0;
    string line;
    
    while (getline(inpfile, line)) {
        vector<string> digits;

        for (int i = 0; i < line.size(); i++) {
            try {
                if (isdigit(line[i])) digits.emplace_back(string(1, line[i]));
                else if (wordtonum.find(line.substr(i,5)) != wordtonum.end())
                    digits.emplace_back(wordtonum[line.substr(i,5)]);
                else if (wordtonum.find(line.substr(i,4)) != wordtonum.end())
                    digits.emplace_back(wordtonum[line.substr(i,4)]);
                else if (wordtonum.find(line.substr(i,3)) != wordtonum.end())
                    digits.emplace_back(wordtonum[line.substr(i,3)]);
            } catch (const out_of_range&) {}
        }

        string calibVal = digits[0] + digits.back();
        sumofcalibval += stoi(calibVal);
    }

    cout << "Sum of calibaration value: " << sumofcalibval << endl;

    inpfile.close();
    return 0;
}