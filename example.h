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

// 说明当前文件函数功能和使用，个人觉得太麻烦的说明可以省略！只需要简答介绍和提示。或者也可以不写！

// 行的长度最好不要超过 80！

// 头文件包含按照 <PROJECT>_<PATH>_<FILE>_H_ 进行命名，项目 code_style 路径为 code_style/example.h 可写成：
#ifndef CODE_STYLE_EXAMPLE_H_
#define CODE_STYLE_EXAMPLE_H_
**留白**
// 头文件包含顺序：相关头文件（项目中的）、C 库、C++库、其他库.h,比如第三方 opencv、Eigen 等等库
#include <sys/types.h>           // C 库头文件

#include <vector>                // C++ 头文件

#include <Eigen/Core>
#include <opencv2/core/core.hpp> // 其他第三方库

#include "code_style/xxxx.h"     // 利用项目内其他头文件的某个类型或函数，不要使用 .. 类似的相对路径，要使用相对于项目根目录路径


// 通用命名规则：函数、变量、文件、应具有描述性，不要过度缩写，类型和变量名应该是名词，函数名可以用「命令性」动词

// 常量和静态存储期变量命名：名称前面加k，例如 kDaysInAWeek，
// 所有具有静态存储类型的变量 (例如静态变量或全局变量) 都应当以此方式命名。
// 综合来说：就是所有 const /constexpr 变量（局部或全局，类内），
// 以及 静态存储期变量（包括 static 标识的变量或者未命名的命名空间）的都要用 k 开头！！！！
extern int kGlobalVar;           // 需要在头文件中进行外部声明
extern constexpr int kGGG1;
extern const int kGlobalVar2;
extern int kGoogleStatic1 = 4;   // 这里去掉了 static 

// 这里可以放置外部前置类全局函数的声明，然后在 .cc 文件中进行包含，如果本头文件一些函数和成员函数定义中使用
// 了这个类对象，那么也需要在头文件中添加 #include "ABC" #include "DEF"
class ABC;
template <typename T>
class DEF;


// 可以在 .cc文件、 .h文件的函数、方法或类中，可以使用 using 声明即 using std::string
namespace xxxx项目名称 {          // 小写字母，最高级命名空间取决于项目名称，不要使用缩写，但是大家都知道的缩写可以用。
namespace code_style {           // 对应于 项目/code_style 文件夹

// 可以在这里加上 别名
using Uint8Color = std::array<uint8, 3>;


// TODO 对临时的，短期的解决方案，但不完美的代码使用这个注释，或者写一些 "将来某一天要做的事情"即 未完成事。或明确的事项
// DEPRECATED 弃用注释，不是强制弃用，格式如下：

// DEPRECATED(写说明，帮助其他人修复其调用点) ，或者一般做法，可以将一个弃用函数改造成为一个内联函数，这一函数将调用新的接口。
void FuncTodo() {
    // pass
}
// 改造后的内联函数（内联函数放在头文件！）
inline FuncTodo() {
    // pass
    // 调用新的接口
    FuncOne();
}

// 函数调用时，尽可能易读性：比如： my_widget.Transform(x1, x2, x3, y1, y2, y3, y4, z1, z2, z3);可以改为：
// my_widget.Transform(x1, x2, x3,
//                     y1, y2, y3,
//                     z1, z2, z3);

// 属性和展开为属性的宏，写在函数声明或定义的最前面，即返回类型之前
// 宏的名字，注意全大写，然后下划线链接。
#define MUST_USE_RESULT // 起到提示作用，可以想着用


// 函数声明：注释函数功能，标注： 对于比较明显的就不需要说明了。
// 输入输出，
// 函数是否分配了必须由调用者释放的空间。
// 参数是否可以为空指针，或者在函数内部进行空指针检测，提示错误！用 glog CHECK（）宏。
void GoogleTest(); // 尽量使用这种在命名空间中的函数，不要在命名空间外部定义全局函数，而 static 函数要用在类中


// 类型名称的每个单词首字母均大写, 不包含下划线
using VectorInt = std::vector<int>;
typedef std::vector<int> VectorInt;

// 内部变量命名规则与普通变量命名规则一致，小写加下划线链接，但是不需要结尾加下划线，恰好区分 class
struct GoogleSection {
    int data_member;        // 变量：不需要下划线结尾，当做普通变量处理，小写字母加下划线
    int data_2;
    static int kStructTest; // 用 k 开头
    const int kData = 3;
};
// 列表初始化
GoogleSection cc{2,3};

// 函数代码比较少 10 行的函数声明为内联函数，且声明和定义都放在头文件中，否则编译失败。
// 对于包含 for()等循环 switch 的情况，最好不要用内联，除非，for()等循环 switch 用的少，或基本很少执行。
// 当然对于有些虽然声明为内联，但是编译器有时不会看做内联。比如递归函数、虚函数
inline void TestInline(int test_num) {
    int test_num_buf = test_num + 2;
    return; // 建议 void 返回格式
}


// 类注释：在类前面，描述类的功能
// 和用法，比如 Example:...写下简单用法
// 除非它的功能相当明显。一般情况下可以不说明，用分行 // 注释法
// 是否可多线程访问实例，需要说明，以及可重入性！
// TODO: 进行一些还需要做的事情！
class GoogleNorm {  // 对应文件名字 google_norm.h google_norm.cc
public: // 公有类型声明
    typedef int   int32;
    typedef long long int64;
    enum GoogleChoice { GLOG_CHOICE, GFLAGS_CHOICE }; // 枚举值，采用常量的命名方式。
    /*
    enum GoogleChoice { 
        GLOG_CHOICE, 
        GFLAGS_CHOICE
    }; // 枚举值，采用常量的命名方式。
    */

    // 内部变量命名规则与普通变量命名规则一致，小写加下划线链接，但是不需要结尾加下划线，恰好区分 class
    struct GoogleSection {
        int data_member;        // 变量：不需要下划线结尾，当做普通变量处理，小写字母加下划线
        int data_2;
        static int kStructTest; // 用 k 开头
        const int kData = 3;
    };
private: // 私有类型声明
    // 嵌套类前置声明（之后在 .cc 文件中进行定义即可）
    // 如果这个类不对外开放，那么就在在对应的 .cc 文件中进行定义，
    // 否则就在该头文件中进行定义且改为 public 访问权限
    class NestClass;

public: // 外部调用的函数及变量
    // 属于 static const constexpr 的数据成员要放在 public 后面，剩下其他变量全部是 private
    constexpr static const char* kConfigurationFileActionName = // k 开头 // 因为是 static 常量
                                "intensity_to_color";
    static const kMemberStaticConst = 3;

    GoogleNorm() = default;
    // 构造函数一般不注释，切记，读代码的人知道构造/析构函数的功能，需要注明函数对参数做了什么，是否取得指针所有权，析构清理了什么
    GoogleNorm(int i ) {}
    GoogleNorm(const GoogleNorm &other) : section_cout_(other.section_cout_) {
        int * temp = new (nothrow) int[other.ClassStatic]();
        // 拷贝元素
        temp
    }
    ~GoogleNorm() = default;
    //or
    // 析构函数，注意释放内存，以及变量对齐问题，显示整齐
    ~GoogleNorm() {
        if (nullptr != queue_) {
            delete[] queue_;
            queue_    = nullptr;
            capacity_ = 0;
            size_     = 0;
            head_     = 0;
            tail_     = 0;
        }
    }

    // 属性宏或展开为属性的宏，写在函数声明或定义的最前面。 表示提醒调用者
    MUST_USE_RESULT bool IsOk();

    void get_const(){ return ClassStatic_; }            // 单函数内部要留白左右一个空格

    void get_section() const { return  section_cout_; } // 取值函数和设值函数要全小写加下划线。最好与实际成员变量对应

    // 声明：注释函数功能：对于明显的可以不用说明。比如上面取值和设值函数就不用加注释
    // 输入输出，
    // 函数是否分配了必须由调用者释放的空间。
    // 参数是否可以为空指针，或者在函数内部进行空指针检测，提示错误！用 glog CHECK（）宏。
    void MemberFunc(); // 普通函数 单词首字母大写！

protected:

private: // 类成员变量要加下划线，一律小写字母加下划线，结尾加下划线
    static int kClassStatic = 3;
    const int kDaysInWeek_ = 8;
    // 空格前置 风格一致
    char *c; // char &c;

    // 数据成员注释，一般不用，但是对于变量可以接受 NULL or -1 这种值时，需要注释代表的含义
    int section_cout_; // 类的成员 变量（静态、非静态），下划线结尾
    int *p_; // 一段内存
};

}   // namespace code_style
}   // namespace xxxx项目名称
**留白一行**
#endif  // CODE_STYLE_EXAMPLE_H_