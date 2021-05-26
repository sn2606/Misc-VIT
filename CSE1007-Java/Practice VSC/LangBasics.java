// If Else conditional example
// While loop example
// 10-02-2021

import java.util.Scanner;

class LangBasics {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int marks = s.nextInt();
        char grade;
        int i = 5;

        while(i != 0){
            System.out.println(i);
            i--;
        }

        System.out.println('A' == 'a');
        System.out.println('B' == 'A');
        System.out.println("AbC" == "Abc");
        
        // === is in JavaScript -> identity operator
        // but === is not in Java

        if(marks >= 90){
            grade = 'S';
        }else if(marks < 90 && marks >= 80){
            grade = 'A';
        }else if(marks < 80 && marks >= 70){
            grade = 'B';
        }else if(marks < 70 && marks >= 60){
            grade = 'C';
        }else if(marks < 60 && marks >= 50){
            grade = 'D';
        }else if(marks < 50 && marks >= 40){
            grade = 'E';
        }else{
            grade = 'F';
        }

        System.out.println("Grade: " + grade);

        s.close();

    }
}
