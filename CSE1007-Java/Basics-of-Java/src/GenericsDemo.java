
//like templates in C++
class Test <T> {
	T tobj; // template object
	
	// defining a constructor
	Test(T t1) {
		this.tobj = t1;
	}
	
	// Normal method
	T disp() {
		System.out.println(tobj);
		return tobj;
	}
}


public class GenericsDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Integer i = 7;		
		Test<Integer> t = new Test<Integer>(i);
		t.disp();
		
		Test<String> s = new Test<String>("Hello");
		s.disp();
		
		Test<Float> f = new Test<Float>(3.14f);
		f.disp();
	}
}