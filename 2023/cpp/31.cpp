#include <bits/stdc++.h>
using namespace std;

string checkfornum(string mL, int j);

bool isnum(string s) {
    for (char c : s) if (!isdigit(c)) return false;
    return true;
}

bool search(char target) {
    vector<string> symbols = {
        "-", "#", "=", "*", "+", "@", "$", "&", "/", "%"};
    string targetStr(1, target);

    auto it = find(symbols.begin(), symbols.end(), targetStr);
    if (it != symbols.end()) return true;
    else return false;
}

int main(void)
{
    ifstream inpfile;
    inpfile.open("../test-cases/inp3.txt");

    int sumofpartno = 0;
    string line; 
    vector<string> lines;

    while(getline(inpfile, line)) lines.emplace_back(line);

    for (int i = 0; i < lines.size(); i++) {
        string pL = i-1 >= 0 ? lines[i-1] : "";
        string mL = lines[i];
        string nL = i+1 < lines.size() ? lines[i+1] : "";

        for (int j = 0; j < mL.size(); j++) {
            string num = checkfornum(mL, j);
            if (num != "") {
                if ((j-1>=0 && search(mL[j-1])) || (j+num.size() < mL.size() && search(mL[j+num.size()]))) { 
                    sumofpartno += stoi(num);
                    cout << num << endl;
                }
                else {
                    int limit = j+1+num.size();
                    for (int k = max(j-1, 0); k < min(limit, static_cast<int>(line.size())); k++) {
                        if (k<pL.size() && search(pL[k])) {
                            sumofpartno += stoi(num);
                            cout << num << endl;
                            break;
                        }
                        else if (k<nL.size() && search(nL[k])) {
                            sumofpartno += stoi(num);
                            cout << num << endl;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << "Sum of part numbers: " << sumofpartno << endl;
    inpfile.close();
}

string checkfornum(string mL, int j) {
    string num = "";
    try {
        if (isnum(mL.substr(j,3))) num = mL.substr(j,3);
        else if (isnum(mL.substr(j,2)) && !isdigit(mL[j-1])) num = mL.substr(j,2);
        else if (isdigit(mL[j]) && !isdigit(mL[j-1])) num = mL[j];
    } catch (const out_of_range&) {}

    return num;
}

