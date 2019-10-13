import javafx.geometry.Pos;
import models.Comment;
import models.Post;
import models.User;
import org.junit.Before;
import org.junit.Test;
import play.test.Fixtures;
import play.test.UnitTest;

import java.util.List;

/**
 * 文章单元测试类
 */
public class PostTest extends UnitTest {

    /**
     * 装载函数
     * 会在执行这个单元测试之前先执行
     */
    @Before
    public void setup() {
        // 先清空数据库然后测试
        // 保证单元测试环境相同(复现性)
        Fixtures.deleteAllModels();
    }

    @Test
    public void createPost() {
        // 先新建一个user 便于以后利用
        User bob = new User("bob@123.com", "sb bob", "请不要明文传密码").save();
        new Post("first post", "Hello Play!", bob).save();
        // 这里检查是否插入成功
        assertEquals(1, Post.count());

        // fetch 返回的是一个List 意思是获取所有的查询结果
        List<Post> bobPostList = Post.find("byAuthor", bob).fetch();
        // 因为我们就新建(插入)了一个post
        // 所以在这里判断是否就插入了一个
        assertEquals(1, bobPostList.size());

        // 取第一个post
        // 这里直接取就可以 因为如果不够1各会在上面直接断言跳出
        Post firstPost = bobPostList.get(0);

        // 判断是否为空
        assertNotNull(firstPost);
        assertNotNull(firstPost.postAt);

        // 这里判断是否相等
        assertEquals(bob, firstPost.author);
        assertEquals("first post", firstPost.title);
        assertEquals("Hello Play!", firstPost.content);
        Fixtures.deleteAllModels();
    }

    @Test
    public void postComment() {
        // 先新建用户
        User user = new User("bob@123.com", "bob shit", "不要明文传密码!").save();
        // 然后新建文章
        Post post = new Post("shit post", "辣鸡框架", user).save();

        // 这里的.save的方法就是存储到数据库的意思
        new Comment("sss", "a", post).save();
        new Comment("ssssss", "b", post).save();

        List<Comment> list = Comment.find("byPost", post).fetch();
        // 剩下的就懒得写了 差不多都那个样子

        Fixtures.deleteAllModels();
    }

    @Test
    public void useCommentRelation() {
        // 先新建用户
        User user = new User("bob@123.com", "bob shit", "不要明文传密码!").save();
        // 然后新建文章
        Post post = new Post("shit post", "辣鸡框架", user).save();

        // 这里的.save的方法就是存储到数据库的意思
        post.addComment("sss", "a");
        post.addComment("sssss", "ass");

        assertEquals(1, User.count());
        assertEquals(1, Post.count());
        assertEquals(2, Comment.count());

        post = Post.find("byAuthor", user).first();
        assertNotNull(post);

        assertEquals(2, post.comments.size());
        assertEquals("sss", post.comments.get(0).author);

        post.delete();

        assertEquals(1, User.count());
        assertEquals(0, Post.count());
        assertEquals(0, Comment.count());

        Fixtures.deleteAllModels();
    }
}
