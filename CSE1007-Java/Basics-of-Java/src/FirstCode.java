// Data Types tutorial

public class FirstCode {
	public static void main(String args[]) {
//		System.out.print("Hello, World");
		
		int num = 6;
		System.out.println(num);
		
		num = 78;
		System.out.println(num);
		
		num = 90_000_000;
		System.out.println(num);
		
		float percent = 5.5f;
		double percent2 = 5.5;
		
		System.out.print(percent + " ");
		System.out.print(percent2 + "\n");
		
		long l = 5000000000000l; // 8 bytes -> 64 bits
		int i = 454678;			 // 4 bytes -> 32 bits
		short s = 9085;          // 2 bytes -> 16 bits
		byte b = 78;			 // 1 byte  ->  8 bits
		
		System.out.println(l + " " + i + " " + s + " " + b + " ");
		
		char c = 'A';
		c = 69;					 // ASCII value corresponding to 69 is stored
		
		System.out.println(c);
		
		double d1 = 5;           // Implicit conversion (5 -> 5.0)
		int k = (int) 5.6;       // Type casting / Explicit conversion
		
		System.out.println(d1);
		System.out.println(k);		
		
	}

}
