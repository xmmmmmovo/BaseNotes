package com.nucandroid.extend;

import okhttp3.Response;
import okhttp3.ResponseBody;
import java.io.IOException;


public class JDBCObject {
    public void save(JDBCDao.SaveListener listener){
        Response response = JDBCHelper.getInstance().save(this);
        //201 成功返回
        if (response != null && response.code() == 201){
            try {
                String json = response.body().string();
                listener.onSucceed(json);
            } catch (IOException e) {
                listener.onFail();
                e.printStackTrace();
            }
        }else {
            listener.onFail();
        }
    }
}
