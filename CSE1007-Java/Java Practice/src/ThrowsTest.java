import java.io.IOException;

class Test {
	void method() throws IOException {
		throw new IOException("Hello World");
	}
}

public class ThrowsTest {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		new Test().method();
		System.out.println("Normal Flow..");
	}

}
