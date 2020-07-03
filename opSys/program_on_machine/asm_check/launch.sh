# 使用 -Og 减少优化，使用 -S 能看到编译器产生的汇编代码
# 运行之后会产生一个.s文件，但是不做其它工作，通常情况下还会继续调用汇编器产生目标代码文件
# gcc -Og -S mstore.c

# 使用 -c GCC将会编译并汇编该代码
# 运行之后会产生一个.o文件，它是二进制格式的，无法直接查看
# gcc -Og -c mstore.c

# 使用GDB查看目标代码的16进制表示
# (gdb) x/14xb multstore

# 用objdump反汇编器查看二进制代码
objdump -d mstore.o
