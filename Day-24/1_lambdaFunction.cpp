#include <bits/stdc++.h>
using namespace std;

// it is used for defining an inline or local to be passed without declaration 
// for example when a function is to be passed in sort function, instead of declaring it above, lambda function can be used
// [](){}
// [] is used for passing variables from the local scope
// () is used for passing parameters
// {} is for the main code

int main(){
    int a = 10, b = 16;

    auto lbdFnc = [=](float x, float y){
        return a*x + b*y;
    };

    cout<<lbdFnc(.5,.25);
    // prints 9
}

// [] → captures nothing

// [x] → captures x by value

// [&x] → captures x by reference

// [=] → captures all used variables by value

// [&] → captures all used variables by reference