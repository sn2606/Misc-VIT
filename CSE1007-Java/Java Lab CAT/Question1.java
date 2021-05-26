import java.util.Scanner;
// Done by 19BCE0977

class OddEvenTest {
    public static boolean isOdd(int number) {
        if(((number % 2) + 2) % 2 == 1) {
            return true;
        }else{
            return false;
        }
    }
}

public class Question1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Input an integer: ");
        int n = s.nextInt();

        // invoking the method in a static way
        if(OddEvenTest.isOdd(n)){
            System.out.println("ODD");
            System.out.println(n + " is an odd number.");
        }else{
            System.out.println("EVEN");
            System.out.println(n + " is an even number.");
        }
        s.close();
    }
}