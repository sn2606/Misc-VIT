import java.util.Scanner;

class Fresher {
    String regNo;
    double boardMarks;
    double EPTMarks;
    double APTMarks;

    void getData(Scanner s){
        regNo = s.next();
        boardMarks = s.nextDouble();
        EPTMarks = s.nextDouble();
        APTMarks = s.nextDouble();
    }
}

public class Freshers {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        Fresher obj[] = new Fresher[5];

        for(int i = 0; i < 5; i++){
            obj[i] = new Fresher();
        }

        for(int i = 0; i < 5; i++){
            obj[i].getData(s);
        }

        for(int i = 0; i < 5; i++){
            if(obj[i].EPTMarks > 50.0){
                System.out.println(obj[i].regNo);
            }
        }
        s.close();        
    }    
}
