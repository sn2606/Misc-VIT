import java.util.NoSuchElementException;
import java.util.HashSet;
import java.util.Set;
//import java.util.Hashtable;

class Node {
	int x = 12;
	
	void display() {
		System.out.println(x);
	}
}


public class NestTry {
	void printWorld(byte[] barr) {
		System.out.println("World");
		try {
			int a = 0;
			int b = 42/a;
			System.out.println(a + " " + b);
		} catch (ArithmeticException e) {
			System.out.println(e);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try {
			System.out.println("Hello");
			byte[] b = "Swara".getBytes();
			new NestTry().printWorld(b);
			
			try {
				Set<String> s = new HashSet<String>();
				System.out.println(s.iterator().next());				
			} catch (NoSuchElementException e) {
				System.out.println(e);
			}
			
			Node n = null;
			n.display();
			 
		} catch (NullPointerException e) {
			System.out.println(e);
		} catch (Exception e) {
			System.out.println(e);
		}

	}

}
