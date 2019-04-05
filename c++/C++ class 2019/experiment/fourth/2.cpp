#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Goods {
private:
    static int goodsNum;
    const string goodsName;

public:
    Goods(string name, int num) : goodsName(name){
        goodsNum = num;
    }

    void addGoods(int num) {
        goodsNum += num;
    }

    void removeGoods(int num) {
        if (goodsNum - num < 0) {
            cout << "没有这么多库存！" << endl;
            return;
        }
        goodsNum -= num;
    }

    void info() {
        cout << "货物名：" << goodsName << " " << "货物库存：" << goodsNum << " " << endl;
    }

    int getGoodsNum() {
        return goodsNum;
    }
};

int main() {
    string nameIn;
    int numIn, flag = 0;
    vector<Goods> goods;

    do {
        cout << "请输入货物名字与初始库存" << endl;
        cin >> nameIn >> numIn;
        goods.push_back(Goods(nameIn, numIn));

        cout << "请问是否继续输入？ 1.继续 0.停止" << endl;
    }while(cin >> flag && flag != 0);

    for(auto &good : goods) {
        good.info();
    }

    return 0;
}
