#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ifstream inpfile;
    inpfile.open("../test-cases/inp1.txt");

    string line;
    int sumofcalibval = 0;

    while (getline(inpfile, line)) {
        string digits, calibVal;

        for (const char c : line)
            if (isdigit(c)) digits += c;
        
        calibVal = calibVal + digits[0] + digits.back();
        sumofcalibval += stoi(calibVal);
    }

    cout << "Sum of calibaration value: " << sumofcalibval << endl;

    inpfile.close();
    return 0;
}