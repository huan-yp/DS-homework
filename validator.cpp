/*
使用:

作业名为 <homework>, 工作目录下有 <homework>/<homework>.exe, <homework>/gen.exe

<homework>/<homework>.exe: 标准输入输出读写
<homework>/gen.exe: 输出测试数据到 data.in, 标准答案到 data.ans

每次运行时需要重新编译 <homework>/<homework>.cpp 和 <homework>/gen.cpp 生成对应可执行文件.

运行 validator.exe <homework> 生成测试数据并检查答案.
*/
#include <bits/stdc++.h>

using namespace std;


int main(int argc, char *argv[])
{
    string generator = string(argv[1]) + "\\gen"s;
    string myprog = string(argv[1]) + "\\"s + string(argv[1]);
    string exec = myprog + " < data.in > data.out";
    cout << "checking:" << exec << '\n';
    for(int test=1; test<=100; test++){
        cout << "test " << test << '\n';
        system(generator.c_str());
        system(exec.c_str());
        if(system("fc data.out data.ans")){
            cout << "wrong answer\n";
            return 0;
        }
        cout << "ok\n";
    }
    return 0;
}
