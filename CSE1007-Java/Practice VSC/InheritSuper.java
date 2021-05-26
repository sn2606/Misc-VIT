
class University {
    String name;
    University(String s){
        name = s;
    }
}

class Scope extends University {
    String sname;
    Scope(String s1, String s2){
        // should be in first line
        // will check if there is a one-argument constructor
        // If there is, it will apply
        // Super keyword is used to invoke superclass constructors
        super(s1);
        sname = s2;
    }

    void disp() {
        System.out.println("University: " + name + " School: " + sname);
    }
}

public class InheritSuper {
    public static void main(String[] args) {
        
        Scope sobj = new Scope("VIT", "SCOPE");
        sobj.disp();

    }    
}