import java.util.*;

public class Lab {
    
    public static void main(String[] args){
        
        Scanner s = new Scanner(System.in);
        int cred = s.nextInt();
        
        if(cred >= 16 && cred <= 19){
            System.out.println("Minimum credit registered.");
        }else if(cred >= 20 && cred <= 23){
            System.out.println("Average credit registered.");
        }else if(cred >= 24 && cred <= 27){
            System.out.println("Maximum credit registered.");
        }
        
        s.close();
    }
    
}