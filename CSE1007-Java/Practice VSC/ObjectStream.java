import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

// implements serializable is important
// the class which is read as objects
class Stud implements Serializable {
    String name;
    String regno;

    Stud(){}

    Stud(String n, String r){
        name = n;
        regno = r;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Regn: " + regno);
    }
}


public class ObjectStream {
    public static void main(String[] args) {
        
        try {
            Stud s = new Stud("VBN", "S1");
            FileOutputStream fos = new FileOutputStream("C:\\Users\\S K Nayak\\Documents\\CSE1007 Lab\\Practice VSC\\Obs.txt");
            ObjectOutputStream os = new ObjectOutputStream(fos);
            os.writeObject(s);
            os.close();
            fos.close();
            // Obs.txt is written in bytes

            FileInputStream fis = new FileInputStream("C:\\Users\\S K Nayak\\Documents\\CSE1007 Lab\\Practice VSC\\Obs.txt");
            ObjectInputStream is = new ObjectInputStream(fis);
            Stud s1 = new Stud();
            s1 = (Stud)is.readObject();
            s1.display();
            is.close();
            fis.close();
        } catch (Exception e) {
            System.out.println("Exception thrown.");
        }
    }
}
