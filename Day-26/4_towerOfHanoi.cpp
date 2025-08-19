#include <bits/stdc++.h>
using namespace std;

void f(char source, char helper, char dest, int n){
    if(n==1){
        cout<<source<<" to "<<dest<<endl;
        return;
    }

    f(source, dest, helper, n-1);
    f(source, helper, dest, 1);
    f(helper, source, dest, n-1);
    return;
}

int main(){
    f('A','B','C',3);
    return 0;
}