#include <iostream>
#include <vector>
#include <cmath>
#include "MatrixOperations.cpp"
#include "PositionalVector.cpp"

using namespace std; 


pair<int,int>square(pair<int,int>point){
    return {point.first, pow(point.second,2)};
}

template<typename X, typename Y>
void print_pair(const pair<X,Y>&point){
    cout << "(" << point.first << "," << point.second << ").\n";
}

int main(){

    int bound = 5;

    vector<vector<int>>q1(bound,vector<int>(bound,0));

        // for(int i = 0; i < q1[0].size(); i++){
        //     point_translation(q1, )

        // }
    vector<vector<int>>q2(bound,vector<int>(bound,0)); 
    vector<vector<int>>q3(bound,vector<int>(bound,0)); 
    vector<vector<int>>q4(bound,vector<int>(bound,0)); 

    vector<vector<vector<int>>>graph = {q1,q2,q3,q4};

    pair<int,int>point = {1,2};

    print_pair(point);

    graph_print(graph); 



    return 0;
}