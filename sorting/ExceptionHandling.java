package sorting;

import java.util.Scanner;


class InvalidInputException extends Exception{
    @Override
    public String toString() {
        return "InvalidInputException";
    }
}

class CannotDivideBy0 extends Exception {
    @Override
    public String toString() {
        return "CannotDivideBy0";
    }
}

class MaxInputException extends Exception {
    @Override
    public String toString() {
        return "MaxInputException";
    }
}

class MaxMultiplierException extends Exception {
    @Override
    public String toString() {
        return "MaxMultiplierException by AUM";
    }
}

public class ExceptionHandling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String ch;
        System.out.println("Enter the Operation:");
        ch = sc.next();

        switch (ch) {
            case "+": {
                System.out.println("Enter a and b:");
                int a = sc.nextInt();
                int b = sc.nextInt();
                if (a > 100000 || b > 100000) {
                    try {
                        throw new MaxInputException();
                    } catch (MaxInputException e) {
                        System.out.println(e.toString());
                    }
                }
                System.out.println("The sum is- " + (a + b));
                break;
            }
            case "-": {
                System.out.println("Enter a and b:");
                int a = sc.nextInt();
                int b = sc.nextInt();
                if (a > 100000 || b > 100000) {
                    try {
                        throw new MaxInputException();
                    } catch (MaxInputException e) {
                        System.out.println(e.toString());
                    }
                }
                System.out.println("The Subtraction is- " + (a - b));
                break;
            }
            case "*": {
                System.out.println("Enter a and b:");
                int a = sc.nextInt();
                int b = sc.nextInt();
                if (a > 70000 || b > 70000) {
                    try {
                        throw new MaxMultiplierException();
                    } catch (MaxMultiplierException e) {
                        System.out.println(e.toString());
                    }
                }else{
                    System.out.println("The Multiplication is- " + (a * b));
                }
                break;
            }
            case "/": {
                System.out.println("Enter a and b:");
                int a = sc.nextInt();
                int b = sc.nextInt();
                if (a > 100000 || b > 100000) {
                    try {
                        throw new MaxInputException();
                    } catch (MaxInputException e) {
                        System.out.println(e.toString());
                    }
                }
                if ( b == 0) {
                    try {
                        throw new CannotDivideBy0();
                    } catch (CannotDivideBy0 e) {
                        System.out.println(e.toString());
                    }
                }
                System.out.println("The Division is- " + (a / b));
                break;
            }
            default:
                System.out.println("Invalid Operation");
        }
    }
}
