#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void test1()
{
    std::string word;

    // 条件状态：判定流是否有效
    // while (std::cin >> word)
    //     ;
    // std::cout << word << std::endl;

    /////////////////////////
    // 上下两个操作是等价的 //
    /////////////////////////

    while (!std::cin.fail())
    {
        std::cin >> word;
    }
    std::cout << word << std::endl;

    // Ctrl + D：输入EOF
    // 标准输入：1231 123123  321312
    // 输出：321312
}

// 使用文件流
void file_stream()
{
    // 创建输入流，关联输入的文件
    // std::ifstream in("infile.txt");
    // 一种等价的写法
    std::ifstream in;
    in.open("infile.txt");
    // 关闭文件
    // in.close();

    // 检测是否打开成功
    if (!in)
    {
        std::cout << "Cannot Open File." << std::endl;
        return;
    }

    // 创建输出流，未关联输出文件
    std::ofstream out("outfile.txt");
    // 向文件中输出一行字符
    out << "Hello fstream !" << std::endl;

    // 文件读取
    int number;
    std::string content;
    while (in >> number >> content)
    {
        std::cout << number << "\t" << content << std::endl;
    }
}

// 文件模式
void f_mode()
{
    std::ifstream in;
    std::ofstream out;

    // 默认也是in
    in.open("infile.txt", std::ofstream::in);
    // 默认是out，但是可以改成app
    out.open("outfile.txt", std::ofstream::app);
    // 追加内容
    out << "wdnmd" << std::endl;
}

int main(int argc, char const *argv[])
{
    // test1();
    // file_stream();
    f_mode();
}
