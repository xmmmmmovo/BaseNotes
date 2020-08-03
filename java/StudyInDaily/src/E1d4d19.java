public class E1d4d19 {
    public static void min(int[][] a) {
        int Rlo = 1;
        int Rhi = a.length;
        int Rmid;
        //
        int Clo = 1;
        int Chi = a[0].length;
        int Cmid;

        while (Rlo < Rhi && Clo < Chi) {
            Rmid = (Rlo + Rhi) / 2;
            Cmid = (Clo + Chi) / 2;
            if (a[Rmid - 1][Cmid] < a[Rmid][Cmid])
                Rhi = Rmid - 1;
            else if (a[Rmid][Cmid] > a[Rmid + 1][Cmid])
                Rlo = Rmid + 1;
            else if (a[Rmid][Cmid - 1] < a[Rmid][Cmid])
                Chi = Cmid - 1;
            else if (a[Rmid][Cmid] > a[Rmid][Cmid + 1])
                Clo = Cmid + 1;
            else {
                System.out.printf("row=%d,col=%d", Rmid, Cmid);
                return;
            }
        }
        System.out.println("can't find");
    }

    public static void main(String[] args) {
        int N = 3;
        int[][] a = {
                {1, 2, 3},
                {2, 2, 3},
                {1, 2, 3}
        };
        min(a);
        //StdOut.println(min(a));
    }//end main
}