#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// C++不支持对象的序列化，对象不能整体从文件中读取/写入
// 可以定义成只含数据的结构体
// write: 写入二进制数据

struct Date
{
    int month, day, year;
};

void file_stream_test1()
{
    Date dt = {7, 22, 2020};
    // 设定为二进制模式
    ofstream fout("data.dat", ios_base::binary);
    // 指针类型转换
    fout.write(reinterpret_cast<char *>(&dt), sizeof(dt));
    fout.close();
}

void file_stream_test2()
{
    Date dt;
    ifstream fin("data.dat");
    fin.read(reinterpret_cast<char *>(&dt), sizeof(dt));
    cout << dt.year << endl;
}

// 把任何类型转换成字符串流
// 前提是该类重载过<<操作符
template <class T>
inline string toString(const T &V)
{
    ostringstream sout;
    sout << V;
    return sout.str();
}

template <class T>
inline T fromString(string s)
{
    T V;
    istringstream sin(s);
    sin >> V;
    return V;
}

int main(int argc, char const *argv[])
{
    file_stream_test1();
    file_stream_test2();
    float fn = fromString<float>("1.23");
    cout << fn + 0.01 << endl;
    return 0;
}
