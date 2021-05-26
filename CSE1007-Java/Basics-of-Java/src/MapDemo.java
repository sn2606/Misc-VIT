import java.util.Collection;
import java.util.HashMap;

public class MapDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HashMap <String, String> name = new HashMap <String, String>();
		name.put("SJT", "SCOPE");
		name.put("TT", "SENSE");
		name.put("MB", "SMEC");
		name.put("SJT", "SITE");
		
		System.out.println(name);
		System.out.println(name.keySet());
//		System.out.println(name.values());
		
		Collection <String> val = name.values();
		
		for(String v : val) {
			System.out.println("Values: " + v);
		}
		
		System.out.println(name.get("SJT"));
		System.out.println("Does the hashmap contain TT as a key?: " + name.containsKey("TT"));
		System.out.println("Does the hashmap contain SELECT as a value?: " + name.containsValue("SELECT"));
		System.out.println(name.remove("TT"));
		System.out.println(name);
	}

}
