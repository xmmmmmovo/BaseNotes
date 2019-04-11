package com.xmmmmmovo.demo.controller;

import com.sun.org.apache.xerces.internal.xs.StringList;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

import java.util.Map;

@Controller
public class MainController {

    @GetMapping("/")
    public String index(Model model) {
        model.addAttribute("name", "张三");
        return "index";
    }

}
