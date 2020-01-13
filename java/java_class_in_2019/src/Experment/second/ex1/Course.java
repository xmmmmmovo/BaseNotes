package Experment.second.ex1;

import java.util.ArrayList;
import java.util.List;

public class Course {
    private String ClassName;
    private int ClassNumber;
    private List<Integer> PreClassList;
    public Course() {
        PreClassList = new ArrayList<>();
    }

    public Course(String className, int classNumber, List<Integer> preClassList) {
        ClassName = className;
        ClassNumber = classNumber;
        PreClassList = preClassList;
    }

    public String getClassName() {
        return ClassName;
    }

    public void setClassName(String className) {
        ClassName = className;
    }

    public int getClassNumber() {
        return ClassNumber;
    }

    public void setClassNumber(int classNumber) {
        ClassNumber = classNumber;
    }

    public List<Integer> getPreClassList() {
        return PreClassList;
    }

    public void setPreClassList(List<Integer> preClassList) {
        PreClassList = preClassList;
    }

    public void printClassMessage() {
        System.out.println("课程名：" + ClassName);
        System.out.println("课程编号：" + ClassNumber);
        System.out.println("预先课程编号：");
        for (Integer pre:
        PreClassList){
            System.out.println(pre + " ");
        }
        System.out.println();
    }
}
