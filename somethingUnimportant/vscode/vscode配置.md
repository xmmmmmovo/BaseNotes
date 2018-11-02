<center>算是一直留着的坑吧。。。。大致就是vscode编译c++的基本操作步骤</center>

<!--more-->

### 1.准备

- [MinGW-w64](https://versaweb.dl.sourceforge.net/project/mingw-w64/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe)  (这里只介绍MinGW-w64的方法，clang配置方法暂不讲解)
- [VScode](https://vscode.cdn.azure.cn/stable/7f3ce96ff4729c91352ae6def877e59c561f4850/VSCodeUserSetup-x64-1.28.2.exe)(并装有以下插件)
  - [**C/C++**](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)(俗称cpptools,代码提示及基本环境,**必须安装**！)
  - [C++ Intellisense](https://marketplace.visualstudio.com/items?itemName=austin.code-gnu-global)(快速查到定位地点 推荐安装)
  - [Hds's C/C++Snippets](https://marketplace.visualstudio.com/items?itemName=huangdongsheng.HdsCppSnippets)(能够快速打出部分代码片段例如,inc, fori便可直接显示)

### 2.配置

#### 安装MinGW

1. 下载[MinGW](https://mirrors.tuna.tsinghua.edu.cn/osdn/mingw/68260/mingw-get-setup.exe)(点击名字即可下载)
2. 打开
3. 关于安装设置问题可以参考这个博客:[点击访问链接](http://rsreland.net/archives/1760)<br>如果是跟我一样是64位的win10系统的话那么跟我下面的图片一样就行了<br>![配置](http://ww1.sinaimg.cn/large/006ZO6XQgy1fwtnmyh2gnj30er0as3yp.jpg)
4. 然后next，选择**安装路径**，next，等待最终显示完成便可以关闭了
5. 哦对了，别忘了设置一下***环境变量***<br>![](http://ww1.sinaimg.cn/large/006ZO6XQgy1fwqjwqjqb0j30np09x0tm.jpg)<br>![](http://ww1.sinaimg.cn/large/006ZO6XQgy1fwtnosym1ij30f303e74g.jpg)

#### 配置vscode

这个说来也容易

大致就是配置 c_cpp_properties.json(新版本中删除),    launch.json,    settings.json,     tasks.json这四个文件

- c_cpp_properties.json(这个文件主要是配置c文件路径的)<br>现在再也不用配置这个文件啦 你可以**删掉这个**了(感谢[HyYyrWang](https://wanghao15536870732.github.io/)的提醒)<br>因为编译器会**自动**找到你环境变量里面的编译工具**自动配置**啦！

- launch.json(这个主要是启动调试)<br>![launch](http://ww1.sinaimg.cn/large/006ZO6XQly1fwqf05jakpj30ee0czwel.jpg)

  ```json
  {
      "version": "0.2.0",
      "configurations": [
          {
              "name": "(gdb) Launch",
              "type": "cppdbg",
              "request": "launch",
              "program": "${fileDirname}/${fileBasenameNoExtension}.exe",//这里是运行的.exe文件名称
              "args": [],//这里写传入命令行参数文本(main经常里面void的就不用写了)
              "stopAtEntry": false,
              "cwd": "${workspaceFolder}",
              "environment": [],
              "externalConsole": true,
              "targetArchitecture": "x64", 
              "MIMode": "gdb",
              "miDebuggerPath": "D:\\anzhuang\\MinGW\\bin\\gdb.exe",//写自己环境的gdb
              "preLaunchTask": "g++",
              "setupCommands": [
                  {
                      "description": "Enable pretty-printing for gdb",
                      "text": "-enable-pretty-printing",
                      "ignoreFailures": true
                  }
              ]
          },
      ]
  }
  ```

- settings.json(无关紧要的设置)<br>这个我真忘了怎么弄出来的了。。。要不就新建吧。。。。

  ```json
  {
      "C_Cpp.errorSquiggles": "Enabled",//纠错
      "files.associations": {//文件关联
          "system_error": "c",
          "*.tcc": "cpp",
          "unordered_map": "cpp",
          "vector": "cpp",
          "array": "cpp",
          "initializer_list": "cpp",
          "utility": "cpp",
          "iostream": "cpp",
          "cmath": "cpp",
          "functional": "cpp",
          "tuple": "cpp",
          "istream": "cpp",
          "cctype": "cpp",
          "clocale": "cpp",
          "cstdint": "cpp",
          "cstdio": "cpp",
          "cstdlib": "cpp",
          "cwchar": "cpp",
          "cwctype": "cpp",
          "exception": "cpp",
          "fstream": "cpp",
          "iosfwd": "cpp",
          "limits": "cpp",
          "new": "cpp",
          "ostream": "cpp",
          "numeric": "cpp",
          "sstream": "cpp",
          "stdexcept": "cpp",
          "streambuf": "cpp",
          "type_traits": "cpp",
          "typeinfo": "cpp",
          "ctime": "cpp",
          "list": "cpp",
          "string": "cpp",
          "stdlib.h": "c",
          "math.h": "c",
          "stdio.h": "c"
      }
  }
  ```

- tasks.json(编译环节)<br>按``ctrl + shift + P`` 然后输入tasks 选择others(其实选哪个都行) 就会出现tasks.json文件了<br>![](http://ww1.sinaimg.cn/large/006ZO6XQly1fwqf2ujg4dj30km046t8q.jpg)![](http://ww1.sinaimg.cn/large/006ZO6XQly1fwqf2xa1sdj30jz031wec.jpg)

![tasks](http://ww1.sinaimg.cn/large/006ZO6XQly1fwqf05j6fpj30l805wdfx.jpg)

```json
{
    "version": "2.0.0",
    "command": "g++",//执行命令
    "args": ["-g","-std=c++11","${file}","-o","${fileDirname}\\${fileBasenameNoExtension}.exe"],   // 编译命令参数
    "problemMatcher": {
        "owner": "cpp",
        "fileLocation": ["relative", "${workspaceRoot}"],//文件地址
        "pattern": {
            "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
        "file": 1,
        "line": 2,
        "column": 3,
        "severity": 4,
        "message": 5
        }
    }
}
```



### 3.愉悦的c++编程

这里可以有非调试启动，但其实都是调试启动 没什么区别

p.s. 认为编译效率低的请用cmake

![](http://ww1.sinaimg.cn/large/006ZO6XQgy1fwtnsun34uj309k0gvdgh.jpg)



![](http://ww1.sinaimg.cn/large/006ZO6XQly1fwqf93sf5zj30oj0fot9t.jpg)



还可以把运行键位改成你喜欢的23333

![](http://ww1.sinaimg.cn/large/006ZO6XQgy1fwqfaavrn4j307h0anwei.jpg)

![](http://ww1.sinaimg.cn/large/006ZO6XQgy1fwqfbsj9g3j30tx05kwem.jpg)



### 4.中文乱码问题

你可能会遇到中文乱码问题 莫慌 只需几步你进能够完美解决这个问题

1. 打开设置<br>![](http://ww1.sinaimg.cn/large/006ZO6XQly1fwqlcbxzlej3064099dft.jpg)
2. 输入encoding<br>并且在下面的Guess Encoding上打上对勾<br>并且将下面的Encoding改成gb2312<br>![](http://ww1.sinaimg.cn/large/006ZO6XQly1fwqlcbyr2yj30y409v74t.jpg)



### 5.为什么需要用vscode？其他编译器不好吗？

其他编译器有些自然不错，像是vs,cLion什么的都很成熟并且功能强大

但是vscode有着一些得天独厚的优势，比如：当你只想写一个helloworld的时候 难道你还要新建一个项目嘛？

那真的是麻烦到爆炸，所以vscode轻便流畅，比较便于即开即用那种类型

最重要的是 他可以编译不止c++，以后我可能会拿来编译python, Golang, 或者Dart, 甚至小程序你都可以在这里开发，并且装了cmake插件的话还可以编译opencv，可以说它大大减轻了你的内存负担以及IDE过多问题，如果你一个项目里面有许多的语言需要编译，或许，你真的需要一个vscode

### 6.最后

有问题请联系我

就在右下角那个Daovoice就可以了