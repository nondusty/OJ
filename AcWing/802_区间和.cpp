#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
typedef pair<int, int> PII;
 
const int N = 300010;
 
int n, m;
int a[N], s[N];
 
vector<int> alls;//用来保存真实的下标和想象的下标的映射关系
vector<PII> add, query; //原来保存操作输入的值
 
int find(int x) {  //二分查找
    int  l = 0, r = alls.size() - 1;
    while (l<r) {
        int mid = l + r >> 1;
        if (alls[mid] >=x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1; //  因为要求前缀和，故下标从1开始方便，不用额外的再处理边界。
}
int main () {
    cin >> n >> m;
    for (int i = 0; i < n;++ i) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
 
        alls.push_back(x);//先把下标放入向量中 统一离散化 
    }
    for (int i = 0; i < m;++ i) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
 
        alls.push_back(l);
        alls.push_back(r);
//将其左右端点也映射进来，目的是可以让我们在虚拟的映射表里找到，
//这对于我们后面的前缀和操作时是十分的方便的。如果当我们在虚拟的
//映射表里找的时候，如果没有找到左右端点，那么前缀和无法求
    }
    sort(alls.begin(), alls.end());  //排序
    alls.erase(unique(alls.begin(), alls.end()), alls.end());//去除重复元素
   // 1）erase( pos, n); 删除从pos开始的n个字符，例如erase( 0, 1)，
   // 删除0位置的一个字符，即删除第一个字符
    //（2）erase( position); 
    //删除position处的一个字符（position是个string类型的迭代器）
    //（3）erase（first，last）;删除从first到last之间的字符，
   // （first和last都是迭代器）last 不能是x.end()
    //unique 使用 必须要先过一遍sort排序。再者，unique函数返的返回值是
    //一个迭代器，它指向的是去重后容器中不重复序列的最后一个元素的
    //下一个元素。所以如果 想要得到不重复元素的个数就需要用返回值-开始地址。
    for ( auto item : add) { //先对添加里的元素映射 赋值 
        int x = find(item.first);//找到x的映射值 往原数组中加c 
        a[x] += item.second; // 处理插入
    }
    //for(auto a:b)中b为一个容器，效果是利用a遍历并获得b容器中的每一个值，
    //但是a无法影响到b容器中的元素。
    for (int i = 1; i <= alls.size(); ++i)
    {
        s[i] = s[i - 1] + a[i];//前缀和
    }
    for (auto item : query) {
            int l = find(item.first), r = find(item.second);
            cout << s[r] - s[l - 1] << endl;
    }//每个元素都对应一组{first, first}键值对（pair），
    //键值对中的第一个成员称为first，第二个成员称为second.
    return 0;
}

/**
 * 题目描述：
假定有一个无限长的数轴，数轴上每个坐标上的数都是0。
现在，我们首先进行 n 次操作，每次操作将某一位置x上的数加c。
近下来，进行 m 次询问，每个询问包含两个整数l和r，你需要求出在区间[l, r]之间的所有数的和。

输入格式
第一行包含两个整数n和m。
接下来 n 行，每行包含两个整数x和c。
再接下里 m 行，每行包含两个整数l和r。

输出格式
共m行，每行输出一个询问中所求的区间内数字和。

数据范围
−10^9≤x≤10^9,
1≤n,m≤10^5,
−10^9≤l≤r≤10^9,
−10000≤c≤10000

输入样例：
3 3
1 2
3 6
7 5
1 3
4 6
7 8

输出样例：
8
0
5
*/