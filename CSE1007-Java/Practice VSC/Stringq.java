import java.util.Scanner;

public class Stringq {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);
        System.out.print("Enter your string: ");
        String s1 = s.next();

        char[] arr = new char[s1.length()]; 
  
        // Copy character by character into array 
        for (int i = 0; i < s1.length(); i++) { 
            arr[i] = s1.charAt(i); 
        }
        
        String rev = "";

        for(int i = arr.length - 1; i >= 0; i--){
            rev = rev + arr[i];
        }

        System.out.println("Reverse: " + rev);
        char temp;

        for(int i = 0; i < arr.length; i++){
            for(int j = i+1; j < arr.length; j++){
                if(arr[j] < arr[i]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        String sorted = "";

        for(char c : arr)
            sorted = sorted + c;

        System.out.println("Sorted string: " + sorted);

        s.close();
    }
    
}
