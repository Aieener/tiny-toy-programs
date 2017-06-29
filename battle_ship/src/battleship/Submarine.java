package battleship;

public class Submarine extends Ship {
	/**
	 * the constructor
	 */
	public Submarine(){
		length = 1;
		for(int i = 0; i<length;i++){
			hit[i] = false;
		}
	}

	/**
	 * getLength()
	 * get the length of submarine
	 */
	@Override
	protected int getLength() {
		return length;
	}

	/**
	 * getShipType()
	 * get the shiptype of submarine
	 */
	@Override
	public String getShipType() {
		return "submarine";
	}
}
