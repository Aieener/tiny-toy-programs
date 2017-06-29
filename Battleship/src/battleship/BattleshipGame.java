package battleship;

import java.util.*;

public class BattleshipGame {

	/**
	 * getlocation: get a location from user to shoot at
	 * 
	 * @param roworcol
	 * @param sc
	 * @return an integer to specify row and column
	 */
	public static int getlocation(String roworcol, Scanner sc) {
		int result;
		String input;
		while (true) {
			System.out.print(roworcol);
			input = sc.nextLine();
			try {
				result = Integer.parseInt(input);
				if (result >= 0 && result <= 9) {
					break;
				} else {
					System.out.println("Invalid entry. Please enter an integer between 0 and 9.");
				}
			} catch (NumberFormatException nfe) {
				System.out.println("Invalid entry. Please enter an integer between 0 and 9.");
			}
		}
		return result;
	}

	/**
	 * playagain() 
	 * Ask the use if they want to play again
	 * @param sc
	 * @return true or false
	 */
	public static boolean playagain(Scanner sc) {
		String input;
		boolean askagain = true;
		boolean play = true;
		while (askagain) {
			System.out.print("Do you want to play again? (y(Y) or n(N))\n");
			input = sc.nextLine();
			if (input.startsWith("Y") || input.startsWith("y")) {
				askagain = false;

			} else if (input.startsWith("N") || input.startsWith("n")) {
				System.out.print("See you next time! :)\n");
				askagain = false;
				play = false;
			} else {
				System.out.print("Please enter y(Y) or n(N)\n");
			}
		}
		return play;
	}

	/**
	 * the main function to set up the game
	 * 
	 * @param args
	 */

	public static void main(String[] args) {
		// Print out welcome message
		System.out.print("==========================\n");
		System.out.print("Welcome to the Battleship!\n");
		System.out.print("Have Fun! :) \n");
		System.out.print("==========================\n");
		int row, col;

		Scanner sc = new Scanner(System.in);
		boolean play = true;
		while (play) {
			Ocean o = new Ocean();
			o.placeAllShipsRandomly();

			// ----------------- start the game ----------------------
			while (!o.isGameOver()) {
				int counter = o.getShotsFired() + 1;
				System.out.print("--------------------------\n");
				System.out.print("    Round " + counter + "\n");
				System.out.print("--------------------------\n");
				o.print();

				System.out.println("Please give a position to shot at:");

				row = getlocation("Row: ", sc);
				col = getlocation("Col: ", sc);

				if (o.shootAt(row, col)) {
					// check if the ship just get hit is sunk
					if (o.getShipArray()[row][col].isSunk()) {
						String message = "You just sank a " + o.getShipArray()[row][col].getShipType() + "!";
						System.out.println(message);
					}
				}
			}

			// When game is over, print out Congrats message:
			o.print();
			System.out.print("==========================\n");
			System.out.print("Congratulations!\nAll ships are sunked! LOL\n");
			String hcount = "Hit Count: " + o.getHitCount();
			String scount = "Shots Fired: " + o.getShotsFired();
			System.out.print("==========================\n");
			System.out.println(hcount);
			System.out.println(scount);

			// --------- ask user if they want to play again-----------
			play = playagain(sc);
		}
		sc.close();
	}
}
