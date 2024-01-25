#include <iostream>
#include <vector>
#include <cmath>
#include "MatrixOperations.cpp"
#include "PositionalVector.cpp"

using namespace std; 

//! Move to a mathematics header file
pair<int,int>square(pair<int,int>point){
    return {point.first, pow(point.second,2)};
}

//!Important note: move all universal functions to a separate header file
template<typename X, typename Y>
void print_pair(const pair<X,Y>&point){
    cout << "(" << point.first << "," << point.second << ")\n";
}

 pair<pair<int,int>, int> generate_quadrant(pair<int,int>point, int& temp){

    pair<pair<int,int>, int> generated_point = {point,-1};

    //Q1 
    if(point.first > 0 && point.second > 0){
        generated_point.second = 1;
        temp = 1;
        return generated_point; 
    }
    //Q2
    else if(point.first < 0 && point.second > 0){
        generated_point.second = 2;
        return generated_point;
        temp = 0;
    }
    //Q3
    else if(point.first < 0 && point.second < 0){
        generated_point.second = 3;
        return generated_point;
        temp = 2;
    }
    //Q4
    else if(point.first > 0 && point.second < 0){
        generated_point.second = 4;
        return generated_point;
        temp = 3;
    }   
        cout << "ERROR: Invalid points: (" << point.first << "," << point.second << ").\n";
        return generated_point;
}

int main(){

    int bound = 5;

    vector<vector<int>>q1(bound,vector<int>(bound,0));
    vector<vector<int>>q2(bound,vector<int>(bound,0)); 
    vector<vector<int>>q3(bound,vector<int>(bound,0)); 
    vector<vector<int>>q4(bound,vector<int>(bound,0)); 

    vector<vector<vector<int>>>graph = {q2,q1,q3,q4};

    int temp; 

   pair<int,int>point = {-5,-5};

   pair<pair<int,int>, int> quadrant = generate_quadrant(point,temp);

    point_translation_version2(graph[temp],quadrant,1);

    graph_print(graph); 

    /*
        Possible implementation: 

        The user can simply enter the bounds of the graph, and which character type is being used
        to project the graph. 

        The user can then simply input the coordinate into the graph, and the graph will project 
        the point accordingly.

    */

    return 0;
}