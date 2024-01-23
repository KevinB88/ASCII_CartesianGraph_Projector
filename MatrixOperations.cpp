#include <iostream>
#include <vector>

using namespace std;

// vector<vector<vector<int>>>graph = {q2,q1,q3,q4};

template<typename T>
void graph_print(const vector<vector<vector<T>>>&graph){

    int height  = graph[0].size() + graph[1].size();
    int width   = graph[0].size() + graph[2].size(); 

        for(int i = 0; i < height; i++){

            for(int j = 0; j < width; j++){

                //Q1:
                if(i < graph[0].size() && j < graph[0][0].size()){
                    cout << graph[0][i][j] << " ";
                }
                //Q2:
                else if(i < graph[0].size() && j >= graph[0][0].size()){
                    cout << graph[1][i][j % graph[1][0].size()] << " ";
                }
                //Q3:
                else if(i >= graph[0].size() && j < graph[0][0].size()){
                    cout << graph[2][i % graph[2].size()][j] << " ";
                }
                //Q4:
                else if(i >= graph[0].size() && j >= graph[0][0].size()){
                    cout << graph[3][i % graph[2].size()][j % graph[3][0].size()] << " ";
                }
            }
                cout << "\n";
        }
}

template <typename T>
void quandrant_print(const vector<vector<T>>& quadrant){
    for(auto& row : quadrant){
        for(auto& column : row){
            cout << column << " ";
        }
            cout << "\n";
    }
}
   
void quadrant_wipe_int(vector<vector<int>>& quadrant){
    vector<vector<int>>x(quadrant.size(),vector<int>(quadrant.size(),0));
    quadrant = x;
}

void quadrant_wipe_char(vector<vector<char>>&quadrant, char filler){
    vector<vector<char>>x(quadrant.size(),vector<char>(quadrant.size(),filler));
    quadrant = x;
}

// int main(){

//     vector<vector<int>>q1(2,vector<int>(2,0));

//     quandrant_print(q1);

//     cout << "\n";

//     vector<vector<int>>q2(2,vector<int>(2,0));
//     vector<vector<int>>q3(2,vector<int>(2,0));
//     vector<vector<int>>q4(2,vector<int>(2,0));

//     vector<vector<vector<int>>>graph = {q2,q1,q3,q4};

//     graph_print(graph);

//     return 0;
// }

