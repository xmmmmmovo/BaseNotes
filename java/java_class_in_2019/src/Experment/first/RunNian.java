package Experment.first;

import java.util.Scanner;

/**
 * RunNian
 */
public class RunNian {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int year = sc.nextInt();

        if ((year % 4 == 0) &&
         (year % 100 != 0 || year % 400 == 0)) {
             System.out.println("Is Leak Year");
        } else {
            System.out.println("Isn't Leak Year");
        }

        sc.close();
        return;
    }
}