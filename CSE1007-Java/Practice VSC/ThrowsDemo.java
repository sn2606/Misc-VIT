import java.io.DataInputStream;
import java.io.*;

public class ThrowsDemo {
    public static void main(String[] args) throws IOException {
        try {
            DataInputStream din = new DataInputStream(System.in);
            int inp = din.readInt();
            System.out.println(Integer.toString(inp));
            System.out.println(Integer.parseInt(din.readLine()));
        } catch (Exception e) {
            
        }
    }
}
 