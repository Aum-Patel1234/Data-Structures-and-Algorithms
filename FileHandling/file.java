package FileHandling;
import java.io.*;

public class file {
    public static void main(String[] args)  {
//        try(InputStreamReader isr=new InputStreamReader(System.in)) {
//            System.out.println("Enter the data:");
//            int a=isr.read();
//            while (isr.ready()){
//                System.out.println((char) a);
//                a=isr.read();
//            }
//            //isr.close();
//        }catch (IOException e){
//            System.out.println(e.getMessage());
//        }
//
//        try (FileReader fr = new FileReader("C:\\Users\\AUM PATEL\\Desktop\\Data Structures and Algorithms\\FileHandling\\text.txt")) {
//            int a=fr.read();
//            while (fr.ready()){
//                System.out.println((char) a);
//                a= fr.read();
//            }
//        } catch (IOException e) {
//            System.out.println(e.getMessage());
//        }

//        try(FileWriter fw=new FileWriter("C:\\\\Users\\\\AUM PATEL\\\\Desktop\\\\Data Structures and Algorithms\\\\FileHandling\\\\text.txt",true)){
//            fw.write("\nffff");
//            fw.write("Hello World!");
//        }catch (IOException e){
//            System.out.println(e.getMessage());
//        }

        try{
            File f=new File("C:\\\\Users\\\\AUM PATEL\\\\Desktop\\\\Data Structures and Algorithms\\\\FileHandling\\\\example.txt");
            f.createNewFile();
        }catch (IOException e){
            System.out.println(e.getMessage());
        }

        try (FileWriter fw=new FileWriter("C:\\\\Users\\\\AUM PATEL\\\\Desktop\\\\Data Structures and Algorithms\\\\FileHandling\\\\example.txt");){

            fw.write("Good Morning!");

        }catch (IOException e){
            System.out.println(e.getMessage());
        }
    }
}

/*

import java.io.*;
import java.io.IOException;
import java.util.Scanner;

class Main {
  public static void main(String[] args) {

    // create
    try {
      File fo = new File("new-file.txt");
      fo.createNewFile();
    } catch (IOException e) {
      System.out.println(e.getMessage());
    }

    // write in the file
    try {
      FileWriter fw = new FileWriter("new-file.txt");
      fw.write("सर्वधर्मान्परित्यज्य मामेकं शरणं व्रज, अहं त्वां सर्वपापेभ्यो मोक्षयिष्यामि मा शुच:");
      fw.close();
    } catch (IOException e) {
      System.out.println(e.getMessage());
    }

    // reading from a file
    try (BufferedReader br = new BufferedReader(new FileReader("new-file.txt"))) {
      while (br.ready()) {
        System.out.println(br.readLine());
      }
    } catch (IOException e) {
        System.out.println(e.getMessage());
    }

    // create
    try {
      File fo = new File("random.txt");
      fo.createNewFile();
      if(fo.delete()) {
        System.out.println(fo.getName());
      }
    } catch (IOException e) {
      System.out.println(e.getMessage());
    }



  }
}

 */
