
#include <iostream>
#include <string>

using namespace std;

string userStr;
int length;
void cShift(string s, int l);
void printS(string s1, int l1);

int main()
{
    cout << "Enter a cypher: ";
    getline(cin, userStr);
    length = userStr.length();
    cShift(userStr, length);
}

void cShift(string s, int l) {
    string tempS = s;                   //TEMP STRING TO HOLD SHIFTED VALUES!
    for (int i = 0; i < 26; ++i) {     //26 total shift values (current value of input string included)

        for (int j = 0; j < l; ++j) {        //iterate entire length of s, char-by-char
            char c = s[j];                   //c makes code easier to read, and cheap to copy
            int x = int(c);                  // cast from char to int
            if ((x >= 65) && (x < 91)) {
                //start with uppercase values
                x -= 65;           //shift values to beginning at 0 (now can use mod26)
                x = ((x + i) % 26);
                x += 65;           //shift back to A-Z ASCII values
                c = char(x);        //cast from int (ASCII value) to char
                tempS[j] = c;           //after shift, change value of pos in temp string to new value
            }
            else if ((x >= 97) && (x < 123)) {    //now account for lowercase values

                x = x - 97;           //shift values to beginning at 0 (now can use mod26)
                x = ((x + i) % 26);
                x += 97;              //shift back to appropriate ASCII values
                c = char(x);           //cast back to char
                tempS[j] = c;        //after shift, change value of pos in temp string to new value
            }
        }
        cout << "Result [" << (i + 1) << "] :  ";
        printS(tempS, l);
    }

}
void printS(string s1, int l1) {
    for (int i = 0; i < l1; i++) {
        cout << s1.at(i);
    }
    cout << endl;
}