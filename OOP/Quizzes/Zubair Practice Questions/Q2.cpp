#include <iostream>
#include <string>
using namespace std;

string my_compress(string s) {
    string result = "";
    int n = s.size();

    for (int i = 0; i < n; i++) {
        char ch = s[i];
        int count = 1;

        while (i + 1 < n) {
            if (s[i + 1] == ch) {
                count++;
                i++;  // consume next char
            } else {
                break; // stop when different char
            }
        }

        result += ch;
        if (count > 1) {
            result += to_string(count);
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Compressed: " << my_compress(s) << endl;
    return 0;
}