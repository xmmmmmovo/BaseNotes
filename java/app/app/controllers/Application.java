package controllers;

import play.*;
import play.mvc.*;

import java.util.*;

import models.*;

public class Application extends Controller {

    public static void index() {
        new User("abc@163.com", "123456", "Abc Def").save();
        User bob = User.find("byEmail", "abc@163.com").first();
        System.out.println(bob.email);
        System.out.println(bob.fullName);
        render();
    }

    public static void hello() {
        render("Application/hello.html");
    }

}