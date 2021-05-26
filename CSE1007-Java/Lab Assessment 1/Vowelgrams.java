import java.util.Scanner;

// Done by 19BCE0977
public class Vowelgrams {

    public static boolean isVowelgram(String s){
        int count[] = new int[5];

        for(int i = 0; i < 5; i++){
            count[i] = 0;
        }

        char arr[] = s.toCharArray();

        for(char a : arr){
            if(a == 'a'){
                count[0]++;
            }else if(a == 'e'){
                count[1]++;
            }else if(a == 'i'){
                count[2]++;
            }else if(a == 'o'){
                count[3]++;
            }else if(a == 'u'){
                count[4]++;
            }
        }

        for(int i : count){
            if(i > 1){
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String str = scan.nextLine();

        boolean b = isVowelgram(str);
        System.out.println(b);

        scan.close();        
    }
}
