class Test implements inter {
  public void fun() {
    System.out.println("having fun from test class");
  }

  public void fun2() {
    System.out.println("overriden");
  }
}

interface inter {
  default void fun() {
    System.out.println("having fun from interface");
  }

  void fun2();
}

public class example {
  public static void main(String[] args) {
    Test test = new Test();
    test.fun();
    test.fun2();
    // having fun from test class
    // overriden
  }
}
