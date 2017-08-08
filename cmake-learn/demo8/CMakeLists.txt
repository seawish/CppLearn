# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
project(Demo8)
set(DEMO_VERSION_MAJOR 1) # 主版本号
set(DEMO_VERSION_MINOR 0) # 副版本号

set (CMAKE_INCLUDE_CURRENT_DIR ON)

#################################### demo6添加-start ####################################
# 检查系统是否支持 pow 函数
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (pow HAVE_POW)
#################################### demo6添加-end ####################################

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

# 是否加入 MathFunctions 库
if (NOT HAVE_POW)  ######## demo6修改 ###########
    include_directories("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math) # 添加 math 子目录
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (NOT HAVE_POW)

# 查找当前目录下的所有源文件
# 并将名称保存到DIR_SRCS变量，变量名要唯一
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(demo ${EXTRA_LIBS})

#################################### demo5添加-start ####################################
# 指定安装路径
install(TARGETS demo DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h"
        DESTINATION include)

# 启用测试
enable_testing()

# 测试帮助信息是否可以正常提示
add_test(test_usage demo)
set_tests_properties(test_usage
        PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

# 定义一个宏，用来简化测试工作
macro (do_test arg1 arg2 result)
    add_test (test_${arg1}_${arg2} demo ${arg1} ${arg2})
    set_tests_properties (test_${arg1}_${arg2}
            PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

# 利用 do_test 宏，测试一系列数据
do_test (5 2 "is 25")
do_test (10 5 "is 100000")
do_test (2 10 "is 1024")
#################################### demo5添加-end ####################################

#################################### demo6添加-start ####################################
# 构建一个 CPack 安装包
# 导入 InstallRequiredSystemLibraries 模块，以便之后导入 CPack 模块；
# 设置一些 CPack 相关变量，包括版权信息和版本信息，其中版本信息用了上一节定义的版本号；
# 导入 CPack 模块。
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
        "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${DEMO_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${DEMO_VERSION_MINOR}")
include (CPack)

#################################### demo6添加-end ####################################