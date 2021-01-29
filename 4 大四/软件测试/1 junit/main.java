package test;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class main {
	public static void main(String[] args){
		Result result = JUnitCore.runClasses(TestTriangle.class);
		
		for (Failure failure : result.getFailures()){
			System.out.println(failure.toString());
		}
		
		System.out.println("是否全部通过测试：" + result.wasSuccessful());
	}
}

