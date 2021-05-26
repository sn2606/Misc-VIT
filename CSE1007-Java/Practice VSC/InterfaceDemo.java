
interface Test2 {
    // If you are declaring a variable, and intend to use it, it must be initialized
    int var = 0;
    // Interface must have only declared methods, no implementations
    void meth1();
    void meth2();
}

class Demo1 implements Test2 {
    
    // In definition you should make it as public
    // Interface methods should always be public
    public void meth1() {
        System.out.println("In Method 1");
        System.out.println(var);

    }

    // if method 2 not defined, it becomes abstract class
    // gives an exception
    public void meth2() {
        System.out.println("In method 2");
    }
}

public class InterfaceDemo {    
    public static void main(String[] args) {
        Demo1 d = new Demo1();
        d.meth1();
        d.meth2();
    }    
}