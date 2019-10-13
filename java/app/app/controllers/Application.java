package controllers;

import play.*;
import play.mvc.*;

import java.util.*;

import models.*;

/**
 * 这里继承自Controller
 * 这说明这个类已经是一个控制器/应用了
 * 此时可以在里面定义route
 * 这里是http请求的入口
 * */
public class Application extends Controller {

    public static void index() {
        render();
    }

    public static void hello() {
        render("Application/hello.html");
    }

    public static void renderTextStudy() {
        renderText("这里是个字符串，且可以格式化输出");
//        renderJSON(); // 同样的这里也可以进行json返回，自动会把类转换为json object
    }
}