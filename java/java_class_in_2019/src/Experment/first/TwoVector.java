package Experment.first;

/**
 * TwoVector
 */
public class TwoVector {
    public static void main(String[] args) {
        int [][]num = {
            {1, 2, 3, 4},
            {6, 7, 8, 9},
            {11, 12, 13, 14},
            {16, 17, 18, 19},
            {21, 22, 23, 24},
        };

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                System.out.print(num[i][j] + " ");
            }
            System.out.println();
        }
    }
}