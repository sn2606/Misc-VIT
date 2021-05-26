
public class FinallyDemo {
	
	static void procA() {
		try {
			throw new RuntimeException("In Proc A");			
		} finally {
			System.out.println("Finally Proc A");
		}
	}
	
	static void procB() {
		try {
			return;
		} finally {
			System.out.println("Finally Proc B");
		}
	}
	
	static void procC() {
		try {
			System.out.println("In proc C");
		} finally {
			System.out.println("Finally Proc C");
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			procA();
		} catch (Exception e) {
			System.out.println(e);
		}
		
		procB();
		procC();
	}

}
