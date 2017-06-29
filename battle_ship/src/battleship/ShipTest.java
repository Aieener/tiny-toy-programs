package battleship;

import static org.junit.Assert.*;

import org.junit.*;

public class ShipTest {
	Ocean o1;
	Battleship bs1;
	Cruiser cr1,cr2;
	Destroyer dt1,dt2,dt3;
	Submarine sb1,sb2,sb3,sb4;

	@Before
	public void setUp(){
		o1 = new Ocean();
		bs1 = new Battleship();
		cr1 = new Cruiser();
		dt1 = new Destroyer();
		sb1 = new Submarine();
	}

	@Test
	public void testOKtoplaseshipandplaceship() {
		// o1 is empty now test battleship
		// first test edge on the 4 corners: all should return true
		int bmaxbow = 10 - bs1.getLength();
		int cmaxbow = 10 - cr1.getLength();
		//hor
		assertTrue(bs1.okToPlaceShipAt(0, 0, true, o1));
		assertTrue(cr1.okToPlaceShipAt(0, 0, true, o1));
		assertTrue(bs1.okToPlaceShipAt(9, 0, true, o1));
		assertTrue(cr1.okToPlaceShipAt(9, 0, true, o1));
		assertTrue(bs1.okToPlaceShipAt(0, bmaxbow, true, o1));
		assertTrue(cr1.okToPlaceShipAt(0, cmaxbow, true, o1));
		assertTrue(bs1.okToPlaceShipAt(9, bmaxbow, true, o1));
		assertTrue(cr1.okToPlaceShipAt(9, cmaxbow, true, o1));

		//ver
		assertTrue(bs1.okToPlaceShipAt(0, 0, false, o1));
		assertTrue(cr1.okToPlaceShipAt(0, 0, false, o1));
		assertTrue(bs1.okToPlaceShipAt(0, 9, false, o1));
		assertTrue(cr1.okToPlaceShipAt(0, 9, false, o1));
		assertTrue(bs1.okToPlaceShipAt(bmaxbow, 0, false, o1));
		assertTrue(cr1.okToPlaceShipAt(cmaxbow, 0, false, o1));
		assertTrue(bs1.okToPlaceShipAt(bmaxbow, 9, false, o1));
		assertTrue(cr1.okToPlaceShipAt(cmaxbow, 9, false, o1));
		
		//Should return false if out of bound;
		assertFalse(bs1.okToPlaceShipAt(bmaxbow+1, 0, false, o1));
		assertFalse(bs1.okToPlaceShipAt(0, bmaxbow+1, true, o1));
		
		//Now place a battleship at (row = 1,column = 1) horizontally
		bs1.placeShipAt(1, 1, true, o1);
		assertTrue(o1.isOccupied(1, 4));
		assertTrue(o1.isOccupied(1, 3));
		assertTrue(o1.isOccupied(1, 2));
		assertTrue(o1.isOccupied(1, 1));
		assertFalse(o1.isOccupied(0, 0));
		assertFalse(o1.isOccupied(1, 0));
		assertFalse(o1.isOccupied(2, 0));
		assertFalse(o1.isOccupied(0, 5));
		assertFalse(o1.isOccupied(1, 5));
		assertFalse(o1.isOccupied(2, 5));
		for(int i = 0;i<3;i++){
			assertFalse(bs1.okToPlaceShipAt(i, 0, true, o1));
			assertFalse(bs1.okToPlaceShipAt(i, 1, true, o1));
			assertFalse(bs1.okToPlaceShipAt(i, 2, true, o1));
			assertFalse(bs1.okToPlaceShipAt(i, 3, true, o1));
			assertFalse(bs1.okToPlaceShipAt(i, 4, true, o1));
			assertFalse(bs1.okToPlaceShipAt(i, 5, true, o1));
			assertTrue(bs1.okToPlaceShipAt(i, 6, true, o1));

			assertFalse(dt1.okToPlaceShipAt(i, 0, true, o1));
			assertFalse(dt1.okToPlaceShipAt(i, 1, true, o1));
			assertFalse(dt1.okToPlaceShipAt(i, 2, true, o1));
			assertFalse(dt1.okToPlaceShipAt(i, 3, true, o1));
			assertFalse(dt1.okToPlaceShipAt(i, 4, true, o1));
			assertTrue(dt1.okToPlaceShipAt(i, 7, true, o1));
			assertTrue(dt1.okToPlaceShipAt(i, 8, true, o1));

		}
		//Place another battleship at (row = 5,column = 8) vertically
		bs1.placeShipAt(5, 8, false, o1);
		for(int i = 7;i<10;i++){
			assertTrue(bs1.okToPlaceShipAt(0, i, false, o1));
			assertFalse(bs1.okToPlaceShipAt(1, i, false, o1));
			assertFalse(bs1.okToPlaceShipAt(2, i, false, o1));
			assertFalse(bs1.okToPlaceShipAt(3, i, false, o1));
			assertFalse(bs1.okToPlaceShipAt(4, i, false, o1));
			assertFalse(bs1.okToPlaceShipAt(5, i, false, o1));
			assertFalse(bs1.okToPlaceShipAt(6, i, false, o1));

			assertTrue(dt1.okToPlaceShipAt(0, i, false, o1));
			assertTrue(dt1.okToPlaceShipAt(1, i, false, o1));
			assertTrue(dt1.okToPlaceShipAt(2, i, false, o1));
			assertFalse(dt1.okToPlaceShipAt(3, i, false, o1));
			assertFalse(dt1.okToPlaceShipAt(4, i, false, o1));
			assertFalse(dt1.okToPlaceShipAt(5, i, false, o1));
			assertFalse(dt1.okToPlaceShipAt(6, i, false, o1));
			assertFalse(dt1.okToPlaceShipAt(7, i, false, o1));
			assertFalse(dt1.okToPlaceShipAt(8, i, false, o1));
		}
		assertFalse(cr1.okToPlaceShipAt(0, 0, false, o1));
		assertFalse(cr1.okToPlaceShipAt(0, 5, false, o1));
		assertTrue(cr1.okToPlaceShipAt(0, 6, false, o1));
		
		assertFalse(cr1.okToPlaceShipAt(4, 5, true, o1)); // the diagonal adjacent case
		assertFalse(cr1.okToPlaceShipAt(4, 7, true, o1)); 
		assertFalse(cr1.okToPlaceShipAt(9, 7, true, o1)); 
		assertTrue(cr1.okToPlaceShipAt(3, 7, true, o1)); 

		// Test the edge case
		bs1.placeShipAt(3, 0, false, o1);
		assertFalse(cr1.okToPlaceShipAt(4, 1, false, o1)); 

		bs1.placeShipAt(9, 1, true, o1);
		assertFalse(cr1.okToPlaceShipAt(9, 5, true, o1)); 
		assertFalse(cr1.okToPlaceShipAt(9, 6, true, o1)); 
		assertTrue(cr1.okToPlaceShipAt(7, 2, true, o1)); 

	}
	
	@Test
	public void testgetShiptypeandlength() {
		assertEquals(o1.getShipArray()[4][4].getLength(),1);
		assertEquals(o1.getShipArray()[4][4].getShipType(),"emptysea");
		bs1.placeShipAt(4, 4, false, o1);
		assertEquals(o1.getShipArray()[4][4].getShipType(),"battleship");
		assertEquals(o1.getShipArray()[4][4].getLength(),4);
	}
	
	@Test
	public void testshootAtandisSunk(){
		cr1.placeShipAt(4, 7, true, o1);
		assertFalse(cr1.isSunk());
		cr1.shootAt(4, 7);
		assertFalse(cr1.isSunk());
		cr1.shootAt(4, 8);
		assertFalse(cr1.isSunk());
		cr1.shootAt(4, 9);
		assertTrue(cr1.isSunk());
	}
}
