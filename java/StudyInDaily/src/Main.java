import java.math.BigDecimal;

public class Main {
    public static void main(String[] args) {
        BigDecimal b1 = new BigDecimal("1.0");
        BigDecimal b2 = new BigDecimal("3.0");

//        b1.setScale(100000);
        System.out.println(b1.divide(b2, 1000, BigDecimal.ROUND_HALF_UP).toString());
    }
}
