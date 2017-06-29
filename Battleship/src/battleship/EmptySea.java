package battleship;

public class EmptySea extends Ship {

	/**
	 * the contructor
	 */
	public EmptySea(){
		length = 1;
	}

	/**
	 * getLength()
	 * get the length of an emptysea
	 */
	@Override
	protected int getLength() {
		return length;
	}

	/**
	 * getShipType
	 * get the ship type of an emptysea
	 */
	@Override
	public String getShipType() {
		return "emptysea";
	}
	
	/**
	 * shootAt()
	 * always return false when shots on an emptysea
	 */
	@Override
	public boolean shootAt(int row, int column){
		return false;
	}
	
	/**
	 * isSunk()
	 * empty is always sunk
	 */
	@Override
	public boolean isSunk(){
		return false;
	}
	
	/**
	 * toString()
	 * print "-" for emptysea when called
	 */
	@Override
	public String toString(){
		return "-";
	}

}
