# Data Structures and Algorithms ?

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Standard](https://img.shields.io/badge/Standard-C%2B%2B11%20%2F%2014-orange)
![Status](https://img.shields.io/badge/Status-Learning-green)

## ? 项目介绍 (Introduction)

欢迎来到我的数据结构与算法代码库！

本项目主要用于记录我在学习数据结构课程时编写的 C++ 代码。涵盖了从基础的链表、树到复杂的图论算法的实现。通过手写这些底层数据结构，旨在深入理解其内部原理与内存管理机制。

## ? 目录结构 (Directory Structure)

代码按数据结构类型进行了整理：

### 1. ? 线性表 (Linked Lists)
* `Linklist.cpp`: 单链表的基础操作（增删改查）。
* `merge_linklist.cpp`: 合并两个有序链表。
* `polynomial.cpp`: 一元多项式的加减乘除运算（基于链表实现）。
* `Intersection.cpp`: 集合的交集运算。

### 2. ? 树与二叉树 (Trees)
* `Tree.cpp`: 二叉树的建立与遍历（前序、中序、后序）。
* `Huffman.cpp` / `Huffman_tree_and_code.cpp`: 哈夫曼树的构建与哈夫曼编码实现（数据压缩基础）。

### 3. ?? 图论 (Graphs)
* `graph.cpp`: 图的存储结构（邻接矩阵/邻接表）。
* `graph_dfs.cpp`: 图的深度优先搜索 (DFS) 算法。
* `graph_topological_structure.cpp`: 拓扑排序 (Topological Sort) 实现。

### 4. ? 基础算法与数学
* `sun_factorial.cpp`: 阶乘计算（递归与非递归）。
* `main.cpp`: 用于测试各个模块的主程序入口。

## ?? 开发环境 (Environment)

* **Language**: C++
* **Compiler**: g++ / MinGW
* **IDE**: Visual Studio Code (已配置 `.vscode` 环境)

## ? 如何运行 (How to Run)

本项目包含标准的 VS Code 配置文件。

1. **使用 VS Code 运行**:
   打开任意 `.cpp` 文件，按下 `F5` 或点击右上角的运行按钮即可调试。

2. **使用命令行编译**:
   ```bash
   # 示例：编译并运行哈夫曼树程序
   g++ Huffman.cpp -o huffman
   ./huffman