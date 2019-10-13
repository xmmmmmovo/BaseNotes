package models;

/**
 * 用户表
 */

import play.db.jpa.Model;

import javax.persistence.Entity;

@Entity
//或者
//@Table(name = "User") //但个人更倾向于第一种类名即表名的写法 比较顺手
public class User extends Model {
    public String email;
    public String fullName;
    public String password;
    public boolean isAdmin = false;

    public User(String email, String fullName, String password) {
        this.email = email;
        this.fullName = fullName;
        this.password = password;
    }

    public static User connect(String email, String password) {
        return find("byEmailAndPassword", email, password).first();
    }

}