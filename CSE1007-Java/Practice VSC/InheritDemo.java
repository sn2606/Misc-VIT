// Inheritance demo in theory class
// 23-02-2021

// Super CLass
class Student {
    String name;
    String regno;
    
    void getStudentDetails(String n, String r){
        name = n;
        regno = r;
    }

    void dispStudentData(){
        System.out.println("Student Name: " + name);
        System.out.println("Registration No.: " + regno);
    }
}

// Sub Class
// Any subclass in java can have only one super class
class Marks extends Student {
    int marks1, marks2;

    void getMarks(int m1, int m2) {
        marks1 = m1;
        marks2 = m2;
    }

    void dispMarks() {
        System.out.println("Marks 1: " + marks1);
        System.out.println("Marks 2: " + marks2);
    }
}

class Result extends Marks {
    int total = marks1 + marks2;

    void dispResult() {
        System.out.println("Result: " + total);
    }
}

public class InheritDemo {
    public static void main(String[] args) {
        
        Marks m = new Marks();
        m.getStudentDetails("Swaranjana Nayak", "19BCE0977");
        m.dispStudentData();
        m.getMarks(85, 83);
        m.dispMarks();
    }

}