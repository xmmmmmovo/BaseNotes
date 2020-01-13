package models;

import play.data.validation.Email;
import play.data.validation.Required;
import play.db.jpa.Model;

import javax.persistence.Entity;

/**
 * 懒得写成接口了 就这样吧
 * */
@Entity
public class Postgraduate extends Model {
    @Required
    public String name;

    @Required
    public double cost;

    public String toString() {
        return name;
    }
}
