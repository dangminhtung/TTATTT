import java.util.Scanner;

class Main {
    public static void main(String[] args) {
      Scanner myObj = new Scanner(System.in);  // Create a Scanner object
      System.out.println("Enter username");
  
      float a = myObj.nextInt();  // Read user input
    float b= myObj.nextInt();
    
    a=a+b;
    b=a-b;
    a=a-b;
    System.out.println(a);
    System.out.println(b);

    }
  }