package models;

import javafx.geometry.Pos;
import play.db.jpa.Model;

import javax.persistence.Entity;
import javax.persistence.Lob;
import javax.persistence.ManyToOne;
import java.util.Date;

@Entity
public class Comment extends Model {
    public String author;
    public Date postedAt;

    @Lob
    public String content;

    @ManyToOne
    public Post post;

    public Comment(String author, String content, Post post) {
        this.author = author;
        this.postedAt = new Date();
        this.content = content;
        this.post = post;
    }
}
