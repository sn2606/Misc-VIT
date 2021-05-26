// import org.comp

import java.util.Scanner;

class Demo{

    public static void main(String args[]){

        Scanner s = new Scanner(System.in);

        int matrix[][] = new int[2][2];

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                matrix[i][j] = s.nextInt();
            }
        }

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                System.out.println(matrix[i][j]);
            }
        }


        int arr[] = new int[5];

        for(int i = 0; i < 5; i++){
            arr[i] = s.nextInt();
        }

        arr[0] = 99;

        for(int i : arr){
            System.out.println(i);
        }

        String f = s.next();
        String ln = s.nextLine();
        s.close();
        System.out.println(f);
        System.out.println(ln);
    }
}