import java.util.regex.Pattern;

public class RegTest {
    public static void main(String[] args) {
        String testString = new String("长度:0 39.916322 116.395322。长度:1 39.918086 116.402703。长度:1 39.920921 116.423812,");
        String[] s = testString.split("。|,|，"); // 正则切
        for (String ss :
                s) {
            System.out.println(ss);
            String[] sss = ss.split(" ");
            System.out.println(sss[0].substring(3, 4));
            System.out.println(sss[1]);
            System.out.println(sss[2]);
        }
        System.out.println();
    }
}
