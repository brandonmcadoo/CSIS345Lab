import java.util.Scanner;

/**
 * This is a text version of Tic-Tac-Toe
 *
 * @author Darren Lim
 * @version 1.0
 */
public class TicTacToe
{
    /**
     * An example of a method - replace this comment with your own
     *
     * @param  y  a sample parameter for a method
     * @return    the sum of x and y
     */
    public static String checkBoard(char[] pos){

        for(int i = 0; i < 3; i++){
            //checking for vertical and horizontal wins
            if(pos[i] == 'X' && pos[i+3] == 'X' && pos[i+6] == 'X' || pos[i] == 'X' && pos[i+1] == 'X' && pos[i+2] == 'X'){
                return "X";
            }
            else if(pos[i] == 'O' && pos[i+3] == 'O' && pos[i+6] == 'O' || pos[i] == 'O' && pos[i+1] == 'O' && pos[i+2] == 'O'){
                return "O";
            }
            //checking for diagonal wins
            else if(i == 0){
                if(pos[i] == 'X' && pos[i+4] == 'X' && pos[i+8] == 'X' || pos[i+2] == 'X' && pos[i+4] == 'X' && pos[i+6] == 'X'){
                    return "X";
                }
                else if(pos[i] == 'O' && pos[i+4] == 'O' && pos[i+8] == 'O' || pos[i+2] == 'O' && pos[i+4] == 'O' && pos[i+6] == 'O'){
                    return "O";
                }
            }
        }
        //no wins
        return "0";
    }

    /**
     * Prints the current board of the game
     *
     * @param  y  a sample parameter for a method
     */
    public static void printBoard(char[] pos)
    {
        //clears the screen
        System.out.print("\033[H\033[2J");
        System.out.flush();

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                System.out.print(pos[j + (i *3)] + "|");
            }
            System.out.print(pos[2 + (i * 3)]);
            System.out.print("\n" + "-----\n");
        }

        for(int i = 0; i < 2; i++){
            System.out.print(pos[6 + (i)] + "|");
        }
        System.out.print(pos[8] + "\n");

    }

    /**
     * Main method for Tic-Tac-Toe
     * 
     * @param   args    Commmand Line arguments 
     */
    public static void main(String args[])
    {
        char[] positions = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
        int input;
        int totalMoves = 0;
        Scanner scnr = new Scanner(System.in);

        System.out.print("Pick X or O to go first: ");
        String start = scnr.next();

        String throwAway = scnr.nextLine();

        if(!start.equals("X") && !start.equals("O")){
            System.out.println("Invalid input");
            System.exit(0);
        }


        boolean xTurn = start.equals("X");
        while (true)
        {
            printBoard(positions);

            if(xTurn){
                System.out.print("Place X [0-8]=>");
                try{
                    input = scnr.nextInt();
                    if(positions[input] != ' '){
                        System.out.println("Already taken");
                        xTurn = !xTurn;
                    } else {
                        positions[input] = 'X';
                        totalMoves++;
                    }
                }
                catch(Exception z){
                    System.out.println("Invalid input");
                    xTurn = !xTurn;
                }




            } else {
                System.out.print("Place O [0-8]=>");
                try{
                    input = scnr.nextInt();
                    if(positions[input] != ' '){
                        System.out.println("Already taken");
                        xTurn = !xTurn;
                    } else {
                        positions[input] = 'O';
                        totalMoves++;
                    }
                }
                catch(Exception z){
                    System.out.println("Invalid input");
                    xTurn = !xTurn;
                }
            }
            
            String result = checkBoard(positions);
            if (result == "X")
            {
                printBoard(positions);
                System.out.println("X wins");
                break;
            }
            else if (result == "O")
            {
                printBoard(positions);
                System.out.println("O wins");
                break;
            }
            else if(totalMoves == 9){
                printBoard(positions);
                System.out.println("Tie");
                break;
            }
            xTurn = !xTurn;
        }
        scnr.close();

    }
}
