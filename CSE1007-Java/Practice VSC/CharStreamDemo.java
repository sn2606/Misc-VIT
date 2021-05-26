import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CharStreamDemo {
    public static void main(String[] args) {
        
        try {        
            FileWriter fw = new FileWriter("C:\\Users\\S K Nayak\\Documents\\CSE1007 Lab\\Practice VSC\\fwdemo.txt");
            fw.write("VIT Vellore");
            fw.close();

            FileReader fr = new FileReader("C:\\Users\\S K Nayak\\Documents\\CSE1007 Lab\\Practice VSC\\fwdemo.txt");
            
            // char ch;
            int ch;
            while((ch = fr.read()) != -1) {
                System.out.println((char)ch);
            }
            fr.close();

        }catch (IOException e){
            System.out.println("IO Exception");
        }
    }
}
