import java.util.ArrayList;

public class LambdaTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		ArrayList <Integer> arr = new ArrayList <Integer>();
		arr.add(11);
		arr.add(12);
		arr.add(13);
		
		// Lambda Expression example		
		arr.forEach((i) -> {
			if(i%2 == 1) 
				System.out.println(i);
			});

	}

}
