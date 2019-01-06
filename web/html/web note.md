# web笔记

## HTML教程

### 实例解析

- **<!DOCTYPE html>** 声明为 HTML5 文档
- **<html>** 元素是 HTML 页面的根元素
- **<head>** 元素包含了文档的元（meta）数据，如 <meta charset="utf-8"> 定义网页编码格式为 **utf-8**。
- **<title>** 元素描述了文档的标题
- **<body>** 元素包含了可见的页面内容
- **<h1>** 元素定义一个大标题
- **<p>** 元素定义一个段落

### 例子

- HTML 链接是通过标签 <a> 来定义的

  ```html
  <a href="http://www.runoob.com">这是一个链接</a>
  ```

- HTML 图像是通过标签 <img> 来定义的![错误图片](https://img-blog.csdnimg.cn/20181118200847500.png)

  ```html
  <!--
  	注意这里的图片加载不出问题
  	1. 有可能被abp广告管理给禁用掉了(错误信息见上图)
  	2. 位置错误(一定要注意相对路径./(当前路径)与../(当前路径上级)区别)
  -->
  <img src="./image/testpic.jpg" width="500" height="744"/>
  ```

- **`<br> <br/> `**换行(建议用后者 但是前者可以在所有浏览器中适用)
- **<hr>** 水平线

### 属性

[html所有标签列表](https://www.runoob.com/tags/html-reference.html)



## HTML5教程