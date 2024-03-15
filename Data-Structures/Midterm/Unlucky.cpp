#include <iostream>
#include <cmath>
using namespace std;

bool unlucky(int n){
    if (n < 100) return (n / 10 + n % 10) == 13;
    else return unlucky(n/10);
}

int sumCubes(int n){
    if (n == 0) return n;
    return sumCubes(n - 1) + pow(n, 3);
}

// int biggestDigit(int n){
//     if(n < 10) return n;
//     return max(n%10, biggestDigit(n/10));
    
// }

int sumDigits(int n){
    if (n < 10) return n;
    return sumDigits(n/10) + n % 10;

}

int call(int n){
    if(n < 10 && n % 2 == 0) return n;
    else if(n < 10 && n % 2 != 0) return 0;
    
    if((n % 10) % 2 == 0) return 10 * call(n/10) + n % 10;
    else return call(n/10); 

}

int biggestDigit(int n){
    if(n < 10) return n;

    return max(n%10, biggestDigit(n/10));
}


int main(){
    // if(unlucky(6378)) cout << "This is an unlucky number!\n";
    // else cout << "You're safe!\n"; 

    // for(int i = 0; i < 5; i++){
    //     cout << sumCubes(i) << "\n";
    // }

    cout << call(12346) << "\n";
    cout << biggestDigit(1234) << "\n";

    // cout << "The largest digit within the sequence: " << biggestDigit(12389) << "\n";

    // cout << "The sum of the following digits: " << sumDigits(1234) << "\n";

    return 0; 
}