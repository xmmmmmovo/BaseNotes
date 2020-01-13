package com.nucandroid.extend;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        Employee employee = new Employee("bao's mimei", 1, 10000);

        JDBCDao.SaveListener listener = new JDBCDao.SaveListener() {
            @Override
            public void onSucceed(String json) {

            }

            @Override
            public void onFail() {
            }
        };
        employee.save(listener);
    }
}
