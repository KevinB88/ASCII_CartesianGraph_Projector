#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;

//* Calculate the unique sum cardinality for a given positive integer n


bool isPrime(int N){
    if(N <= 1) return false;

    if(N <= 3) return true;

    if(N % 2 == 0 || N % 3 == 0) return false; 

    for(int i = 5; i * i <= N; i += 6){
        if(N % i == 0 || N % (i + 2) == 0) return false;
    }

    return true; 
}


int USC(int N){
    return floor((sqrt(1 + 8*N) - 1) / 2);
}

template<typename T>
void print(const vector<T>&container, bool TIMED, long long TIMER){
    
    
    for(auto& i : container){

        cout << i << " ";
        if(TIMED) this_thread::sleep_for(chrono::milliseconds(TIMER)); 
    }
    cout << "\n"; 
}


void print_primes(vector<int>&container){
    
    for(int& i : container){
        if(isPrime(i)) cout << i << " ";
    }
        cout << "\n"; 
}


vector<int> USC_LIST(int N){
    
    // Cardinality
    int C = USC(N); 
    vector<int> LIST(C,0); 

    for(int i = 0; i < C; i++) LIST[i] = i + 1; 

    int SUM = 0;
    for(int i : LIST) SUM += i; 

    if(SUM == N) return LIST; 

    int D = N - SUM;

    for(int i = C - 1; i >= C - D; i--) LIST[i]++;

    return LIST;
}



int main(){

    //Generate the unique set cardinality list for a provided input integer.
    
    // while(true){

    // int USER_INPUT; 
    // std::cout << "Enter a positive integer value: ";
    // std::cin >> USER_INPUT; 

    // while(USER_INPUT <= 0){
    //     std::cout << "Please enter a positive integer value: ";
    //     std::cin >> USER_INPUT; 
    // }

    // vector<int>list = USC_LIST(USER_INPUT);
    
    // std::cout << "Corresponding unique sequence for: " << USER_INPUT << ":\n";
    
    // print(list); 

    // cout << "\n" << "\n";

    // }


    int N = 1, J = 1;

    while(true){

        vector<int>list = USC_LIST(N); 
        
        if(list.size() > J){   
            J = list.size(); 
            this_thread::sleep_for(chrono::milliseconds(50)); 
             cout << "\n";
        }
        else this_thread::sleep_for(chrono::milliseconds(10)); 

        cout << N << ": ";
        // print(list, false, 0); 
        print_primes(list); 

        N++;
}

    return 0;
}
/*
   


*/