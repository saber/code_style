/*
 * CopyRight (c) 2021 saber
 * File: example.cc
 * Project: code_style
 * Author: gcj
 * Date: 2021/6/19
 * Description: google code style
 * License: see the LICENSE.txt file
 * github: https://github.com/saber/code_style
 */

// 在这里说明当前文件某些函数的实现细节（不过一般不需要在 .cc 中说明，可以写一个文档作为代替）
// ...................................头文件放置示例...................................................
#include "code_style/example.h"     // 当前 .cc 文件对应的头文件
/**留白**/
#include <cmath>                    // c 库
/**留白**/
//#include <vector>                 // c++ 库
/**留白**/
//#include <Eigen/Core>             // 在头文件中包含了，则在 .cc 里就不用包含
#include "glog/logging.h"           // 其他库头文件
/**留白**/
#include "code_style/xxx.h"         // 本项目中的头文件
#include "ABC"                      // 本类访问的外部的类，在头文件中进行了前置声明，在对应 .cc 文件中要用
                                    // 这里 .cc 文件进行 include 包含，因为本类定义时需要使用


// 宏的名字，注意全大写，然后下划线链接。
#ifdef DISASTER_CXX11
#include <initializer_list>
#endif

// 对于使用 gflags 需要在命名空间外部定义变量
DEFINE_FLAG(bool, someflag, false, "dummy flag");
// 预处理指令不要缩进，从行首开始！
#if DISASTER_PENDING
    // .....
#endif

    // 宏命名（尽量少使用宏，尽可能用常量代替 const constexpr）
#define My_MACRO_SMALL_CHILDREN // 采用全大写，且下划线链接！

// 常量和静态存储期变量命名：名称前面加k，例如 kDaysInAWeek，
// 所有具有静态存储类型的变量 (例如静态变量或全局变量) 都应当以此方式命名。
// 综合来说：就是所有 const /constexpr 变量（局部或全局，类内），
// 以及 静态存储期变量（包括 static 标识的变量或者未命名的命名空间）的都要用 k 开头！！！！

int kGlobalVar1;                // 需要在头文件中进行外部声明
constexpr int kGGG1;
const int kGlobalVar2;
static int kGoogleStatic1 = 4; 

namespace {
    constexpr int kGGG2;
    const int kGlobalVar3;
    static int kGoogleStatic2 = 4; 
    int kGGGGS; // 特别注意这个也要 K 开头
}

// 除文件包含、 全局标识的声明/定义以及类的前置声明外，其他放在命名空间中
// 可以在 .cc文件、 .h文件的函数、方法或类中，可以使用 using 声明即 using std::string，
// 不使用 using 指示: using namespace std; 这种
using std::endl;
using std::cout;


// ..................本文件静态函数变量的定义（建议放到未命名空间中，不要使用 static 标示）.....................
// 在这里的未命名的命名空间里使用该源文件的 static 函数定义，或者静态全局变量的定义
// 这里的名字与未命名空间的名字的作用域是一致的，未命名命名空间不建议放在头文件中（引发唯一定义原则）
// 这里的东西是不被外部访问的，仅仅对该文件内函数有效！
// 鼓励在 .cc 文件内使用匿名命名空间或 static 声明（ static 标识只在声明处，定义就不要了）。
// 除文件包含、 全局标识的声明/定义以及类的前置声明外，其他放在命名空间中
namespace {
    // 可以放置一些本文件使用的全局变量和全局函数，关于类的全局对象最好不要定义，除非用单例模式
    
    // 静态存储期的常量用 k 开头，其他静态存储期变量直接用函数命名规则单词首字母大写，且最好不要定义一个全局类变量！！！会出现动态初始化的 bug
    // 全局变量要注释说明含义和用途。以及作为全局变量的原因。

    const int kGlobalConst = 8; // 这个名字要改成具有某些含义的名字，而不是现在这样说变量的属性
    constexpr int kGlobalExpr = 9;
    int kGlobalVar;             // 全局变量!!!!!
} // namespace

namespace xxx项目名字 {
namespace code_style {

// ....................................进行嵌套类的定义.................................................
// 不能被外部访问的 GoogleNorm 的内嵌类的定义
class GoogleNorm::NestClass {
public:
    NestClass() {

    }
private:
    int a_;    
}; // class GoogleNorm::NestClass
// ...................................进行嵌套类的成员函数外部定义............................................
GoogleNorm::NestClass::NestClass() {

}

// ....................................外部类成员函数的外部定义..................................
// 构造函数说明..................................................................
// 如果所有变量能放在同一行:
GoogleNorm::GoogleNorm(int var) : some_var_(var) {
  DoSomething();
}

// 如果不能放在同一行,
// 必须置于冒号后, 并缩进 4 个空格
GoogleNorm::GoogleNorm(int var)
    : some_var_(var), some_other_var_(var + 1) {
  DoSomething();
}

// 如果初始化列表需要置于多行, 将每一个成员放在单独的一行
// 并逐行对齐
GoogleNorm::GoogleNorm(int var)
    : some_var_(var),             // 4 space indent
      some_other_var_(var + 1) {  // lined up
  DoSomething();
}

// 右大括号 } 可以和左大括号 { 放在同一行
// 如果这样做合适的话
GoogleNorm::GoogleNorm(int var)
    : some_var_(var) {}


void GoogleNorm::MemberFunc2() {

}


/***留白一行****/
// 两个函数定义之间留白一个空行
void GoogleNorm::MemberFunc(const 值或引用(输入参数)，非 const 指针或引用) {
    // 变量初始化建议 括号，普通非数组的变量用 = 号
    // 将函数变量尽可能置于最小作用域内, 并在变量声明时进行初始化.
    vector<int> v(100, 1);
    int pi(3.14); // 优先使用 int pi = 3.14;
    vector<string> x; // 注意留白处理
    y = static_cast<char *>(x);
    vector<char *> x; // 留白处理
    const int kGsdDuu; // 常量也要在前面加上 k

// 预处理指令不要缩进，从行首开始！
#if PRO_DISASTER_PENDING
    // .....
#endif

    while (1) { // 注意空格处理

    }
    // 函数调用规则：
    if (...) {
        DoSomethingThatRequiresALongFunctionName(
            very_long_argument1, // 4 space indent
            argument2,
            argument3,
            argument4);
    }
    bool retval = DoSomething(argument1,
                            argument2,
                            argument3,
                            argument4);
    // 空循环体
    while (1) continue;
    // 函数返回值：如果单参数不需要括号 return aa;逻辑判断的可以用括号改善阅读环境
    return (some_long_condition &&
            another_condition);
}

// 定义处，注释描述函数实现。声明处描述函数功能。
// 重点放在函数的实现大致步骤。比如前半部分加锁，后半部分不需要。

// 弥补方法：
// 如果函数参数意义不明显，比如用到了字面值常量，如 23 等等，可以用一个 constexpr 常量来代替
// 对于 bool 类型参数，可以用 enum 来代替，然后 enum ChoiceArg { kHave , kNoHave }; 这样用 enum 更清晰
// 一个函数不要超过 40 行
void GoogleTest(输入参数, 输出参数) {  // 函数名字每个单词大写，剩下小写。
    // 开头不要加空行
    // 普通变量，小写加下划线
    int price_count_reader;
    const int kLocalConst = 3;
    static int kLocalStatic = 4;
    // 保持符号和变量紧凑
    char *u;
    char &b;

    // 对于代码中巧妙的、晦涩的、有趣的、重要的地方加上注释
    // example: 这是一个 for 循环。用了 ... 技巧。。。
    for (int i = 0; i < 2; ++i) {
        // 比较晦涩的地方，要在行尾加入注释。空两个空格
        printf("i = %d\n", i);  //example: this is a printf,no except

        // 把 && 逻辑处理符号放在后面 ，适当加入括号，方便阅读 if ((this_one_thing > this_other_thing) && ....)
        if (this_one_thing > this_other_thing &&
            a_third_thing == a_fourth_thing &&
            yet_another && last_one) {

            }
    }
    // 注意使用基于范围的 for 循环
    double data[7];
    for (double& d:data) fin>>d;

    // 空循环体处理
    for (int i = 0; i < kGlobalConst; ++i) {}

    // 注意空格的处理
    if (a == 5) {
        ;
    } else if (a == 4) {
        ;
    }

    // 简短的 if 可以写在一行(有 else 不可以)
    if (b == 3) return ;
    // 注意空格处理
    switch (var) {
        case 0: {
            break;
        }
        case 1: {
            break;
        }
        default: {
            // 若 default 用不执行，可以使用这条语句
            assert(false);
        }
    }
    // 函数结尾不要加空行
}
// 如果某个函数有多个配置选项，可以像刚刚说的那样，定义一个类或结构体保存配置选项。然后用该类作为形式参数，这样可以后期随意添加选项
// 比如: const DecimalNumber product = CalculateProduct(values, 7, false, nullptr); CalculateProduct() 有 4 个配置选项参数，可以定义个类或者结构体，然后进行配置
// 然后传入这个类的实例
// 修改后： class ProductOptions {...};
//          ProductOptions options; options.set_precision_decimals(7); options.set_use_cache(ProductOptions::kDontUseCache);
//          CalculateProduct(values, options, nullptr);

} // namespace code_style
} // namespace xxx项目名字
