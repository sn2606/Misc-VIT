// class ThreadDemo extends Thread

// class ThreadDemo implements Runnable
// any no. of implements can be used
// but only one superclass with extends 
class ThreadDemo implements Runnable {
    // thread code should always be in public void run()
    public void run(){
        for(int i = 0; i < 30; i++){

            // try {
            //     if(i == 10){
            //         sleep(1000); // temporary stoppage
            //         // sleep throws InterruptedException
            //         // You should always handle exceptions
            //     }
            //     System.out.println("In Thread " + Thread.currentThread() + ": " + i);                
            // } catch (InterruptedException e) {
            //     // Thread.currentThread().interrupt();
            // }

            System.out.println("In Thread " + Thread.currentThread() + ": " + i); 
            
        }
    }
}


public class ThreadTest {
    public static void main(String[] args) {
        // main is also a thread
        // main thread always starts first (?)

        ThreadDemo t  = new ThreadDemo(); // only created object
        Thread t1  = new Thread(t);

        // t1.setPriority(10); // highest priority
        // still main method will be executing first
        // t1 will finish executing first
        t1.start(); // start is only for Thread class

        // t.start(); // don't call t.run()
        // new ThreadDemo().start(); // thread created and started so this will execute first

        // t.r; // start() is undefined for the class ThreadDemo implements Runnable

        // switching between threads is purely based on OS scheduling
        // so we cant predict output
        // but those threads execute simultaneously

        for(int j = 0; j < 30; j++){
            System.out.println("In main thread: " + j);
        }        
    }
}

// practical examples -> gaming application -> we cant predict output in gaming applications
// Joint account -> concurrent transactions
// deadlocks? thread deadlocks? like in OS
// semaphores, critical regions, deadlock issues
// thread synchronization -> to avoid multiple access in joint account
// deposit is no issue, withdrawal is
// interthread communication