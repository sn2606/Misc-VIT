
public class MultiCatch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try {
			int a = args.length;
			System.out.println("a = " + a);
			int b = 42/a;
			int c[] = {1};
			c[42] = 99;			
		} catch (ArithmeticException e) {
			System.out.println("Division by 0: " + e);
			throw new ArithmeticException("Wassup");
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("Array index oob: " + e);
		} catch (Exception e) {
			System.out.println(e);
		}
		
		System.out.println("After try-catch blocks");
	}

}
