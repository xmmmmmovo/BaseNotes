package models;

import play.*;
import play.db.jpa.*;
import play.data.validation.*;
import javax.persistence.*;
import java.util.*;

@Entity
public class Teacher extends Model {
	@Required
	@MaxSize(8)
	public String name;

	public String email;

	/**
	 * 稍微解释一下下面这几个字段意思
	 * mappedBy参加下面这篇
	 * https://blog.csdn.net/qq_31924435/article/details/53786717
	 * 所以这里的myTeacher就是跟Student类里面对应的
	 * cascade 参见下面的博客
	 * https://www.jianshu.com/p/e8caafce5445
	 * fetch看这篇
	 * https://thoughts-on-java.org/entity-mappings-introduction-jpa-fetchtypes/
	 */
	@OneToMany(mappedBy = "myTeacher", cascade = CascadeType.ALL, fetch = FetchType.LAZY)
	public List<Student> students;
	
	public String toString() {
		return name;
	}
}
