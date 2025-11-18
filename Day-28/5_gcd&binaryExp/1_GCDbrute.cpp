#include <bits/stdc++.h>
using namespace std;

// idea : we would simultaneouly break both the numbers in a loop from i = 2 to i = smaller number
// i would only break the number if its divisible by both the numbers
// hence we would get all the common factors (prime) and hence multiplying them would give the gcd
// time complexity would be o(min(a,b)) in the worst case
// it would be lesser than this in average if the numbers are composite numbers 
// this is because both are getting divided with every iteration
// root min(a,b)/max(a,b) didnt work because for example 33 & 77 -> it would never reach i=11 because
// 11 > root 33 && 11 > root 77

int gcd(int a, int b){
    int ans = 1;
    for(int i=2; i<=min(a,b); i++){
        while(a%i==0 && b%i==0){
            a /= i;
            b /= i;
            ans *= i;
        }
    }
    return ans;
}

int main(){
    cout<<gcd(15,25);
}   