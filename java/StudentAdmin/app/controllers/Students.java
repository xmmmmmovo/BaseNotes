package controllers;

import models.Student;

public class Students extends CRUD {

    public static void modifyName(String id) {
        Student stu = Student.findById(Long.parseLong(id));

        render("@changename", stu);
    }

    public static void doModifyName(Student object){
        Student st = Student.findById(object.id);

        if (null != object.name) {
            // 保存新名字
            st.name = object.name;
            st.save();
            render("@modifynamedone", object);
        }
    }

}
