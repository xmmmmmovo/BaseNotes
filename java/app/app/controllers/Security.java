package controllers;

import models.User;

public class Security extends Secure.Security {

    static boolean authenticate(String userName, String pwd) {
        return User.connect(userName, pwd) != null;
    }

    public static boolean check(String profile) {
        if (Security.isConnected()) {
            if (profile.equals("admin")) {
                String user = Security.connected();
                User userFind = User.find("byEmail", user).first();
                return userFind.isAdmin;
            } else {
                return true;
            }
        } else {
            return false;
        }
    }

}
