import javafx.geometry.Pos;
import models.Comment;
import models.Post;
import models.User;
import org.junit.Before;
import org.junit.Test;
import play.test.Fixtures;
import play.test.UnitTest;

public class AllTest extends UnitTest {
    @Before
    public void setup() {
        // 先清空数据库然后测试
        // 保证单元测试环境相同(复现性)
        Fixtures.deleteAllModels();
        Fixtures.loadModels("data/data.yml");
    }

    @Test
    public void fullTest() {
        assertEquals(2, User.count());
        assertEquals(3, Post.count());
        assertEquals(3, Comment.count());

        assertNotNull(User.connect("bob@gmail.com", "secret"));

    }

}
