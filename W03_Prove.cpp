
//Setup library for program.
#include <iostream>
using namespace std;


//Game board array
char board [3][3] = {{1,2,3},{4,5,6},{7,8,9}};

//Variables and declarations
int PlayerInput;
int row;
int column;
char PlayerPiece = 'X';
bool draw = false;

//Layout of gameboard
int DisplayBoard()
{
    cout<<"    |    |    \n";
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
    cout<<"____|____|____\n";
    cout<<"    |    |    \n";
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
    cout<<"____|____|____\n";
    cout<<"    |    |    \n";
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
    cout<<"    |    |    \n";  
}

//Function that take player input and places it onto the game board.
void PlayerTurn(){
    if (PlayerPiece == 'X'){
        cout<<"Player 1's turn";
    }
    else if (PlayerPiece == 'O'){
        cout<<"Player 2's turn";
    }
//Code that takes player input.
    cin>> PlayerInput;

 //Code to evaluate a determine which space the player's piece will be place on.   
    switch(PlayerInput){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
    }

    //Code to update the locations of the X and O symbols.
    if (PlayerPiece == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'X';
        PlayerPiece = 'O';
    }
    else if (PlayerPiece == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'O';
        PlayerPiece = 'X';
    }
    //Code for if the location wants to put a piece has already been filled.
    else {
        cout<<"Sorry that place has already been filled. Please choose a different spot.";
        PlayerTurn();
    }

    DisplayBoard();
}

//Conditions for a game over.
bool GameOver(){
    for(int i=0;i<3;i++)
// code that checks for row and column victories.
    {if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return true;
    }
    // code checks for diagonal victories.
    {
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return true;
    }

    {draw = true;
    return false;}
}

//The main function where the program begins running.
int main(){
    while(!GameOver()){
        DisplayBoard();
        PlayerTurn();
        GameOver();
    }
    if (PlayerPiece == 'X' && draw == false){
        cout<<"Congratulation! You won Player 1";
    }
    else if (PlayerPiece == 'O' && draw == false){
        cout<<"Congratulation! You won Player 2";
    }
    else
    cout<<"No winner. Draw";
}
