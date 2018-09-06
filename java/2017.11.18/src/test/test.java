package test;

import java.util.Arrays;
import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] num  = new int[n];
        for (int i = 0; i < n; i++) {
            num[i] = scanner.nextInt();
        }

        int[] num2 = Arrays.copyOf(num, num.length);
        int[] num3 = Arrays.copyOf(num, num.length);

        Factory factory = new Factory();

        BaseSort selectsort = new SelectSort();
        factory.setSort(selectsort);
        factory.doSort(num);

        BaseSort insertsort = new InsertSort();
        factory.setSort(insertsort);
        factory.doSort(num2);

        BaseSort quicksort = new QuickSort();
        factory.setSort(quicksort);
        factory.doSort(num3);
    }
}