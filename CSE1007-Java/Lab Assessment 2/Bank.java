import java.util.Scanner;
import java.lang.Math;

class BankAccount {
    String customerName;
    int accNo;
    String accType;
    public double balance = 0.0;

    void getInput(Scanner s){
        System.out.print("Name: ");
        customerName = s.next();
        System.out.print("Account No: ");
        accNo = s.nextInt();
        System.out.print("Account Type: ");
        accType = s.next();
    }

    void displayAcc(){
        
        System.out.println(customerName);        
        System.out.println(accNo);        
        System.out.println(accType);
        // System.out.print("Account Balance: ");
        // System.out.println(balance);
    }

    void withdraw(double amt){
        balance = balance - amt;
        System.out.println("₹" + amt + " withdrawn.");
    }

    void deposit(double amt){
        balance = balance + amt;
        System.out.println("₹" + amt + " deposited.");
    }

    void displayBalance(){
        System.out.println("The balance is: " + balance);
    }

    void updateBalance(double amt){
        // If withdrawn, amt will be negative
        // If deposited, amt will be positive
        // += handles both cases
        balance = balance + amt;
        System.out.println("Balance Updated.");
    }
}

class CurrentType extends BankAccount {
    double serviceCharge;
    String chequeBook;
    double minimumBalance = 1000.0;

    void chequeBook(){
        System.out.println("Cheque Book associated with " + accNo + " is " + chequeBook);
    }

    int checkBalance(){
        if(balance < minimumBalance){
            return 1;
        }else{
            return 0;
        }
    }

    void imposePenalty(){
        if(checkBalance() == 1){
            System.out.println("Penalty Imposed on Account " + accNo + "!");
            updateBalance(-100.0); // deducting 100 rs from user's account
        }
    }

}

class SavingsType extends BankAccount {
    double r = 3.0; // Interest Rate
    double cinterest;
    double p;

    void computeInterest(int t, int n) {
        p = balance;
        double amount = p * Math.pow(1 + (r / n), n * t);
        System.out.println(amount);
        cinterest = amount - p;
        System.out.println(cinterest);
    }

    void depositInterest(){
        balance = balance + cinterest;
        System.out.println("Interest Deposited!");
    }
}

public class Bank {
    public static void main(String[] args) {
        CurrentType cus1 = new CurrentType();
        SavingsType cus2 = new SavingsType();
        Scanner s = new Scanner(System.in);

        cus1.getInput(s);
        // cus1.displayAcc();
        cus1.deposit(2000.0);
        cus1.withdraw(1000.0);
        cus1.imposePenalty();
        cus1.deposit(2000.0);

        cus2.getInput(s);
        // cus2.displayAcc();
        cus2.deposit(2000.0);
        cus2.displayBalance();
        cus2.computeInterest(2, 4);
        cus2.depositInterest();
        cus2.displayBalance();

        s.close();        
    }
}
