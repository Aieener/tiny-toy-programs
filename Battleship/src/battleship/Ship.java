package battleship;

public abstract class Ship {
	// Instance variables
	protected int bowRow;
	protected int bowColumn;
	protected int length;
	protected boolean horizontal;
	protected boolean[] hit = new boolean[4];

	protected abstract int getLength();

	// Getters
	/**
	 * getBowRow()
	 * just get the instance variable bowRow
	 * @return
	 */
	public int getBowRow() {
		return bowRow;
	}

	/**
	 * getBowColumn
	 * just get the instance variable bowColumn
	 * @return
	 */
	public int getBowColumn() {
		return bowColumn;
	}

	/**
	 * isHorizontal()
	 * check if the ship is horizontal
	 * @return
	 */
	public boolean isHorizontal() {
		return horizontal;
	}

	// Setters
	/**
	 * setBowRow()
	 * @param row
	 */
	public void setBowRow(int row) {
		this.bowRow = row;
	}

	/**
	 * setBowColumn
	 * @param column
	 */
	public void setBowColumn(int column) {
		this.bowColumn = column;
	}

	/**
	 * setHorizontal()
	 * @param horizontal
	 */
	public void setHorizontal(boolean horizontal) {
		this.horizontal = horizontal;
	}

	// other methods
	public abstract String getShipType();


	/**
	 * okTpPlaceShipAt
	 * Returns ​ true​ if it is okay to put a ship of this length with its bow in this 
	 * location, with the given orientation, and returns ​ false​ otherwise.
	 * @param row
	 * @param column
	 * @param horizontal
	 * @param ocean
	 * @return
	 */
	public boolean okToPlaceShipAt(int row, int column, boolean horizontal, Ocean ocean) {
		int maxbowpos = 10 - length;
		int jstart, jend, istart, iend;

		jstart = -1;
		jend = 2;
		istart = -1;
		iend = length + 1;

		if (horizontal) {
			if (column > maxbowpos) {
				// false if it is out of bound
				return false;
			} else {
				// the horizontal case
				for (int j = jstart; j < jend; j++) {
					for (int i = istart; i < iend; i++) {
						// first check bound as to consider the edge case (sits
						// on the corner or sides)
						if (row + j >= 0 && row + j <= 9 && column + i >= 0 && column + i <= 9) {
							if (ocean.isOccupied(row + j, column + i)) {
								return false;
							}
						}
					}
				}
				return true;
			}

		} else {
			if (row > maxbowpos) {
				// false if it is out of bound
				return false;
			} else {
				// the vertical case (swap i and j in row and column)
				for (int j = jstart; j < jend; j++) {
					for (int i = istart; i < iend; i++) {
						// first check bound as to consider the edge case (sits
						// on the corner or sides)
						if (row + i >= 0 && row + i <= 9 && column + j >= 0 && column + j <= 9) {
							if (ocean.isOccupied(row + i, column + j)) {
								return false;
							}
						}
					}
				}
				return true;
			}
		}
	}
	

	/**
	 * placeShipAt()
	 * Put the ship in the ocean
	 * @param row
	 * @param column
	 * @param horizontal
	 * @param ocean
	 */
	public void placeShipAt(int row, int column, boolean horizontal, Ocean ocean) {
		// place ship into ocean and update ocean
		if (horizontal) {
			// place the ship horizontally
			for (int i = 0; i < length; i++) {
				ocean.getShipArray()[row][column + i] = this;
				setBowColumn(column);
				setBowRow(row);
				setHorizontal(horizontal);
			}
		} else {
			// place the ship vertically
			for (int j = 0; j < length; j++) {
				ocean.getShipArray()[row + j][column] = this;
				setBowColumn(column);
				setBowRow(row);
				setHorizontal(horizontal);
			}
		}
	}

	/**
	 * shootAt()
	 * If a part of the ship occupies the given row and column, and the ship hasn't already 
	 * been sunk, mark that part of the ship as "hit" (in the ​ hit​ array, 0 indicates the 
	 * bow) and return true​ , otherwise return ​ false​ .
	 * @param row
	 * @param column
	 * @return
	 */
	public boolean shootAt(int row, int column) {

		if (!isSunk()) {
			// ship is not sunk yet
			if (horizontal) {
				// the horizontal case
				if (bowRow == row) {
					// bowRow has to be row to get shot
					for (int i = 0; i < length; i++) {
						if (bowColumn + i == column) {
							hit[i] = true;
							return true;
						}
					}
					return false;
				} else {
					return false;
				}
			} else {
				// the vertical case
				if (bowColumn == column) {
					// bowcolumn has to be column to get shot
					for (int i = 0; i < length; i++) {
						if (bowRow + i == row) {
							hit[i] = true;
							return true;
						}
					}
					return false;
				} else {
					return false;
				}
			}
		} else {
			return false;
		}

	}

	/**
	 * isSunk()
	 * Return ​ true​ if every part of the ship has been hit, false​ otherwise. 
	 * @return
	 */
	public boolean isSunk() {
		for (int i = 0; i < length; i++) {
			if (hit[i] == false) {
				return false;
			}
		}
		return true;
	}

	/**
	 * toString()
	 * This method should return​ "x"​ if the ship has been sunk, ​ "S"​ if it 
	 * has not been sunk. This method can be used to print out locations 
	 * in the ocean that have been shot at; it should ​ not ​ be used to 
	 * print locations that have ​ not ​ been shot at.
	 */
	@Override
	public String toString() {
		if (isSunk()) {
			return "x";
		} else {
			return "S";
		}
	}
}
