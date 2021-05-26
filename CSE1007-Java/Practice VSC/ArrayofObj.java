
import java.util.Scanner;

class Course {
    String courseID;
    String courseName;

    void getData(Scanner s) {
        this.courseID = s.next();
        this.courseName = s.next();
    }

    void dispData() {
        System.out.println("Course ID: " + courseID);
        System.out.println("Course Title: " + courseName);
    }
}

public class ArrayofObj {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        Course c = new Course();
        c.getData(s);
        c.dispData();

        Course obj[] = new Course[3];

        for(int i = 0; i < 3; i++){
            obj[i] = new Course();
        }

        for(int i = 0; i < 3; i++){
            obj[i].getData(s);
            obj[i].dispData();
        }

        s.close();
    }
}