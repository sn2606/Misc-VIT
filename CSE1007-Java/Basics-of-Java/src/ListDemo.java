import java.util.LinkedList;
import java.util.ArrayList;
//import java.util.*;
// import java.*;

public class ListDemo {
    public static void main(String[] args) {
    	ArrayList <Integer> arr = new ArrayList<Integer>();
        LinkedList<Integer> num = new LinkedList<Integer>();
        LinkedList<Integer> n1 = new LinkedList<Integer>();
        num.add(101);
        num.add(121);
        num.add(222);
        System.out.println("List: " + num);
        System.out.println("List: " + num.size());
        System.out.println("Element: " + num.get(1));
        System.out.println("Removed: " + num.remove(2));
        num.add(2, 333); // add element at index 2
        num.push(444); // add element at first
        num.pop();
        num.addAll(2, n1); // add sub list n1
        
        arr.add(14);
        arr.add(99);
        num.addAll(0, arr); // can add but type must be the same
        
        System.out.println(num);

        // Integer a = new Integer(7);
    }
}