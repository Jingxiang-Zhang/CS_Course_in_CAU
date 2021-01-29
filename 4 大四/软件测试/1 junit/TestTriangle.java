package test;
import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class TestTriangle {
    private static Triangle triangle = new Triangle();
    private String commonTriangle = "一般三角形";
    private String noneTriangle = "不是三角形";
    private String isoscelesTriangle = "等腰三角形";
    private String congruentTriangles = "等边三角形";
    
	@Test
	public void test1(){
		assertEquals(commonTriangle,triangle.triJudge(3, 4, 5));
	}
	
	@Test
	public void test2(){
		assertEquals(noneTriangle,triangle.triJudge(0, 1, 2));
	}
	
	@Test
	public void test3(){
		assertEquals(noneTriangle,triangle.triJudge(1, 0, 2));
	}
	
	@Test
	public void test4(){
		assertEquals(noneTriangle,triangle.triJudge(1, 2, 0));
	}
	
	@Test
	public void test5(){
		assertEquals(noneTriangle,triangle.triJudge(1, 2, 3));
	}
	
	@Test
	public void test6(){
		assertEquals(noneTriangle,triangle.triJudge(1, 2, 3));
	}
	
	@Test
	public void test7(){
		assertEquals(noneTriangle,triangle.triJudge(3, 1, 2));
	}
	
	@Test
	public void test8(){
		assertEquals(isoscelesTriangle,triangle.triJudge(3, 3, 4));
	}
	
	@Test
	public void test9(){
		assertEquals(isoscelesTriangle,triangle.triJudge(3, 4, 4));
	}
	
	@Test
	public void test10(){
		assertEquals(isoscelesTriangle,triangle.triJudge(3, 4, 3));
	}
	
	@Test
	public void test11(){
		assertEquals(congruentTriangles,triangle.triJudge(3, 3, 3));
	}
	
	
}

