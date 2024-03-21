package Projects;

import java.util.HashMap;
import java.util.Map;
// what was Express940934
// how does map work
public class TickTackToe{
    public static void main(String[] args) {
        Map<Integer,String> obj  = new HashMap<>();
        obj.put(34,"thirty four");
        obj.put(10,"ten");
        System.out.println(obj);

        Map<Integer,String> obj2  = new HashMap<>(obj);
        obj2.put(5,"five");
        obj2.put(1,"one");
        System.out.println(obj2);
    }
}
//class Animal{
//    String name;
//    int age;
//    Animal(int age,String name){
//        this.age=age;
//        this.name=name;
//    }
//}