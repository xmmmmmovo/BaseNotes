package team.androidlab.train;

public class Test {
    public static void main(String[] args) {

//        DataManager<Integer>dataMnager = new DataManager<>();
//        dataMnager.setT(12);
//        System.out.println(dataMnager.getT());
//
//        DataManager<String> dataManager1 = new DataManager<>();
//        dataManager1.setT("fff");
//        System.out.println(dataManager1.getT());

        int[] a = new int[]{1, 2, 3};
        say(a);
        String[] b = new String[]{"excude", "???"};
    }

    static <T> void say(T ...t){
        for (int i = 0; i < t.length; i++) {
            System.out.print(t[i] + " ");
        }
    }
}
