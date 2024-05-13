class SingleTonClass{
    // To make exactly one object of a class you have to prevent user from calling the constructor of the class
    //thus
    private SingleTonClass(String name){
        this.Name = name;
    }

    private static SingleTonClass instance ;
    private String Name ;
    public String getName(){
        return this.Name;
    }
    public static SingleTonClass getInstance(String name){
        if(instance == null){
            instance = new SingleTonClass(name);
        }

        return instance;
    }
}
public class Singleton{
    public static void main(String[] args) {
        SingleTonClass obj = SingleTonClass.getInstance("Aum");
        SingleTonClass obj1 = SingleTonClass.getInstance("Sahil");
        SingleTonClass obj2 = SingleTonClass.getInstance("Siddhant");

        System.out.println(obj.getName());
        System.out.println(obj1.getName());
        System.out.println(obj2.getName());
    }
}