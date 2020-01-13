package homework2019;

import java.util.ArrayList;
import java.util.List;

public class MBigDecimal {
    private List<Integer> number;
    private List<Integer> result;

    public MBigDecimal() {
        number = new ArrayList<>();
        result = new ArrayList<>();
    }

    public MBigDecimal(int i) {
        this();
        String.valueOf(i);
    }

    public MBigDecimal(String string) {
        this();
    }
}
