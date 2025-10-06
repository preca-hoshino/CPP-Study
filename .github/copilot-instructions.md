## 📚 项目概述

洛谷算法题目练习。`.cpp` 文件按题号命名（如 `P5709.cpp`）。

**文件命名规则**:
- 手动编写：`P5709.cpp`
- AI 辅助编写：`P5709[AI].cpp`

### 📁 目录结构

```
CPP-Study/
├── 2025-10-1/          # 2025年10月第1周
├── 2025-10-2/          # 2025年10月第2周 
├── .vscode/            # launch.json, tasks.json
├── .github/            # copilot-instructions.md
└── .gitignore
```

**目录命名**: `年份-月份-周数` (如 `2025-10-1`)

---

## 🎯 做题流程

1. **分析题目**：明确输入输出、核心算法、边界条件
2. **设计思路**：选择数据结构、确定算法流程
3. **编写代码**：按题号命名，套用模板，添加注释
   - 手动编写：`P5709.cpp`
   - AI 辅助编写：`P5709[AI].cpp`（需添加 AGENT MODE 标注）
4. **测试验证**：编译 → 样例测试 → 边界测试
5. **更新文档**：在题目分类中添加题号（去掉[AI]标识），更新题数
6. **提交代码**：
   - 手动编写：`git add <题号>.cpp && git commit -m "[Add] <题号>"`
   - AI 辅助编写：`git add <题号>[AI].cpp && git commit -m "[Add] <题号>[AI]"`

---

## 📝 代码规范

**标准模板**:
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    // 逻辑实现
    cout << result;
    return 0;
}
```

**AI 辅助标注** (使用 GitHub Copilot 编写时):
```cpp
// AGENT CODE
// P5709 - 【深基2.例12】申请奖学金
// GitHub Copilot - 2025-10-06 10:30:00
#include<bits/stdc++.h>
using namespace std;
// ... 代码实现
```
- 第1行：固定字符串 `// AGENT CODE`
- 第2行：格式 `// 题目编号 - 题目名称`
- 第3行：格式 `// 模型名称 - 文件创建时间（YYYY-MM-DD HH:MM:SS）`

**编码约定**: `#include<bits/stdc++.h>` | `using namespace std;` | 变量初始化为0 | `const`修饰常量 | `constexpr`定义编译期常量 | Allman风格（花括号独占一行）

---

## 💡 解题模式

1. **条件分支**: `if-else` | `if-else if` | `condition ? a : b` | 边界特判提前`return`
2. **字符串**: `ch-'0'`(字符→数字) | `'0'+digit`(数字→字符) | `+=`拼接 | 加权求和
3. **数组排序**: `sort(arr,arr+n)` | `max/min` | `INT_MAX/MIN` | `gcd/lcm`
4. **循环累加**: 条件统计 | 分段计算 | 循环减半 | 级数求和 | 分段累加
5. **格式输出**: `fixed+setprecision(n)` | `setfill('0')+setw(2)` | `(double)a/b`
6. **高精度**: `vector<int>`存储(低位在前) | 逐位相乘/相加 | 处理进位 | 逆序输出
7. **数字处理**: `num%10`提取个位 | `num/=10`去掉个位 | 函数封装

**常用技巧**:
- 上取整：`(a+b-1)/b`
- 周期循环：`((x-1+i)%7)+1`
- 最大公约数/最小公倍数：`gcd/lcm` 递归实现

---

## 🧪 测试与调试规范

**用例数量**: 3-5个 (1样例+2边界最少) | **边界占比**: ≥50% | **边界选择**: n=min(0/1)/max/特殊值  
**测试流程**: 编译→样例→边界min→边界max→特殊值(可选)

### 🐧 Linux 环境

**编译方式**:
```bash
# VS Code任务方式（推荐）
Ctrl+Shift+B                                       # 调用任务: [Linux] g++ build active file

# 命令行方式
clear;echo 'BUILD MODE';g++ -g <文件名>.cpp -o <文件名>                      # 手动编译
clear;echo 'BUILD MODE';g++ -g "P5709[AI].cpp" -o "P5709[AI]"               # 带[AI]的文件需要引号
```

**测试命令** (Bash/Zsh):
```bash
clear;echo 'TEST MODE #<次数> [<简短说明>]';echo 100 | ./P5722                                 # 单行输入
clear;echo 'TEST MODE #<次数> [<简短说明>]';echo -e "3 5\n7" | ./P5722                        # 多行输入
clear;echo 'TEST MODE #<次数> [<简短说明>]';printf "3 5\n7\n" | ./P5722                       # 多行输入(替代)
```

**调试方式**:
- F5 启动调试 (使用 gdb)
- 配置: `[Linux] 启动` (launch.json 中)
- 调试器: `/usr/bin/gdb`

---

### 🪟 Windows 环境

**编译方式**:
```powershell
# VS Code任务方式（推荐）
Ctrl+Shift+B                                       # 调用任务: [Windows] cl.exe 生成活动文件

# 命令行方式
clear;echo 'BUILD MODE';cl.exe /Zi /EHsc /nologo /Fe<文件名>.exe <文件名>.cpp   # 手动编译
clear;echo 'BUILD MODE';cl.exe /Zi /EHsc /nologo /Fe"P5709[AI].exe" "P5709[AI].cpp"  # 带[AI]的文件需要引号
```

**测试命令** (PowerShell):
```powershell
clear;echo 'TEST MODE #<次数> [<简短说明>]';echo 100 | .\P5722.exe                            # 单行输入
@"
3 5
7
"@ | .\P5722.exe                                  # 多行输入
```

**调试方式**:
- F5 启动调试 (使用 cppvsdbg)
- 配置: `[Windows] 启动` (launch.json 中，需取消注释)
- 调试器: Visual Studio Debugger

---

## 📖 题目分类 

**基础计算**: B2001
**条件判断**: 
**数组排序**: 
**循环累加**:  
**格式输出**: 
**图形输出**:
**高精度**: 
**字符串**:
**数字处理**: 
**综合**: 

---

## 📦 Git工作流

**常用命令**:
```bash
git status                    # 状态
git add .                     # 添加
git commit -m "[Add] P1234"  # 提交
git log --oneline             # 历史
git diff <文件>            # 差异
git restore <文件>        # 撤销
```

**提交规范**: [Add]新题 | [Fix]修复 | [Doc]文档 | [Ref]重构 | [Del]删除

**注意事项**: `.gitignore`已排除构建产物
