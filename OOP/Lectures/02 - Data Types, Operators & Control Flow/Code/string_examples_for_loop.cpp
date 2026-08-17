
// Harrypotter
//pot

// Pseudo code for solving the substring finding problem
// function findsubstringindex (txt, pat)
// n -> length of txt
// m -> length of pat
// for i from (0 to n-m){
//  match -> true
//  for j from (o to m-1):
//     if txt[i+j] !=pat[j]
//     match = false
//     break

//   if match is true
//      return i

//   return -1

#include <iostream>
using namespace std;
#include <string>

int findsubstringindex (string txt, string pat){

    int n = txt.length();
    int m = pat.length();
    int j;

    // loop through the txt first
    for (int i=0; i<=n-m; i++){
        bool match = true;
        // sliding window concept
        for (j=0; j<m; j++){
            if (txt[i+j] != pat[j]){
                match = false;
                break;
            }
        }
        if (match == true){
            return i;
        }
    }
    return -1;
}

int main(){

    string txt = "HarryPotter";
    string pat = "Pot";

    int index = findsubstringindex(txt, pat);

    if (index!=-1){

        cout << " Pattern found at " <<index <<endl;
    }
    else{

        cout << " Pattern not found!!"<<endl;

    }
    return 0;
}

