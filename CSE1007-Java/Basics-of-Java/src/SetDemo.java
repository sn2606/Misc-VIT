import java.util.HashSet;

public class SetDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HashSet <String> school = new HashSet<String>();
		HashSet <String> school2 = new HashSet<String>();
		school.add("SCOPE");
		school.add("SITE");
		school.add("SELECT");
		school.add("SITE"); // repeated value wont be added
		// set has unique values
		
		school2.add("SMEC");
		school2.add("SELECT");
		school2.add("SSL");
		
		System.out.println("Set Values: " + school);
		System.out.println("Size of set: " + school.size());
		System.out.println("Is SELECT present?: " + school.contains("SELECT"));
		System.out.println("Removing SITE: " + school.remove("SITE"));
		System.out.println("After removal: " + school);
		System.out.println("HashCode: " + school.hashCode());
		System.out.println("Adding other set: " + school.addAll(school2));
		System.out.println("New set: " + school); // unique values maintained
		// both school  and school2 has SELECT, but in final school set, SELECT is present only once
		

	}

}
