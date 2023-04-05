#include "Ship.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int main()
{

    Ship Frigate("F", 2);
    Ship Sub("S", 3);
    Ship Destroyer("D", 3);
    Ship Batteleship("B", 4);
    Ship AircraftCarrier("A", 5);

    /*Frigate.initial = 'F';
    Sub.initial = 'S';
    Destroyer.initial = 'D';
    Batteleship.initial = 'B';
    AircraftCarrier.initial = 'A';

    Frigate.size = 2;
    Sub.size = 3;
    Destroyer.size = 3;
    Batteleship.size = 4;
    AircraftCarrier.size = 5;*/

    Ship arr[5] = { Frigate, Sub, Destroyer, Batteleship, AircraftCarrier };
    srand(time(NULL));
    std::string board[10][10];
    bool occupied = false;

    //This creates the board.
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = "[ ]";
        }
    }

    //This determinds the direction of ships
    for (int i = 0; i < arr[i].size; i++) {
        occupied = true;
        while (occupied) {
            occupied = false;
            int HorV = rand() % 2;
            if (HorV == 0) {
                // Vertical
                int r = rand() % (10 - arr[i].size + 1);
                int c = rand() % 10;

                for (int j = 0; j < arr[i].size; ++j) {
                    if (board[r + j][c] != "[ ]") // not empty!
                        occupied = true;
                }
                if (!occupied) {
                    for (int j = 0; j < arr[i].size; ++j) {
                        board[r + j][c] = "[" + arr[i].initial + ']';
                    }
                }
            }
            else {
                // Horizontal
                int r = rand() % 10;
                int c = rand() % (10 - arr[i].size + 1);

                for (int j = 0; j < arr[i].size; ++j) {
                    if (board[r][c + j] != "[ ]") // not empty!
                        occupied = true;
                }
                if (!occupied) {
                    for (int j = 0; j < arr[i].size; ++j) {
                        board[r][c + j] = "[" + arr[i].initial + ']';
                    }
                }
            }
        }
    }

    // //This places ships randomly.
    // for(int i = 0; i < 5; i++){
    //       int r = rand() % 10;
    //       int c = rand() % 10;
    //     board[r][c] = arr[i].initial;
    //      if(board[r][c] != "[ ]"){
    //          board[r][c] = "[" + board[r][c] + "]";
    //      }
    //}

  //This prints out result.
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
