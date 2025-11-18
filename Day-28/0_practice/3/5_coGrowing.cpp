#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int power(int a, int b){
    if(b==0) return 1;
    int halfPow = power(a,b/2);
    int ans = halfPow * halfPow;
    if(b%2) ans = ans * a;
    return ans;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vi bits(30,0);
        int mx=0;
        while(n--){
            int x; cin>>x;
            int c = 0, num = 0;
            while(x || c<mx){   // 0 15 1 -> for example the prev number was 15 (4 bits) and next is 1 (1 bit)
                                // so for 15, it would consider x only but for extra iterations in 1, c<mx would help
                if(bits[c]){
                    // this is to ensure the increasing part i.e. the next number should have all the bits of the prev
                    // number atleast. to get 1 after zor, we need opposite bits in both numbers
                    int bit = !(x&1);
                    num += bit*power(2,c);
                } else{
                    // now here 1 or 0 both would work
                    // but in order to maintain lowest lexo order, we take the bit as always 0
                    int bit = 0;
                    bits[c] = (x&1)^bit;
                }
                x>>=1;
                c++;
            }
            mx = max(mx,c);
            cout<<num<<' ';
        }
        cout<<endl;
    }
}