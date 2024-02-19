import java.util.*;

public class BankingManagementSystems {
    public static void main(String[] args) {
        Admin admin = new Admin();
        Banking obj = new Banking();
        Scanner sc=new Scanner(System.in);
        System.out.println("********************* WELCOME TO BANKING MANAGEMENT SYSTEMS****************************\n");
//        boolean flag=true;
        do{
            System.out.println("Choose your role in the BANK : \n1. Admin\n2. User\n3. EXIT\n");
            int n = sc.nextInt();
            if(n == 3){
                break;
            }
            if(n == 1){
                System.out.println("Enter You ADMIN name : ");
                String name = sc.next();
                System.out.println("Enter Password : ");
                String pass = sc.next();
                if(Objects.equals(name, admin.getName()) && Objects.equals(pass, admin.getPassword())){
                    obj.ADMIN();
                }else {
                    System.out.println("Incorrect Username or Password\n");
                }
            } else if (n == 2) {
                obj.USER();
            }
        }while (true);
        System.out.println("\n\n************************** Thanks for visiting us !! ******************************");
        System.out.println("\n     ************************** See you again !! ******************************");
    }
}
class Banking extends User{
    Admin admin;
    public List<User> users;
    public Banking(){
        users = new ArrayList<>();
    }
    public void ADMIN(){
        admin = new Admin();
        boolean a=true;
        do{
            System.out.println("\nWelcome ADMIN!");
            System.out.println("Choose an option:");
            System.out.println("1. View users");
            System.out.println("2. View bank total balance");
            System.out.println("3. Delete user");
            System.out.println("4. Add user");
            System.out.println("5. Exit\n");

            Scanner scanner = new Scanner(System.in);
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    admin.viewUsers(users);
                    break;
                case 2:
                    admin.viewBankTotalBalance(users);
                    break;
                case 3:
                    admin.deleteUser(users);
                    break;
                case 4:
                    System.out.println("\nEnter name of the User:");
                    String name = scanner.next();
                    System.out.println("\nEnter Password of the User:");
                    String pass = scanner.next();
                    User user =new User(name,pass);
                    GenerateUserID(user);
                    Admin.addUser(users,user);
                    break;
                case 5:
                    a=false;
                    break;
                default:
                    System.out.println("Invalid choice. Please choose a valid option.");
            }
        }while(a);
    }
    public void USER() {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nWelcome USER!");
            System.out.println("1. New here? Sign Up if you are new.");
            System.out.println("2. Sign in");
            System.out.println("3. EXIT\n");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    signUp();
                case 2:
                    signIn();
                    break;
                case 3:
                    System.out.println("\nExiting...\n");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter again.");
            }
        } while (choice != 3);
    }
    private void signIn() {

        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

        while (!exit) {
//            System.out.println("\nWelcome to your account!");
            System.out.println("\nChoose an option:");
            System.out.println("1. View Balance");
            System.out.println("2. Deposit");
            System.out.println("3. Withdraw");
            System.out.println("4. Transfer");
            System.out.println("5. Previous Transaction");
            System.out.println("6. Exit\n");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    viewBalance();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    transfer();
                    break;
                case 5:
                    PreviousTransaction();
                    break;
                case 6:
                    exit = true;
                    break;
                default:
                    System.out.println("Invalid choice. Please choose a valid option.");
            }
        }
    }

    private void PreviousTransaction() {
        User user;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Your User Id :");
        int user_ID = sc.nextInt();
        user=getId(user_ID);
        if( user != null){
            user.getPrev_Transaction();
        }else {
            System.out.println("Your Account was not found , Pls Enter Correct/Valid User id.");
        }
    }

    private void viewBalance() {
        // Implement code to view balance
        User user;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Your User Id :");
        int user_ID = sc.nextInt();
        user=getId(user_ID);
        System.out.println("Enter Password:");
        String pass = sc.next();
        if( user != null && password_Verification(user)){
            System.out.println("Hi "+ user.name+" ! Your current account balance is : Rs "+ user.Balance);
        }else {
            System.out.println("PLS Enter correct user id OR enter correct password!!");
        }
    }
    private User getId(int id){
        for (int i = 0; i <users.toArray().length ; i++) {
            if(id == users.get(i).User_id){
                return users.get(i);
            }
        }
        return null;
    }
    private boolean password_Verification(User user){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Password:");
        String pass = sc.next();
        return Objects.equals(user.getPassword(),pass);
    }
    private void deposit() {
        // Implement code for deposit
        Scanner sc = new Scanner(System.in);
        User user;
        double amt=0;
        System.out.println("Enter Your User Id :");
        int user_ID = sc.nextInt();
        user=getId(user_ID);
        if( user != null && password_Verification(user)){
            System.out.println("\nYour User Name : "+ user.name);
            System.out.println("Your User ID : "+ user.User_id+"\n");
            System.out.println("Is it you ?(y/n)");
            String ch = sc.next();
            char c= ch.charAt(0);
            if(c == 'y'  || c== 'Y'){
                while (true){
                    System.out.println("Enter Amount You Want to Deposit(in Rupees) : ");
                    amt = sc.nextDouble();
                    if(amt > 1000){
                        break;
                    }else{
                        System.out.println("You must deposit min Rs 1,000 in the Bank. Try again.");
                    }
                }
            }
            user.Balance += amt;
            int deposit = user.setPrev_Transaction(amt,1);
            System.out.println("You have successfully deposited amount of Rs "+ amt);
            System.out.println("Your updated balance is: Rs " + user.Balance);
        }else {
            System.out.println("User Id not Found . Pls Try again .");
        }
        Admin.UpdateBankBalance(amt);
    }
    private void withdraw() {
        // Implement code for withdraw
        Scanner sc = new Scanner(System.in);
        User user;
        double amt = 0;
        System.out.println("\nEnter Your User Id:");
        int id = sc.nextInt();
        user = getId(id);
        if( user != null && password_Verification(user)){
            System.out.println("\nYour User Name : "+ user.name);
            System.out.println("Your User ID : "+ user.User_id+"\n");
            System.out.println("Is it you ?(y/n)");
            String ch = sc.next();
            char c= ch.charAt(0);
            if(c == 'y'  || c== 'Y'){
                while (true){
                    System.out.println("Enter Amount You Want to Withdraw(in Rupees) : ");
                    amt = sc.nextDouble();
                    if(user.Balance - amt > 1000){
                        break;
                    }else{
                        System.out.println("You must have min Rs 1,000 in the Bank. Try again.");
                    }
                }
            }
            user.Balance -= amt;

            int with = user.setPrev_Transaction(amt,-1);
            System.out.println("You have successfully Withdrawn amount of Rs "+ amt);
            System.out.println("Your updated balance is: Rs " + user.Balance);
        }else {
            System.out.println("User Id not Found . Pls Try again .");
        }
        Admin.UpdateBankBalance(-amt);
    }
    private void transfer() {
        // Implement code for transfer
        Scanner sc = new Scanner(System.in);
        User user,user2=null;
        double amt = 0;
        System.out.println("\nEnter Your User Id:");
        int id = sc.nextInt();
        user = getId(id);
        if( user != null && password_Verification(user)){
            System.out.println("\nYour User Name : "+ user.name);
            System.out.println("Your User ID : "+ user.User_id+"\n");
            System.out.println("Is it you ?(y/n)");
            String ch = sc.next();
            char c= ch.charAt(0);
            if(c == 'y'  || c== 'Y'){
                while (true){
                    System.out.println("\nEnter the account id in which you want to Transfer the money:");
                    int id2= sc.nextInt();
                    user2 = getId(id2);
                    while (user2 == null){
                        System.out.println("\nAccount id not found !! Pls write valid User Id");
                        id2 = sc.nextInt();
                        user2 = getId(id2);
                    }
                    System.out.println("\nDo You want to Transfer amount to "+user2.name+" ?");
                    ch=sc.next();
                    char cha = ch.charAt(0);
                    if(cha == 'y' || cha == 'Y'){
                        System.out.println("\nProcessing....\n");
                    }else{
                        continue;
                    }
                    System.out.println("Enter Amount You Want to Transfer(in Rupees) : ");
                    amt = sc.nextDouble();
                    if(user.Balance - amt > 1000){
                        break;
                    }else{
                        System.out.println("You must have min Rs 1,000 in the Bank. Try again.");
                    }
                }
            }
            assert user2 != null;
            user2.Balance += amt;
            user.Balance -= amt;

            System.out.println("\nTransferred amount Rs "+amt+" to "+user2.name+".\nYour account balance is : Rs "+user.Balance);
            int t = user.setPrev_Transaction(amt,0);
        }else {
            System.out.println("User Id not Found . Pls Try again .");
        }
    }
    /////////////////////////////////////////////////////////////////////////////
    private void signUp() {
        // Implement code for signing up
        Scanner sc = new Scanner(System.in);
        String name,password;
        System.out.println("Enter Your Name : ");
        name = sc.nextLine();
        System.out.println("Enter Your Password : ");
        password = sc.next();
        User user =new User(name,password);
        GenerateUserID(user);
        System.out.println("Your User name is : "+user.name + "\nYour User Id is :"+ user.User_id);
        System.out.println("\nThanks for Signing Up "+user.name.toUpperCase()+" !!! Hope You Have a wonderful Experience!!");
        Admin.addUser(users, user);
    }
    //////////////////////////////////////////////////////////////////////////////
    private void GenerateUserID(User user){
        Random r =new Random();
        int id=r.nextInt(999999);
        if( id < 100000){
            id+=100000;
        }
        user.User_id=id;
//        for (int i = 0; i < users.toArray().length; i++) {   was trying to not repeat two ids but in this way even if i increase id by 1 there is no
//            int temp = users.get(i).User_id;                 guarantee that the ids assigned before may not be same after incrementing i
//            if(id == temp){
//                id++;
//            }
//        }
    }
}
class User{
    String name;

    public String getPassword() {
        return Password;
    }
    private String Password;
    private double Prev_Transaction;
    int User_id;
    protected double Balance;
    private int identify;
    User(String name, String password) {
        this.name = name;
        this.Password=password;
    }
    public User() {
    }
    public double getBalance(){
        return this.Balance;
    }
    public void getPrev_Transaction() {
        if(this.identify == 1){
            System.out.println("Deposited = Rs "+this.Prev_Transaction);
        } else if (this.identify == 0) {
            System.out.println("Transferred = Rs "+this.Prev_Transaction);
        }else {
            System.out.println("Withdrawn = Rs "+this.Prev_Transaction);
        }
    }

    public int setPrev_Transaction(double prev_Transaction,int identifier) {
        this.Prev_Transaction = prev_Transaction;
        this.identify = identifier;
        return -1;
    }
}
class Admin {
    public String getName() {
        return Name;
    }

    public String getPassword() {
        return Password;
    }

    private String Name = "Aum";
    private String Password ="vesit";
    private final int ADMIN_ID = 123456;
    static double BANK_MONEY;

    protected static void addUser(List<User> users, User user) {
        users.add(user);
        System.out.println("User " + user.name + " added successfully!");
    }

    protected void deleteUser(List<User> users) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the name of the user whose account needs to be deleted: ");
        String name = sc.next();
        System.out.println("Enter the id: ");
        int id = sc.nextInt();
        User user = getId(id,users);
        users.remove(user);
    }

    protected void viewBankTotalBalance(List<User> users) {
        System.out.println("\nThe Total Bank Balance is = "+ BANK_MONEY);
    }
    private User getId(int id,List<User> users){
        for (int i = 0; i <users.toArray().length ; i++) {
            if(id == users.get(i).User_id){
                return users.get(i);
            }
        }
        return null;
    }
    protected void viewUsers(List<User> users) {
        System.out.println("\nWelcome Mr "+this.Name+" . Here are the list of users in our bank and their details :\n");
        System.out.println("User_Name \t\t\t\t User_Id \t\t\t\t Balance\n");
        for (User user : users) {
            System.out.println(user.name + " \t\t\t\t " + user.User_id + " \t\t\t\t " + user.Balance);
        }
//        System.out.println(users.size());
    }
    static void UpdateBankBalance(double amt){
        Admin.BANK_MONEY += amt;
    }
}