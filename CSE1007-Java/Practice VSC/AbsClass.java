abstract class AbsTest {
    abstract void absmeth(); // method declaration
    // abstract method
    // for abstract class, at least one method should be abstract

    void meth() {
        System.out.println("In Non-Abstract method");
    }
}

interface Test1 {
    void interTest1();
    void interTest2();
}

// extends for extending property of class
// inherits all properties from extends class
// superclass -> AbsTest
// subclass -> AbsExtend
class AbsExtend extends AbsTest implements Test1 {
    
    // If public is not added its showing visibility error
    // There are 5 types of visibilities
    public void interTest1() {
        System.out.println("In Interface method 1");
    };
    
    public void interTest2() {
        System.out.println("In Interface method 2");
    };
    
    void absmeth() {
        System.out.println("In Abstract method");
    }

    void meth2() {
        System.out.println("In method 2");
    }
}

// In interface all methods have to be abstract
// interface -> implements
// extends -> for inheritance

public class AbsClass {
    public static void main(String[] args) {
        // Abstract class doesnt have objects of its own
        // AbsTest a = new AbsTest();

        AbsExtend aExtend = new AbsExtend();
        aExtend.absmeth();
        aExtend.meth2();
        aExtend.meth();
        aExtend.interTest1();
        aExtend.interTest2();        
    }
}
