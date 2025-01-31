#include <iostream>
#include <cstdlib> //library for random number generation
#include <ctime> //library for time
using std::cin;
using std::cout;
using std::endl;
using std::string;

string checkBoard(char arr[3][3])
{
    // String result = "";
    // //FIRST CHECK HORIZONTAL
    // for (int row = 0; row < arr.length; row++) {
    //     if (arr[row][0] == (arr[row][1]) && arr[row][1] == (arr[row][2])) {
    //         result = arr[row][0];
    //         return result;
    //     }
    // }
    // //CHECK VERTICAL
    // for (int col = 0; col < arr[0].length; col++) {
    //     if (arr[0][col] == (arr[1][col]) && arr[1][col] == (arr[2][col])) {
    //         result = (arr[0][col]);
    //         return result;
    //     }
    // }
    // //CHECK DIAGONAL
    // if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
    //     result = (arr[0][1]);
    //     return result;
    // }

    // HARDCODED VERSION!!!
    if (arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X' || arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X' || arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X' || arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X' || arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X' || arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X' || arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X' || arr[2][0] == 'X' && arr[1][1] == 'X' && arr[0][2] == 'X')
        return "X";
    if (arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O' || arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O' || arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O' || arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O' || arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O' || arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O' || arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O' || arr[2][0] == 'O' && arr[1][1] == 'O' && arr[0][2] == 'O')
        return "O";
    return "0";
}

/**
 * Prints the current board of the game
 *
 * @param  y  a sample parameter for a method
 */
void printBoard(char grid[3][3])
{
    //clear terminal
    cout << ("\033[2J\033[1;1H");

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (col != 2)
            {
                cout << grid[row][col];
                cout << "|";
            }
            else
            {
                cout << (grid[row][col]);
            }
        }
        cout << ("\n");
        cout << ("-----\n");
    }
}

/**
 * Main method for Tic-Tac-Toe
 *
 * @param   args    Command Line arguments
 */
int main()
{
    srand(time(0));

    int replay = 0; // 0 is yes 1 is no
    char grid[3][3];

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            grid[row][col] = ' ';
        }
    }

    int xWins = 0;
    int oWins = 0;
    int ties = 0;



    // GAME START DIALOGUE
    while (replay == 0)
    {
        for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            grid[row][col] = ' ';
        }
    }

        cout << "What player should start [X or O]=>" << endl;
        string player;
        cin >> player;

        int userRow;
        int userCol;
        string result;
        int spacesFilled = 0;
        while (true)
        {

            // PLAYER X TURN
            while (player == "X")
            {
                while (true)
                {
                    cout << "Pick a row to place X[0-2 0r 3 for random]=>" << endl;
                    cin >> userRow;
                    if (userRow == 3){
                        userRow = rand() % 3;
                        userCol = rand() % 3;
                        while(grid[userRow][userCol] != ' '){
                            userRow = rand() % 3;
                            userCol = rand() % 3;
                        }
                    } else {
                        cout << "Pick a column to place X[0-2]=>";
                        cin >> userCol;
                    }

                    if (grid[userRow][userCol] == ' ')
                    {
                        grid[userRow][userCol] = 'X';
                        spacesFilled++;
                        break;
                    }

                    cout << ("ERROR: That space is already filled, please try again.") << endl;
                }

                printBoard(grid);
                player = "O";
            }

            result = checkBoard(grid);
            if (result == "X")
            {
                cout << ("X wins") << endl;
                xWins++;
                break;
            }
            else if (result == "O")
            {
                cout << ("O wins") << endl;
                oWins++;
                break;
            }
            else if (spacesFilled == 9)
            {
                cout << ("It's a TIE") << endl;
                ties++;
                break;
            }

            // O Player Turn
            while (player == "O")
            {
                while (true)
                {
                    cout << "Pick a row to place X[0-2 0r 3 for random]=>" << endl;
                    cin >> userRow;
                    if (userRow == 3){
                        userRow = rand() % 3;
                        userCol = rand() % 3;
                        while(grid[userRow][userCol] != ' '){
                            userRow = rand() % 3;
                            userCol = rand() % 3;
                        }
                    } else {
                        cout << "Pick a column to place X[0-2]=>";
                        cin >> userCol;
                    }

                    if (grid[userRow][userCol] == ' ')
                    {
                        grid[userRow][userCol] = 'O';
                        spacesFilled++;
                        break;
                    }

                    cout << ("ERROR: That space is already filled, please try again.") << endl;
                }
                printBoard(grid);
                player = "X";
            }

            result = checkBoard(grid);
            if (result == "X")
            {
                cout << ("X wins") << endl;
                xWins++;
                break;
            }
            else if (result == "O")
            {
                cout << ("O wins") << endl;
                oWins++;
                break;
            }
            else if (spacesFilled == 9)
            {
                cout << ("It's a TIE") << endl;
                ties++;
                break;
            }
        }
        cout << ("X Wins: ") << xWins << endl;
        cout << ("O Wins: ") << oWins << endl;
        cout << ("Ties: ") << ties << endl;

        cout << ("Would you like to play again? [0 for yes, 1 for no]") << endl;
        string replayString;
        cin >> replayString;
        if(replayString == "1"){
            replay = 1;
        }

    }

    return 0;
}
