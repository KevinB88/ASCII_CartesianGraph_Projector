#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <vector> 
#include "PositionalVector.cpp"
#include "MatrixOperations.cpp"

/*
    1/23/2024: 5:09 AM
    *Personal note:
        
        *Clean up the code, simplify the syntax for readibility purposes.
        !Optimze features
*/

using namespace std;

template<typename T1, typename T2>
void print_pair(pair<T1,T2>pair){
    cout << pair.first << ", " << pair.second; 
}

template<typename X, typename Y>
void print_2D_points(pair<X,Y>pair){
    cout << "(" << pair.first << "," << pair.second << ")"; 
}

double radian_conversion(double degrees){
    return (degrees * M_PI)/180.0;
}

int main(){

    bool Q1, Q2, Q3, Q4; 

    double a = 0, b = 90, c = 180, d = 270, e = 360;

    b = radian_conversion(b);
    c = radian_conversion(c);
    d = radian_conversion(d);
    e = radian_conversion(e);

        //* CONTROL ZONE:
                //*Initial drawing positions (from the X-axis)
                int A = 0; 
                int B = 15;
                //*Initial drawing positions (from the X-axis)

            bool toggleVanish = true;
            bool toggleSpiral = true;
            double spiral_index = 0.001;
            double scalar = 8;
            double magnitude = 2.125;
            int timeScale = 15;
            char filler = ' ';
            char symbol_A = '>';
            char symbol_B = '*';
        //* CONTROL ZONE:

            /*
                Cool combos:
                    filler: '|'
                    symbol: '/'

                    filler: '@'
                    symbol = '.'

                    filler: '~'
                    symbol: '@'

                Animation set:

                    "Shark in the water"

                    toggleVanish = true
                    filer = '~'
                    symbol = '^'
        
                        "Dominos!"

                        bool toggleVanish = false;
                        bool toggleSpiral = true;
                        double spiral_index = 0.001;
                        double scalar = 8;
                        double magnitude = 2.125;
                        int timeScale = 15;
                        char filler = '|';
                        char symbol_A = '/';
                        char symbol_B = '_';
            */


    pair<int,int>bound = {scalar*(magnitude*cos(a)),scalar*magnitude*sin(a)};
   
    // vector<vector<int>>q1(bound.first, vector<int>(bound.first,0));
    // vector<vector<int>>q2(bound.first, vector<int>(bound.first,0));
    // vector<vector<int>>q3(bound.first, vector<int>(bound.first,0));
    // vector<vector<int>>q4(bound.first, vector<int>(bound.first,0));

    // vector<vector<vector<int>>>graph = {q2,q1,q3,q4};

  

    vector<vector<char>>q1(bound.first,vector<char>(bound.first,filler));
    vector<vector<char>>q2(bound.first,vector<char>(bound.first,filler));
    vector<vector<char>>q3(bound.first,vector<char>(bound.first,filler));
    vector<vector<char>>q4(bound.first,vector<char>(bound.first,filler));

    vector<vector<vector<char>>>graph = {q1,q2,q3,q4};

    graph_print(graph);

    pair<int,int>point_A, point_B;

     while(true){

        cout << "Point A: " << A << " degrees." << "\t" << "Point B: " << B << " degrees.\n";
        A++;
        B++;

        A %= 360;
        B %= 360;

        double radians_A = (A * M_PI) / 180.0;
        double radians_B = (B * M_PI) / 180.0;

        double A_X = magnitude * cos(radians_A);
        double A_Y = magnitude * sin(radians_A);

        double B_X = magnitude * cos(radians_B);
        double B_Y = magnitude * sin(radians_B); 

        int translated_A_X = A_X * scalar; 
        int translated_A_Y = A_Y * scalar; 

        int translated_B_X = B_X * scalar;
        int translated_B_Y = B_Y * scalar;

            this_thread::sleep_for(chrono::milliseconds(timeScale));

        cout << "A: " << "(" << A_X << "," << A_Y << ").\n";
        cout << "B: " << "(" << B_X << "," << B_Y << ").\n";

        point_A = {translated_A_X, translated_A_Y};
        point_B = {translated_B_X, translated_B_Y};
        
        // symbol_A

        if(A >= 0 && A <= 90){
            point_translation(graph[1], point_A, 1, symbol_A);
            Q1 = true;
        }
        else if(A > 90 && A <= 180){
            point_translation(graph[0], point_A, 2, symbol_A);
            Q2 = true;
        }
        else if(A > 180 && A <= 270){
            point_translation(graph[2], point_A, 3, symbol_A);
            Q3 = true;
        }
        else if(A > 270 && A <= 360){
            point_translation(graph[3], point_A, 4, symbol_A);
            Q4 = true;
        }

          
        if(B >= 0 && B <= 90){
            point_translation(graph[1], point_B, 1, symbol_B);
            Q1 = true;
        }
        else if(B > 90 && B <= 180){
            point_translation(graph[0], point_B, 2, symbol_B);
            Q2 = true;
        }
        else if(B > 180 && B <= 270){
            point_translation(graph[2], point_B, 3, symbol_B);
            Q3 = true;
        }
        else if(B > 270 && B <= 360){
            point_translation(graph[3], point_B, 4, symbol_B);
            Q4 = true;
        }

          graph_print(graph);



        if(toggleVanish){
            if(Q1) quadrant_wipe_char(graph[1],filler);
            if(Q2) quadrant_wipe_char(graph[0],filler);
            if(Q3) quadrant_wipe_char(graph[2],filler);
            if(Q4) quadrant_wipe_char(graph[3],filler);
        }
        
        Q1 = false, Q2 = false, Q3 = false, Q4 = false;

        if(toggleSpiral){
            magnitude -= spiral_index;
            cout << magnitude << "\n";

                if(magnitude < 0) break;
        }
     }

    return 0;
}

