package dependency;

import junit.framework.TestCase;

public class DependencyTest extends TestCase {

	public void testShouldAppendCommaWorldExclamationPointToEndOfString() throws Exception {

		assertEquals("Hello, world!", new Dependency("Hello").execute());
	}
}
