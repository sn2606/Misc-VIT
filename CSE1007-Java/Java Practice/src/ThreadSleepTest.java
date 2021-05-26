class SleepTest extends Thread {
	SleepTest(String name) {
		this.setName(name);
	}
	
	public void run() {
		for(int i = 0; i < 5; i++) {
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				System.out.println(e);
			}
			System.out.println(this.getName() + ": " + i);
		}		
	}
}

public class ThreadSleepTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SleepTest t1 = new SleepTest("t1");
		SleepTest t2 = new SleepTest("t2");
		
		t1.start();
		t2.start();
		t1.start();

	}

}
