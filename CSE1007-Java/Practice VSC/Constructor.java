// 17-02-2021

class Account {
    String AccNo;
    String AccName;

    // no return type for constructor
    // can be with or without arguments
    // also instead of null string, we can assign default non-null values
    // method overloading (?)
    Account(){
        AccNo = "";
        AccName = "";
    }

    // constructor name has to be class name always
    Account(String number, String name){
        AccNo = number;
        AccName = name;
    }

    void dispAccount(){
        System.out.println("Account Details: " + AccNo + " " + AccName);
    }

    // same function with same name defined with different number of parameters 
    // function overloading example (here method overloading) :-
    void add(int x, int y) {
        System.out.println("Sum: " + (x + y));
    }

    void add(int x, int y, int z) {
        System.out.println("Sum: " + (x + y + z));
    }
}


public class Constructor {
    public static void main(String[] args) {

        // no-argument constructor
        Account a = new Account();
        a.dispAccount();

        // argument constructor
        Account a1 = new Account("AC101", "VIT");
        a1.dispAccount();

        // array of objects
        Account acc[] = new Account[2];
        acc[0] = new Account();
        acc[1] = new Account("AC102", "IEEE");

        acc[0].dispAccount();
        acc[1].dispAccount();

        a.add(1, 2);
        a.add(1, 2, 3);
        
    }
}