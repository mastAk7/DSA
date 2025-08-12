// given a string, extract all words
#include <bits/stdc++.h>
using namespace std;


// strtok breaks a C-style string (a char[]) into tokens using one or more delimiter characters.
// Each call returns the next token (a char*) until no tokens remain (returns NULL)

// It modifies the input string: every delimiter it finds is replaced by '\0' to terminate tokens.

// You must pass a modifiable buffer (not a string literal).

// The first call gives the string to tokenize; subsequent calls pass NULL to continue tokenizing the same string.

// strtok treats runs of delimiters as a single separator — it does not return empty tokens for consecutive delimiters.


int main(){
    char s[] = "My name is Aryan Kansal. How are you?";

    char *x = strtok(s," .?");
    cout<<x<<endl;
    while(x){
        x = strtok(NULL," .?");
        cout<<x<<endl;
    }

}