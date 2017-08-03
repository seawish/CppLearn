CMake学习
-----------
### 相关链接：
- [CMake入门实战](http://www.hahack.com/codes/cmake/)（**`原文链接`**）
- [CMake官方教程](https://cmake.org/cmake-tutorial/)
- [CMake官方文档](https://cmake.org/cmake/help/cmake2.4docs.html)

### CMake命令
> 在 linux 平台下使用 CMake 生成 Makefile 并编译的流程如下：
   >
   > 1. 编写 CMake 配置文件 CMakeLists.txt 。
   > 2. 执行命令 cmake PATH 或者 ccmake PATH 生成 Makefile。 
       ccmake 和 cmake 的区别在于前者提供了一个交互式的界面。
       其中， PATH 是 CMakeLists.txt 所在的目录。
   > 3. 使用 make 命令进行编译。
       ccmake 和 cmake 的区别在于前者提供了一个交互式的界面。
       
### 目录结构
#### demo1: 单个源文件

#### demo2: 同一目录，多个源文件

#### demo3：多个目录，多个源文件

#### demo4: 自定义编译选项
>     CMake允许为项目增加编译选项，从而可以根据用户的环境和需求选择最合适的编译方案。
>     例如，可以将 math_functions 库设为一个可选的库，
>     如果该选项为 ON ，就使用该库定义的数学函数来进行运算。否则就调用标准库中的数学函数库。
##### 步骤
1. 修改CMakeLists文件
2. 修改main.cc文件
3. 修改config.h.in文件
4. 编译项目
```$xslt
编译项目：
    1. 使用ccmake命令，也可以用cmake -i命令，提供交互式配置界面
    2. 按enter修改变量值
    3. 按c键: 完成并处理配置文件, 该步骤将生成config.h
    4. 按g键：生成Makefile并退出。
``` 

#### demo5: 安装和测试
