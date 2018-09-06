package test;

public class InsertSort extends BaseSort {
    public void sort(int[] a){
        for (int i = 1; i < a.length; i++) {
            int j = i - 1;
            int temp = a[i];

            while(j >= 0 && a[j] < temp){
                a[j+1] = a[j];
                j--;
            }

            a[j+1] = temp;
        }

        BaseSort show = new BaseSort();
        show.sort(a);
    }
}
