题目：求Cell的数量/数量变化
Cell有感染和正常2种状态（如下图，橙色表示被感染的细胞，白色表示正常）
Cell有infect(), recover()两种操作。
Cell每小时只能被感染或被恢复，不会同时即被感染也被恢复
定义了int observe(int top, int left, int size);函数，返回以(left, top)为左上顶点，长为size的正方形内，被感染的Cell的个数。

观察的是一个正方形内的感染的细胞数，如果范围超过，则只计算有效范围内的值

Observe(top, left, 1)返回值可以表示 （left, top）该位置是否被感染 

Init函数
void Init(int cell[][], int N)
传入开始的细胞状态,矩阵方式存储
Cell[left][top] = 1 表示 (left, top) 位置细胞被感染， 0相反
N的值

infect函数
正常细胞->感染细胞

Recover函数
感染细胞->正常细胞


Init()函数只在每个测试例开始调用一次
 1<= N <= 100
左上坐标为（0,0） 右下坐标（N-1, N-1）
Observe里size>=1,如果是0，就返回0
Infect函数只能有细胞被感染，不会有细胞恢复
Recover函数只能有细胞被恢复，不会有细胞被感染
返回结果中，感染/正常细胞的顺序可以任意
细胞变化的数量小于N
Infect/recover调用次数小于100

只给定初始的cell状态，要求infect和recover操作后，给出cell变化的结果

总结下本题的内容

给定一个2维数组cell[][],给user使用;
将cell的信息转换成1维数组data[]，main使用，user不可见;
每次infect和recover引起cell[][]的变化，同时利用updateData更新data[]
利用observe来统计data的信息，间接求cell[][]
通过多次调用observe来求cell[][]数组的变化
要求observe被调用的次数最少

