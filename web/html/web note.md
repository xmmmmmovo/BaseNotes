# web笔记

## HTML教程

### 实例解析

- **<!DOCTYPE html>** 声明为 HTML5 文档
- **<html>** 元素是 HTML 页面的根元素
- **<head>** 元素包含了文档的元（meta）数据，如 <meta charset="utf-8"> 定义网页编码格式为 **utf-8**。
- **<title>** 元素描述了文档的标题
- **<body>** 元素包含了可见的页面内容
- **<h1>** 元素定义一个大标题
- **<p>** 元素定义一个段落(会忽略原文的排版)

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

[html所有标签列表](http://www.w3school.com.cn/tags/index.asp)

[全局属性](https://www.runoob.com/tags/ref-standardattributes.html)

### 图像

- 背景图片<background>

- 对其方案

  - bottom
  - middle
  - top

- 浮动排列

  - left
  - right

- **alt** 当图片显示不出来的时候显示alt中的文本

- 图片区域点击事件

  ```html
  <html>
      <body>
  
      <p>请点击图像上的星球，把它们放大。</p>
  
      <img
      src="/i/eg_planets.jpg"
      border="0" usemap="#planetmap"
      alt="Planets" />
  
      <map name="planetmap" id="planetmap">
          <area
          shape="circle"
          coords="180,139,14"
          href ="/example/html/venus.html"
          target ="_blank"
          alt="Venus" />
  
          <area
          shape="circle"
          coords="129,161,10"
          href ="/example/html/mercur.html"
          target ="_blank"
          alt="Mercury" />
  
          <area
          shape="rect"
          coords="0,0,110,260"
          href ="/example/html/sun.html"
          target ="_blank"
          alt="Sun" />
      </map>
  
      <p><b>注释：</b>img 元素中的 "usemap" 属性引用 map 元素中的 "id" 或 "name" 属性（根据浏览器），所以我们同时向 map 元素添加了 "id" 和 "name" 属性。</p>
  
      </body>
  </html>
  ```

### 表格

- 三个分块 为的就是可以应用不同的样式表
  - **<thead>** 表头
  - **<tbody>** 表身
  - **<tfoot>** 表尾
- **<colgroup>** 标签
  - <colgroup> 标签用于对表格中的列进行组合，以便对其进行格式化。<br>如需对全部列应用样式，<colgroup> 标签很有用，这样就不需要对各个单元和各行重复应用样式了。<br><colgroup> 标签只能在 table 元素中使用。
- **<col>** 标签
  - <col> 标签为表格中一个或多个列定义属性值。<br>如需对全部列应用样式，<col> 标签很有用，这样就不需要对各个单元和各行重复应用样式了。<br>您只能在 table 或 colgroup 元素中使用 <col> 标签。

## HTML5教程