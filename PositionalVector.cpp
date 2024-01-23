#include <iostream>
#include <vector>

using namespace std;

void space(){
    cout << "\n";
}

template<typename T>
void generate_bounds(vector<vector<T>>&matrix, int quadrant){

    cout << "Generated bounds: \n";

    int bound = matrix.size()-1; 
    

    switch(quadrant){
        case 1:
            cout << "(0,0)" << " -> " << "(" << bound << "," << bound << ")\n";
            return;
        case 2:
            cout << "(" << -1 * bound << "," << bound << ") -> (0,0)\n";
            return;
        case 3:
            cout << "(" << -1 * bound << "," << -1 * bound << ") -> (0,0)\n";
            return;
        case 4:
            cout << "(" << bound << "," << -1 * bound << ") -> (0,0)\n";
            return;
        default:
            cout << "ERROR: Invalid quadrant.\n";
            return;
    }
        cout << "\n";
}

template<typename T>
void point_translation(vector<vector<T>>&matrix, pair<int,int>point, int quadrant, T value){

    int t_X;
    int t_Y;
    pair<int,int>origin; 

    if(quadrant == 1){

        origin = {matrix.size()-1, 0};

        t_X = origin.first - point.second;
        t_Y = origin.second + point.first;

        if((t_X < 0 || t_X >= matrix.size()) || (t_Y < 0 || t_Y >= matrix.size())){
            space();
            cout << "Point: " << "(" << point.first << "," << point.second << "), out of bounds!\n";
            generate_bounds(matrix, quadrant);
            return;
        }
            matrix[t_X][t_Y] = value;
    }
    else if(quadrant == 2){

        origin = {matrix.size()-1,matrix.size()-1};

        /*
            some sample points:
            (-1,2)
            (-2,3)
            (-4,4)
        */
       t_X = origin.first - point.second;
       t_Y = origin.second - (-1 * point.first);
        
       if((t_X < 0 || t_X >= matrix.size()) || (t_Y < 0 || t_Y >= matrix.size())){
            space();
            cout << "Point: " << "(" << point.first << "," << point.second << "), out of bounds!\n";
            generate_bounds(matrix, quadrant);
            return;
        }
            matrix[t_X][t_Y] = value;
    }
    else if(quadrant == 3){

        origin = {0, matrix.size()-1};

        t_X = origin.first + (point.second * -1);
        t_Y = origin.second - (point.first * -1); 

        if((t_X < 0 || t_X >= matrix.size()) || (t_Y < 0 || t_Y >= matrix.size())){
            space();
            cout << "Point: " << "(" << point.first << "," << point.second << "), out of bounds!\n";
            generate_bounds(matrix, quadrant);
            return;
        }
            matrix[t_X][t_Y] = value;
    }
    else if(quadrant == 4){

       origin = {0,0};
        
        t_X = origin.first + point.first;
        t_Y = origin.second + (-1 * point.second);

       if((t_X < 0 || t_X >= matrix.size()) || (t_Y < 0 || t_Y >= matrix.size())){
            space();
            cout << "Point: " << "(" << point.first << "," << point.second << "), out of bounds!\n";
            generate_bounds(matrix, quadrant);
            return;
        }
            matrix[t_Y][t_X] = value;
    }
    else{
        cout << "ERROR: Invalid quadrant: " << quadrant << "\n";
        return; 
    }
}

template<typename T>
void print_matrix(const vector<vector<T>>&matrix){
    for(auto& row : matrix){
        for(auto& column : row){
            cout << column << " ";
        }
            cout << "\n"; 
    }
}

// int main(){

//     vector<vector<int>>matrix(5, vector<int>(5,0));

//     vector<vector<int>>q1 = matrix; 
//     vector<vector<int>>q2 = matrix;
//     vector<vector<int>>q3 = matrix;
//     vector<vector<int>>q4 = matrix;

//     // cout << "Quadrant I:\n";

//     // point_translation(q1,{4,2},1);
    
//     // print_matrix(q1);
//     // space();

//     // cout << "Quadrant II:\n";

//     // point_translation(q2,{0,0},2);

//     // print_matrix(q2);
//     // space();
  
//     // cout << "Quadrant III:\n";

//     // point_translation(q3,{-1,-1},3);
  
//     // print_matrix(q3);
//     // space();

//     cout << "Quadrant IV:\n";

//     point_translation(q4,{1,-3},4);

//     print_matrix(q4);
//     space();

//     return 0;
// }

