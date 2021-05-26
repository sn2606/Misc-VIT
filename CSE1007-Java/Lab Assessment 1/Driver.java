import java.util.Scanner;

// Done by 19BCE0977
class DriverInfo {
    String driverName;
    int age;
    String drivingLicenseType;

    DriverInfo(String s){
        driverName = s;
    }

    DriverInfo(String n, int a, String d){
        driverName = n;
        age = a;
        drivingLicenseType = d;
    }

    void getDriverInfo(Scanner s) {
        System.out.print("Driver Name: ");
        driverName = s.next();
        System.out.print("Driver Age: ");
        age = s.nextInt();
        System.out.print("Driver License Type: ");
        drivingLicenseType = s.next();
    }

    void dispDriverInfo() {
        System.out.println("Driver Name: " + driverName);
        System.out.println("Driver Age: " + age);
        System.out.println("Driver License Type: " + drivingLicenseType);
    }

}

public class Driver {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        DriverInfo dri[] = new DriverInfo[6];

        dri[0] = new DriverInfo("Hase", 25, "HGMV");
        dri[1] = new DriverInfo("John", 30, "HMV");
        dri[2] = new DriverInfo("Roug", 36, "HGMV");
        dri[3] = new DriverInfo("Roja", 20, "HMV");
        dri[4] = new DriverInfo("Rahul", 31, "LMV");
        dri[5] = new DriverInfo("Guy", 38, "MGV");
        

        for(int i = 0; i < 6; i++){
            if(dri[i].drivingLicenseType == "HMV"){
                dri[i].dispDriverInfo();
            }
        }

        s.close();
        
    }
}
