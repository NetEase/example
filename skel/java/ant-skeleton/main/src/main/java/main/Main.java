package main;

import dependency.Dependency;

public class Main {
	
	public String greeting() {
		
		return new Dependency("Hello").execute();
	}
}
