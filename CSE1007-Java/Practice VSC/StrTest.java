public class StrTest{
    public static void main(String[] args) {
        
        String str = "Results";
        String str1 = new String("India");
        String str2 = "results";
        System.out.println(str);
        System.out.println("Length of str: " + str.length());
        System.out.println("Character at 2nd position: " + str.charAt(1));
        System.out.println("Index of character s: " + str.indexOf('s'));
        System.out.println("Last Index of character s: " + str.lastIndexOf('s'));
        System.out.println(str1.toLowerCase());
        System.out.println(str.equals(str1));
        System.out.println(str.compareToIgnoreCase(str2));
        System.out.println(str.compareToIgnoreCase(str1));

        char strArr[] = str.toCharArray();
        System.out.println(strArr[0] + strArr[3]);

        String arr[] = {"SCOPE", "SITE", "SENSE", "SELECT"};

        for(String i : arr){
            System.out.println(i);
        }

        StringBuffer strbuf = new StringBuffer("Vellore");
        strbuf.append(str);
        System.out.println(strbuf);

    }
}