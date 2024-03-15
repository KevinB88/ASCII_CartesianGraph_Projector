#include <iostream>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

bool isPrime(int N) {
    if (N <= 1) return false;
    if (N <= 3) return true;
    if (N % 2 == 0 || N % 3 == 0) return false;
    for (int i = 5; i * i <= N; i += 6) {
        if (N % i == 0 || N % (i + 2) == 0) return false;
    }
    return true;
}

// Function to extract the first digit of a number
int firstDigit(int N) {
    while (N >= 10) {
        N /= 10;
    }
    return N;
}

int main() {
    int limit = pow(10, 4); // You can adjust this limit as needed
    vector<map<int, int>> prime_map_vector;
    map<int, int> prime_map;

    for (int exp = 1; exp <= limit; exp *= 10) {
        int next_exp = exp * 10;
        for (int i = exp; i < next_exp; i++) {
            if (isPrime(i)) {
                int first_digit = firstDigit(i);
                prime_map[first_digit]++;
            }
        }
        prime_map_vector.push_back(prime_map);
        prime_map.clear(); // Reset for the next range
    }

    // Output the frequencies for each starting digit for each power of 10
    for (size_t i = 0; i < prime_map_vector.size(); i++) {
        cout << "Primes with leading digit, power of 10^" << i << ":\n";
        for (auto &pair : prime_map_vector[i]) {
            cout << "Digit: " << pair.first << " Frequency: " << pair.second << "\n";
        }
        cout << "\n";
    }

    return 0;
}
