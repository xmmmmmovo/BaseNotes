package com.xmmmmovo.demo.controller;

import com.xmmmmovo.demo.domain.Order;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.ResponseBody;

import java.time.ZoneId;
import java.util.HashMap;
import java.util.Map;

@Controller
public class MainController {

    @GetMapping("/")
    public String index() {
        return "index";
    }

    @GetMapping("/jquery")
    public String jquery() {
        return "jquery";
    }

    @GetMapping("/angularjs")
    public String angularjs() {
        return "angularjs";
    }

    @GetMapping("postData")
    public @ResponseBody
    Map<String, Object> postData(String no, String date, int quantity) {
        System.out.println("no:" + no);
        System.out.println("date:" + date);
        System.out.println("quantity:" + quantity);

        Map<String, Object> map = new HashMap<>();
        map.put("msg", "ok");
        map.put("quantity", quantity);
        map.put("no", no);
        map.put("date", date);
        return map;
    }

    @PostMapping("/postJson")
    public @ResponseBody
    Map<String, Object> postJson(@RequestBody Order order) {
        System.out.println("no:" + order.no);
        System.out.println("date:" + order.date.toInstant().atZone(ZoneId.systemDefault()).toLocalDate());
        System.out.println("quantity:" + order.quantity);

        Map<String, Object> map = new HashMap<>();
        map.put("msg", "ok");
        map.put("value", order);
        return map;
    }
}
