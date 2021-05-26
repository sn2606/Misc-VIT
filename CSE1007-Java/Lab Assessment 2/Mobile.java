import java.util.NoSuchElementException;
import java.util.Scanner;
import java.lang.IllegalArgumentException;

public class Mobile {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String regno;
        long mobile;

        System.out.print("Enter Reg. No: ");
        regno = s.nextLine();

        System.out.print("Enter Mobile No: ");
        mobile = s.nextLong();
        long m = mobile;
        int digits = 0;

        s.close();

        while(m > 0){
            m /= 10;
            digits = digits + 1;
        }

       if(regno.length() != 9 || digits != 10){
            System.out.println("Invalid");
            throw new IllegalArgumentException("Length of input not appropriate.");
        }

        String regex = "^(?=.*[a-zA-Z])(?=.*[0-9])[A-Za-z0-9]+$";

        if(!regno.matches(regex)){
            System.out.println("Invalid");
            throw new NoSuchElementException("Registration number is not valid.");
        }

        System.out.println("Valid");
    }
}
