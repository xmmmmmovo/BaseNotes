package Experment.second.ex1;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Course c1 = new Course(
                "睡觉艺术", 114514,
                new ArrayList<Integer>(){{add(1);add(12);add(123);}});
        Course c2 = new Course();
        List<Integer> list = new ArrayList<>();
        list.add(12);
        list.add(33);
        list.add(44);

        c2.setClassName("药水艺术");
        c2.setClassNumber(123);
        c2.setPreClassList(list);

        c1.printClassMessage();
        c2.printClassMessage();
    }
}
