class PriorityTest implements Runnable {
	public void run() {
		System.out.println(Thread.currentThread().getName() + " " + Thread.currentThread().getPriority());
		
		for(int i = 0; i < 5; i++) {
			System.out.println(Thread.currentThread().getName() + ": " + i);
		}
	}
}


public class ThreadPriority {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PriorityTest p1 = new PriorityTest();
		Thread t1 = new Thread(p1);
		PriorityTest p2 = new PriorityTest();
		Thread t2 = new Thread(p2);
		PriorityTest p3 = new PriorityTest();
		Thread t3 = new Thread(p3);
		PriorityTest p4 = new PriorityTest();
		Thread t4 = new Thread(p4);

		t1.setPriority(Thread.MIN_PRIORITY);
		t2.setPriority(Thread.MAX_PRIORITY);
		t3.setPriority(3);
		
		t1.start();
		t2.start();
		t3.start();
		t4.start();
	}

}
