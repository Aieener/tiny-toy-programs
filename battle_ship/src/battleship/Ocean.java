package battleship;

import java.util.*;

public class Ocean {
	private Ship[][] ships = new Ship[10][10];
	private boolean[][] isHited = new boolean[10][10];
	private int shotsFired;
	private int hitCount;

	/**
	 * the constructor
	 */
	public Ocean() {
		shotsFired = 0;
		hitCount = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				Ship emp = new EmptySea();
				ships[i][j] = emp;
				isHited[i][j] = false;
			}
		}
	}

	/**
	 * placeShipRandomly()
	 * place one ship into the ocean randomly
	 * @param s
	 */
	public void placeShipRandomly(Ship s){
		Random rand = new Random();
		// generate random number between 0 and 1
		double HororVer = Math.random();

		if (HororVer > 0.5) {
			// horizontal battleship
			int maxbow = 10 - s.getLength();
			// random number between 0 and 9
			int brow = rand.nextInt(10);
			// random number between 0 and maxbow
			int bcol = rand.nextInt(maxbow + 1);
			while (!s.okToPlaceShipAt(brow, bcol, true, this)) {
				brow = rand.nextInt(10);
				bcol = rand.nextInt(maxbow + 1);
			}
			s.placeShipAt(brow, bcol, true, this);
		} else {
			// vertical battleship
			int maxbow = 10 - s.getLength();
			// random number between 0 and maxbow
			int brow = rand.nextInt(maxbow + 1);
			// random number between 0 and 9
			int bcol = rand.nextInt(10);
			while (!s.okToPlaceShipAt(brow, bcol, false, this)) {
				brow = rand.nextInt(maxbow + 1);
				bcol = rand.nextInt(10);
			}
			s.placeShipAt(brow, bcol, false, this);
		}
	}

	/**
	 * placeAllShipsRandomly()
	 * Place the ships onto ocean randomly
	 */
	public void placeAllShipsRandomly() {
		// first place the battleship x 1
		Battleship b = new Battleship();
		placeShipRandomly(b);

		// Next place the 2 Cruiser
		int num = 0;
		while (num < 2) {
			Cruiser c = new Cruiser();
			placeShipRandomly(c);
			num++;
		}

		// Next place the 3 Destroyer
		num = 0;
		while (num < 3) {
			Destroyer d = new Destroyer();
			placeShipRandomly(d);
			num++;
		}

		/// Last place the 4 submarine
		num = 0;
		while (num < 4) {
			Submarine s = new Submarine();
			placeShipRandomly(s);
			num++;
		}
	}

	/**
	 * isOccupied()
	 * Returns​ true​ if the given location contains a ship, ​ 
	 * false​ if it does not. 
	 * @param row
	 * @param column
	 * @return
	 */
	public boolean isOccupied(int row, int column) {
		if (ships[row][column].getShipType() != "emptysea") {
			return true;
		} else {
			return false;
		}
	}

	/**
	 * shootAt()
	 * Returns ​ true​ if the given location contains a "real" ship, 
	 * still afloat, (not an ​ EmptySea​ ), false​ if it does not.
	 * @param row
	 * @param column
	 * @return
	 */
	public boolean shootAt(int row, int column) {
		isHited[row][column] = true;
		shotsFired++;
		if (isOccupied(row, column)) {
			// check if the ship is still afloat
			if (!ships[row][column].isSunk()) {
				if (ships[row][column].shootAt(row, column)) {
					hitCount++;
					return true;
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

	/**
	 * getShotsFired()
	 * Returns the number of shots fired
	 * @return
	 */
	public int getShotsFired() {
		return shotsFired;
	}

	/**
	 * getHitCount()
	 * Returns the number of hits recorded 
	 * @return
	 */
	public int getHitCount() {
		return hitCount;
	}

	/**
	 * isGameOver()
	 * Returns true​ if all ships have been sunk, otherwise​ false​ . 
	 * @return
	 */
	public boolean isGameOver() {
		// game is over if all ship are sunk
		for (Ship[] shiprow : ships) {
			for (Ship ship : shiprow) {
				if (ship.getShipType() != "emptysea" && !ship.isSunk()) {
					return false;
				}
			}
		}
		return true;
	}

	public Ship[][] getShipArray() {
		return ships;
	}

	/**
	 * print()
	 * Prints the ocean. 
	 */
	public void print() {
		int i, j, row, col;
		i = j = row = col = 0;
		System.out.print("  ");
		while (i <= 9) {
			System.out.print(i + " ");
			i++;
		}
		System.out.print("\n");
		for (Ship[] shiprow : ships) {
			System.out.print(j + " ");
			col = 0;
			for (Ship ship : shiprow) {
				String shipstatus = ship.toString() + " ";
				if (isHited[row][col]) {
					System.out.print(shipstatus);
				} 
				else {
					System.out.print(". ");
				}
				col++;
			}
			System.out.print("\n");
			j++;
			row++ ;
		}
	}
}
