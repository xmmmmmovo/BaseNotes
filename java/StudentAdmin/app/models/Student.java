package models;

import play.data.validation.Email;
import play.data.validation.MaxSize;
import play.data.validation.Password;
import play.data.validation.Required;
import play.db.jpa.Model;

import javax.persistence.Entity;
import javax.persistence.ManyToOne;

@Entity
public class Student extends Model {
    @Required
    @MaxSize(8)
    public String name;

    @Required
    @Email
    @MaxSize(64)
    public String email;

    @Required
    public String address;

    @Required
    @ManyToOne // 多对一关系引导
    public Teacher myTeacher;
}
