import java.util.Scanner;

// Done by 19BCE0977
public class GradeCalculator {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter number of students: ");
        int n = scan.nextInt();
        String reg[] = new String[n];
        int marks[] = new int[n];

        for(int i = 0; i < n; i++){
            System.out.print("Enter the reg no of student" + (i+1) + ": ");
            reg[i] = scan.next();
            System.out.print("Enter the marks of student" + (i+1) + ": ");
            marks[i] = scan.nextInt();
        }

        char grade;
        double total = 0;
        double denom = (double)n;
        for(int i = 0; i < n; i++){

            total = total + (double)marks[i];

            if(marks[i] >= 90){
                grade = 'S';
            }else if(marks[i] < 90 && marks[i] >= 80) {
                grade = 'A';
            }else if(marks[i] < 80 && marks[i] >= 70) {
                grade = 'B';
            }else if(marks[i] < 70 && marks[i] >= 60) {
                grade = 'C';
            }else if(marks[i] < 60 && marks[i] >= 50) {
                grade = 'D';
            }else {
                grade = 'F';
            }

            System.out.println("Registration Number: " + reg[i]);
            System.out.println("Grade: " + grade);
        }

        System.out.println("Class Average: " + (total/denom));

        scan.close();
    }
}