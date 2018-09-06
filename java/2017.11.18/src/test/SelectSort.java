package test;
//选择排序
public class SelectSort extends BaseSort{
    public void sort(int[] a){
        int temp;

        for (int i = 0; i < a.length - 1; i++) {
            for (int j = 1 + i; j < a.length; j++) {
                if(a[i] < a[j]){
                    temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                }
            }
        }

        BaseSort show = new BaseSort();
        show.sort(a);
    }
}
