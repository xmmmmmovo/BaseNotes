package com.nucandroid.arraylist;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class ArrayListDemo {
    public static void main(String[] args) {
        ArrayList<Person> personList = new ArrayList<>();
        List<Person> addition = new ArrayList<>();
        Person wang = new Person("wangtianrui", 25);
        personList.add(wang);

        Iterator<Person> iterator = personList.iterator();
    }
}
