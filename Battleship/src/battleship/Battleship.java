package battleship;

public class Battleship extends Ship {
	
	/**
	 * the constructor
	 */
	public Battleship(){
		length = 4;
		for(int i = 0; i<length;i++){
			hit[i] = false;
		}
	}

	/**
	 * getLength()
	 * get the length for battleship
	 */
	@Override
	protected int getLength() {
		return length;
	}

	/**
	 * getShipType()
	 * get the ship type for battleship
	 */
	@Override
	public String getShipType() {
		return "battleship";
	}
}
