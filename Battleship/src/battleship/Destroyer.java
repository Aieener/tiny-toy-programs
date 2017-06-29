package battleship;

public class Destroyer extends Ship {

	/**
	 * constructor
	 */
	public Destroyer(){
		length = 2;
		for(int i = 0; i<length;i++){
			hit[i] = false;
		}
	}

	/**
	 * getLength()
	 * get the length for destroyer
	 */
	@Override
	protected int getLength() {
		return length;
	}

	/**
	 * getShipType()
	 * get the ship type for destroyer
	 */
	@Override
	public String getShipType() {
		return "destroyer";
	}
}
