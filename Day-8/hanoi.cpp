#include <bits/stdc++.h>
using namespace std;

void f(char source, char helper, char destination, int n){
    if(n==1){
        cout<<source<<" TO "<<destination<<endl;
        return;
    }

    f(source, destination, helper, n-1);
    f(source, helper, destination, 1);
    f(helper, source, destination, n-1);
    return;
}

int main(){
    f('B','A','C',4);
    f('B','A','C',4);
}