# 查找当前目录下的所有源文件
# 并将名称保存到DIR_SRCS变量，变量名要唯一
aux_source_directory(. DIR_MATH_SRCS)

# 生成链接库
add_library(MathFunctions ${DIR_MATH_SRCS})

# 指定math_functions库的安装路径
install(TARGETS MathFunctions DESTINATION lib)
install(FILES math_functions.h DESTINATION include)
