<center><bold>自己的LaTeX笔记</bold><center>





## [先贴教程总览！！](https://blog.csdn.net/garfielder007/article/details/51646604#t2)





## 公式

### 常用字符

- $$ + enter便可进入LaTeX编辑模式
- ^ 上标
- _ 下标
- {} 块/分组

### 常用环境

> \begin{equation}
>
> **自动编号** \label(eq: ```)**标签**
>
> \end{equation}
>
>
>
> \ref{eq:} **引用**

## 符号

### 希腊字母

- \alpha
- \beta
- \gamma
- \epsilon
- \pi
- \omerga



- \Gamma
- \Delta
- \Theta
- \Pi
- \Omega

### 常用函数

- \log
- \sin
- \cos
- \arcsin
- \arccos
- \ln
- \sqrt[]{} **根式**
- \frac{}{} **分式**

## 矩阵

> \begin{matrix}
>
> 	1 & 1 \\\
>
> 	1 & 1
>
> \end{matrix}
>
> 其中：
>
> & 分割**列**
>
> \\   分割**行**
>
>
>
> p小括号
>
> b中括号
>
> B大括号
>
> v单竖线
>
> V双竖线

- \dots **横向省略号**
- \vdots **竖向省略号**
- \ddots **斜向省略号**
- {n \times n} **n x n**

### 分块矩阵(矩阵嵌套)



### 其他命令

- \multicolumn{}{}{} **合并多列**
- \raisebox{}[]{} **调整高度**
- \hdotsfor{列数} **整列省略号** 

> \left ( **左括号**
>
> \begin{smallmatrix}
>
> \end{smallmatrix}
>
> \right ) **右括号**
>
> **行内小矩阵**

> \begin{array}{c|c}
>
> \hline **分割线**
>
> \end{array}

## 多行公式

> \begin{gather}
>
> ==== \notag **不自动编号** \ \**换行**
>
> ==== \ \
>
> \end{gather}

- {align}
- {split}
- {cases} **分段函数**
- 