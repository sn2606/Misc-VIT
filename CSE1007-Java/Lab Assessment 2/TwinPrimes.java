import java.util.*;
import primespackage.Primes;


public class TwinPrimes{
    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        System.out.println("Check Primes Till:");
        int n=in.nextInt();

        if (n<5){
            in.close();
            return;
        }

        for(int i = 3; i+1 < n; i += 4){
            if(Primes.checkForPrime(i) && Primes.checkForPrime(i+2)) 
                System.out.println(i + ", " + (i+2));

            if(i+2 < n && Primes.checkForPrime(i+1) && Primes.checkForPrime(i+3))
                System.out.println((i+1)+", "+(i+3));
        }

        in.close();
    }
}