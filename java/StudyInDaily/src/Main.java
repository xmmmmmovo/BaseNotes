import com.huaban.analysis.jieba.JiebaSegmenter;

import java.math.BigDecimal;

public class Main {
    public static void main(String[] args) {
//        String test = "今天我吃了一碗肥肠面，里面有大便";
        String test = "select * from user";
        JiebaSegmenter jiebaSegmenter = new JiebaSegmenter();
        System.out.println(jiebaSegmenter.process(test, JiebaSegmenter.SegMode.SEARCH));
    }
}
