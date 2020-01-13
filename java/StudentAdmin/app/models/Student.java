package models;

import play.*;
import play.data.validation.*;
import play.db.jpa.*;

import javax.persistence.*;
import java.util.*;

/**
 * 这里学号就用id就可以了
 * */
@Entity
public class Student extends Model {

    @Required
    public String name;

    @Required
	public double cost;

    public String toString() {
        return name;
    }

}