package controllers;

import javafx.geometry.Pos;
import models.Post;
import play.mvc.Controller;

import java.util.List;

public class Blog extends Controller {

    public static void index() {
        List<Post> posts = Post.findAll();
        render(posts);
    }

    public static void form() {
        render();
    }

    public static void save(String title, String content) {
        Post post = new Post(title, content);

        validation.valid(post);
        if (validation.hasErrors()) {
            render("@form", post);
        }

        post.save();
        index();
    }

}
