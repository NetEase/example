package dependency;

public class Dependency {
	
	private final String _value;
	
	public Dependency(final String value) {

		_value = value;
	}
	
	public String execute() {

		return _value + ", world!";
	}
}
