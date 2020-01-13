package models;

import play.data.validation.Required;
import play.db.jpa.Model;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

@Entity
public class Post extends Model {
    @Required
    public String title;
    public Date postAt;

    // Lob Large Object
    @Required
    @Lob
    public String content;

    // 这里的mappedBy 代表post里面的comment类是别的关系的
    // cascade代表如果删除post 里面的所有commit也会删除
    @OneToMany(mappedBy = "post", cascade = CascadeType.ALL)
    public List<Comment> comments;

    public Post(String title, String content) {
        this.title = title;
        this.postAt = new Date();
        this.content = content;
        this.comments = new ArrayList<>();
    }

    /**
     * 这里是添加评论方法
     * */
    public Post addComment(String author, String content) {
        Comment comment = new Comment(author, content, this).save();
        this.comments.add(comment);
        this.save();
        return this;
    }

}
