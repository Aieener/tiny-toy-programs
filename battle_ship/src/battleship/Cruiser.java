package battleship;

public class Cruiser extends Ship {

	/**
	 * the constructor
	 */
	public Cruiser(){
		length = 3;
		for(int i = 0; i<length;i++){
			hit[i] = false;
		}
	}

	/**
	 * getLength()
	 * get the length for Cruiser
	 */
	@Override
	protected int getLength() {
		return length;
	}

	/**
	 * getShipType()
	 * get the ship type for cruiser
	 */
	@Override
	public String getShipType() {
		return "cruiser";
	}
}
