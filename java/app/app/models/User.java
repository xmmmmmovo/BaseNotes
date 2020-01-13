package models;

/**
 * 用户表
 */

import play.data.validation.*;
import play.db.jpa.Model;

import javax.persistence.Entity;
import javax.persistence.Table;

@Entity
@Table(name = "blog_user")
public class User extends Model {

    @Required
    @Email
    public String email;

    @Required
    @MaxSize(64)
    public String fullName;

    @Password
    @Required
    @MinSize(8)
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

    @Override
    public String toString() {
        return fullName;
    }
}