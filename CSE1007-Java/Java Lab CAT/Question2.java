import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Monitor {
    String manufacturer;
    double screenSize; // in inches
    int HDMI; // number of HDMI ports
    int serialNo; // serial number of the product
    double price; // price of the product

    Monitor() {}

    Monitor(String m, double s, int h, int n, double p) {
        manufacturer = m;
        screenSize = s;
        HDMI = h;
        serialNo = n;
        price = p;
    }

    double getPrice() {
        return this.price;
    }

    double getScreenSize() {
        return this.screenSize;
    }

    void getInput(Scanner s) {
        System.out.print("Manufacturer: ");
        manufacturer = s.next();
        System.out.print("Serial No.: ");
        serialNo = s.nextInt();
        System.out.print("Screen Size (in inches): ");
        screenSize = s.nextDouble();
        System.out.print("No. of HDMI ports: ");
        HDMI = s.nextInt();
        System.out.print("Price: ₹");
        price = s.nextDouble();
    }

    void printProductInfo() {
        System.out.println("Manufacturer: " + manufacturer);
        System.out.println("Serial No.: " + serialNo);
        System.out.println("Screen Size: " + screenSize + " inches");
        System.out.println("No. of HDMI ports: " + HDMI);
        System.out.println("Price: ₹" + price);
    }
}

class TV extends Monitor {
    int refreshRate; // in hertz
    int warranty; // years of warranty

    TV() {}

    TV(String m, double s, int h, int n, double p, int r, int w) {
        super(m, s, h, n, p);
        refreshRate = r;
        warranty = w;
    }

    int getWarranty() {
        return this.warranty;
    }

    String getManufacturer() {
        return this.manufacturer;
    }

    void getInput(Scanner s) {
        super.getInput(s);
        System.out.print("Refresh rate (in Hertz): ");
        refreshRate = s.nextInt();
        System.out.print("Years of warranty: ");
        warranty = s.nextInt();
    }

    void printProductInfo() {
        super.printProductInfo();
        System.out.println("Refresh rate (in Hertz): " + refreshRate);
        System.out.println("Years of warranty: " + warranty);
    }

}

public class Question2 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);

        int n = 5;
        Monitor m[] = new Monitor[n];

        for(int i = 0; i < n; i++) {
            m[i] = new Monitor();
            m[i].getInput(s);
        }

        Arrays.sort(m, new Comparator<Monitor>() {
            public int compare(Monitor m1, Monitor m2) {
                if(m1.screenSize > m2.screenSize){
                    return 1;
                }
                if(m1.screenSize < m2.screenSize){
                    return -1;
                }
                return 0;
            }
        });

        System.out.println("\nPrinted in ascending order:");

        for(int i = 0; i < n; i++) {
            m[i].printProductInfo();
        }

        TV t[] = new TV[n];

        for(int i = 0; i < n; i++) {
            t[i] = new TV();
            t[i].getInput(s);
        }

        for(int i = 0; i < n; i++) {
            t[i].printProductInfo();
        }


        s.close();

    }    
}