#include <iostream>
#include <vector>
#include <string>
using namespace std;

void changeStrByVal(string s) {
    if (s.size() >0) {
        s[0]++;
        cout << s << endl;
    }
}

void changeStrByRef(string & s) {
    if (s.size() >0) {
        s[0]++;
        cout << s << endl;
    }
}

int main(void) {

    string s;

    s = "welcome";
    changeStrByVal(s);
    cout << s << "\n\n";
    
    s = "welcome";
    changeStrByRef(s);
    cout << s << "\n\n";

    return 0;
}

