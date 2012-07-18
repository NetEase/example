package main;

import junit.framework.TestCase;

public class MainTest extends TestCase {

	public void testShouldProduceFriendlyGreeting() throws Exception {

		assertEquals("Hello, world!", new Main().greeting());
	}
}
