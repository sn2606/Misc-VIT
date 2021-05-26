// import java.util.*;

class Test{

    // No
    // public:
    // as in C++

    void display(){
        System.out.println("In display method");
    }
}
// No semicolon in end as in C++

// Why use public here? In TestClass?
// Single file can have only one public
// If no class is defined public, by default it will take main method class as Public
// Program execution starts from main()
// Main method -> public static (compulsary)
public class TestClass {    
    // public static == static public
    public static void main(String[] args) {
        Test t = new Test(); // Object Creation
        t.display();         // Accessing the methods with . operator

    }
}
