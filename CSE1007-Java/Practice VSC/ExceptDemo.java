public class ExceptDemo {
    public static void main(String[] args) {
        int a = 5, b = 2; // b = 0;
        int arr[] = new int[2];
        try {
            int res;
            // if b were 0, it wont go to arr statements at all
            // will execute ArithmeticException catch code
            res = a/b;
            arr[1] = res;
            arr[2] = 37;
        }
        // Catch block of array index out of bounds exception
        // exception of that type will be generated
        catch(ArrayIndexOutOfBoundsException ai){
            System.out.println("Array index out of bounds exception caught");
        }
        // division by 0 is an arithmetic exception
        catch(ArithmeticException ae){
            System.out.println("Ärithmetic Exception Caught");
        }
        // when we don't know exact exception class
        // any no of catch blocks can be defined
        catch (Exception e) {
            System.out.println("Expection caught!");
        }
        // finally block is always executed
        finally {
            System.out.println("In finally block");
        }
    }
}