import java.util.Scanner;

public class Arrayq {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int arr[] = new int[n];

        for(int i = 0; i < n; i++){
            arr[i] = s.nextInt();
        }

        int even = 0, odd = 0;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0 && arr[i] % 2 == 1){
                System.out.println(arr[i]);
                odd = odd + 1;
            }

            if((i % 2 == 1 && arr[i] % 2 == 0)){
                System.out.println(arr[i]);
                even = even + 1;
            }
        }

        System.out.println("No. of even numbers in odd position in the array: " + even);
        System.out.println("No. of odd numbers in even position in the array: " + odd);

        s.close();
    }
    
}
