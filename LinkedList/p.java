package LinkedList;
class emp{
    String name;
    int number;
    emp(String name,int number){
        this.name=name;
        this.number=number;
    }
    public void name_check(){
        System.out.println("Mailing to "+this.name+" on number - "+this.number);
    }
}
class a extends emp{
    public  String code;
    a(String name,int number,String code){
        super(name,number);
        this.code = code;
    }
    public void name_check(){
        System.out.println("Mailing to "+this.name+" on number - "+this.number +" and codeWOrd -"+ code);
    }
}
public class p {
    public static void main(String[] args) {
        a s=new a("aum",44,"XyZ");
        s.code="hi";
        emp e=new a("sahil",24,"XZr");
//        s.name_check();
        System.out.println(s.code);
        e.name_check();
        System.out.println(s.code);
    }
    // imp 
}
