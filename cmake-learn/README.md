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
> CMake允许为项目增加编译选项，从而可以根据用户的环境和需求选择最合适的编译方案。
> 例如，可以将math_functions库设为一个可选的库，如果该选项为ON，就使用该库定义的数学函数来进行运算。
> 否则就调用标准库中的数学函数库。
##### 步骤
1. 修改CMakeLists文件
2. 修改main.cc文件
3. 修改config.h.in文件
4. 编译项目
```$xslt
编译项目：
    1. 使用ccmake命令，也可以用cmake -i命令，提供交互式配置界面。(需要先按c键才能看到变量)
    3. 按enter修改变量值
    4. 按c键: 完成并处理配置文件, 该步骤将生成config.h
    5. 按g键：生成Makefile并退出。
    6. 使用make install命令，库将按照到指定目录。
``` 

#### demo5: 安装和测试
> CMake 也可以指定安装规则，以及添加测试。
> 这两个功能分别可以通过在产生 Makefile 后使用 make install 和 make test 来执行。
##### 步骤
1. 定制安装规则
2. 为工程添加测试

#### demo6: 添加环境检查

#### demo7: 添加版本号
``` 
在demo6的基础上，修改demo7/CMakeCache.txt、config.h.in、main.cc文件。
```

#### demo8: 生成安装包
##### 步骤：
```
1. 构建一个 CPack 安装包
2. 导入 InstallRequiredSystemLibraries 模块，以便之后导入 CPack 模块；
3. 设置一些 CPack 相关变量，包括版权信息和版本信息，其中版本信息用了上一节定义的版本号；
4. 导入 CPack 模块。
```
##### 命令：

```cmake
cmake .  或 ccmake .
make
cpack -C CPackConfig.cmake // 生成二进制安装包
cpack -C CPackSourceConfig.cmake // 生成源码安装包
```