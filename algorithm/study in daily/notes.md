# 笔记

## tinghuaOJ

### tutorial

- 用double，哪怕是简单的int类型输出如果需要int那就`.0f`
- 尽量多用变量保险，因为内存是足够的
- 处理多个空格的时候，如果需要从空格中间读取char类型，只需要利用空格，如下

> scanf("%lf %c %lf", &num1, &op , &num2);
> 这一句就直接把num1与num2中间空格全部无视，直接读取operator
