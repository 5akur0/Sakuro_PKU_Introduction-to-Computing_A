### 题目描述
给定两个不超过 $200$ 位的大整数（$200$ 位包含符号位。正整数和 $0$ 可以带符号，也可以不带符号），计算其差值（前面的值减去后面的值）。

#### 关于输入
第 $1$ 行输入一个整数 $n$，表示接下来有 $n$ 组数据。
每组数据有两行，第一行是被减数，第二行是减数；相邻的两组数据之间用一个空行隔开。

#### 关于输出
对于每组数据，逐行输出它们的差值。
若结果不为 $0$，最高位不能是 $0$。
若结果为非负整数，不能带符号。

#### 例子输入
5
-567123
-545012

121346
-17623

+12341
2346789

-21346
+87623

-0
-9876543210

#### 例子输出
-22111
138969
-2334448
-108969
9876543210

#### 提示信息
结果的最高位不能是 $0$，除非结果为 $0$。