import java.util.Scanner;

/**
 * Gift
 */
public class Gift {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String gift = (String)sc.nextLine();

        switch (gift) {
            case "1":
                System.out.println("1 gift");
                break;
            case "2":
                System.out.println("2 gift");
                break;
            case "3":
                System.out.println("3 gift");
                break;

            default:
                System.out.println("No Gifts For You!");
                break;
        }

        sc.close();
    }
}