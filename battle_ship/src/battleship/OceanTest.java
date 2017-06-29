package battleship;

import static org.junit.Assert.*;

import org.junit.*;

public class OceanTest {
	Ocean o;
	Battleship bs;
	Cruiser cr;
	Destroyer dt;
	Submarine sb;

	@Before
	public void setUp(){
		o = new Ocean();
		bs = new Battleship();
		cr = new Cruiser();
		dt = new Destroyer();
		sb = new Submarine();
	}

	@Test
	public void testisOccupied() {
		assertFalse(o.isOccupied(1, 3));
		sb.placeShipAt(1, 3, true, o);
		assertTrue(o.isOccupied(1, 3));
		assertFalse(o.isOccupied(4, 3));
		sb.placeShipAt(4, 3, true, o);
		assertTrue(o.isOccupied(4, 3));
		

		assertFalse(o.isOccupied(0, 0));
		sb.placeShipAt(0, 0, true, o);
		assertTrue(o.isOccupied(0, 0));
		assertFalse(o.isOccupied(0, 9));
		sb.placeShipAt(0, 9, true, o);
		assertTrue(o.isOccupied(0, 9));
		assertFalse(o.isOccupied(9, 9));
		sb.placeShipAt(9, 9, true, o);
		assertTrue(o.isOccupied(9, 9));
		assertFalse(o.isOccupied(9, 0));
		sb.placeShipAt(9, 0, true, o);
		assertTrue(o.isOccupied(9, 0));
	}
	
	@Test
	public void testshooAt(){
		bs.placeShipAt(5, 5, true, o);
		assertFalse(o.shootAt(5, 4));
		assertTrue(o.shootAt(5, 5));
		assertTrue(o.shootAt(5, 6));
		assertTrue(o.shootAt(5, 7));
		assertTrue(o.shootAt(5, 8));
		assertFalse(o.shootAt(5, 9));
	}
	
	@Test
	public void testgetShotsFired(){
		assertEquals(o.getShotsFired(),0);
		o.shootAt(0, 0);
		assertEquals(o.getShotsFired(),1);
		o.shootAt(3, 8);
		assertEquals(o.getShotsFired(),2);
	}
	
	@Test
	public void testgetHitCount(){
		assertEquals(o.getHitCount(),0);
		o.shootAt(0, 0);
		assertEquals(o.getHitCount(),0);
		o.shootAt(3, 8);
		assertEquals(o.getHitCount(),0);
		cr.placeShipAt(5, 3, false, o);
		o.shootAt(5, 3);
		assertEquals(o.getHitCount(),1);
		o.shootAt(5, 3);
		assertEquals(o.getHitCount(),2);
		o.shootAt(6, 3);
		assertEquals(o.getHitCount(),3);
		o.shootAt(7, 3);
		assertEquals(o.getHitCount(),4);
		o.shootAt(7, 3);
		o.shootAt(6, 3);
		o.shootAt(5, 3);
		assertEquals(o.getHitCount(),4);
	}
	
	@Test
	public void testisGameOver(){
		assertTrue(o.isGameOver());
		dt.placeShipAt(0, 0, false, o);
		assertFalse(o.isGameOver());
		o.shootAt(0, 0);
		assertFalse(o.isGameOver());
		o.shootAt(1, 0);
		assertTrue(o.isGameOver());
				
	}

	@Test
	public void testgetShipArray(){
		assertEquals(o.getShipArray()[4][4].getLength(),1);
		assertEquals(o.getShipArray()[4][4].getShipType(),"emptysea");
		bs.placeShipAt(4, 4, false, o);
		assertEquals(o.getShipArray()[4][4].getShipType(),"battleship");
		assertEquals(o.getShipArray()[4][4].getLength(),4);
	}
}
