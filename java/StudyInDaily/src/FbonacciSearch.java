import java.util.Arrays;

public class FbonacciSearch {

    /**
     * <p>name: main</p>
     * <p>description: </p>
     * <p>return: void</p>
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        int[] array = {1, 5, 15, 22, 25, 31, 39, 42, 47, 49, 59, 68, 88, 88,
                88, 88, 88};
        System.out.println("result: " + fbSearch(array, 31));
    }

    /**
     * <p>
     * name: fbSearch
     * </p>
     * <p>
     * description: 斐波那契查找实现
     * </p>
     * <p>
     * return: int
     * </p>
     */
    public static int fbSearch(int[] array, int a) {
        if (array == null || array.length == 0) {
            return -1;
        } else {
            int length = array.length;
            int[] fb = makeFbArray(20);// 制造一个长度为10的斐波数列
            int k = 0;
            while (length > fb[k] - 1) {// 找出数组的长度在斐波数列（减1）中的位置，将决定如何拆分
                k++;
            }
            int[] temp = Arrays.copyOf(array, fb[k] - 1);// 构造一个长度为fb[k] - 1的新数列
            for (int i = length; i < temp.length; i++) {
                if (i >= length) {
                    temp[i] = array[length - 1];
                }
            }

            int low = 0;
            int hight = array.length - 1;
            while (low <= hight) {
                System.out.println(k);
                int middle = low + fb[k - 1] - 1;
                System.out.println(middle);
                if (temp[middle] > a) {
                    hight = middle - 1;
                    k = k - 1;
                } else if (temp[middle] < a) {
                    low = middle + 1;
                    k = k - 2;
                } else {
                    if (middle <= hight) {
                        return middle;// 若相等则说明mid即为查找到的位置
                    } else {
                        return hight;// middle的值已经大于hight,进入扩展数组的填充部分,即最后一个数就是要查找的数。
                    }
                }
            }
            return -1;
            // return recurse(array, fb, a, low, hight, k);
        }
    }

    /**
     * <p>
     * name: makeFbArray
     * </p>
     * <p>
     * description: 生成指定长度的斐波数列
     * </p>
     * <p>
     * return: int[]
     * </p>
     */
    public static int[] makeFbArray(int length) {
        int[] array = null;
        if (length > 2) {
            array = new int[length];
            array[0] = 1;
            array[1] = 1;
            for (int i = 2; i < length; i++) {
                array[i] = array[i - 1] + array[i - 2];
            }
        }
        return array;
    }

    /**
     * <p>
     * name: recurse
     * </p>
     * <p>
     * description: 递归实现，可以来代替while (low <= hight)遍历
     * </p>
     * <p>
     * return: int
     * </p>
     */
    public static int recurse(int[] array, int[] fb, int a, int low, int hight,
                              int k) {
        if (array == null || array.length == 0 || a < array[low]
                || a > array[hight] || low > hight) {
            return -1;
        }
        int middle = low + fb[k - 1] - 1;
        if (a < array[middle]) {
            return recurse(array, fb, a, low, middle - 1, k - 1);
        } else if (a > array[middle]) {
            return recurse(array, fb, a, middle + 1, hight, k - 2);
        } else {
            if (middle <= hight) {
                return middle;
            } else {
                return hight;
            }
        }
    }
}
