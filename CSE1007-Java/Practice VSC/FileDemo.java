import java.io.*;

public class FileDemo {
    public static void main(String[] args) {
        
        try {

            // File fos = new File("input.txt");
            FileOutputStream fos = new FileOutputStream("C:\\Users\\S K Nayak\\Documents\\CSE1007 Lab\\Practice VSC\\in.txt");
            // int i = 99;
            // String s = "ii";
            // fos.write(i); // converting to ASCII and then writing ??
            // fos.write(s); -> string not allowed
            
            fos.write('6');
            
            FileInputStream fis = new FileInputStream("C:\\Users\\S K Nayak\\Documents\\CSE1007 Lab\\Practice VSC\\in.txt");
            System.out.println((char)fis.read());
            
            fos.close();
            fis.close();
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found");
        } catch (IOException e) {
            System.out.println("Input Output Exception");
        } 
        
        // byte b = 12345;
        // int i = b.intValue();

        int i = 9;
        byte b = (byte)i;

        System.out.println(b);

    }
}
