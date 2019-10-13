package models;

import play.db.jpa.Model;

import javax.persistence.Entity;
import javax.persistence.Lob;
import javax.persistence.ManyToOne;
import java.util.Date;

@Entity
public class Post extends Model {
    public String title;
    public Date postAt;

    // Lob Large Object
    @Lob
    public String content;

    // 外键约束
    @ManyToOne
    public User author;

    public Post(String title, String content, User author) {
        this.title = title;
        this.postAt = new Date();
        this.content = content;
        this.author = author;
    }


}
