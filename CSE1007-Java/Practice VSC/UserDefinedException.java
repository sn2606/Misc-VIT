// import java.lang.ArithmeticException;
// extends keyword is compulsary for user defined exception
class MyException extends Exception {
    String msg(){
        // System.out.println("In user defined exception");
        return "In User Defined Exception Class";
    }
}

// we can define userdefined exceptions for validations and all

public class UserDefinedException {
    public static void main(String[] args) {
        try {
            // if userdefined exception is thrown
            // you have to handle it
            throw new MyException();
            // if this exception is not handled,
            // it will give a run time error
            // the block of code will look for a catch block with exception
            // thrown above type
        }
        // we can have a common exception too
        catch(MyException e){
            System.out.println(e.msg());
        }
        catch(Exception e){
            System.out.println("Hello WOrld");
        }
        // ArithmeticException
    }
}
