#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
mt19937 mt_for_action(1);
uniform_real_distribution<double> dist01(0.0, 1.0);

// 入力を整理
struct Input {
    
};

// 時間を管理するクラス
class TimeKeeper
{
private:
    chrono::high_resolution_clock::time_point start_time_;
    ll time_threshold_;

public:
    // 時間制限をミリ秒単位で指定してインスタンスをつくる。
    TimeKeeper(const ll &time_threshold)
        : start_time_(chrono::high_resolution_clock::now()),
          time_threshold_(time_threshold)
    {
    }

    // インスタンス生成した時から指定した時間制限を超過したか判定する。
    bool isTimeOver() const
    {
        auto diff = chrono::high_resolution_clock::now() - this->start_time_;
        return chrono::duration_cast<chrono::milliseconds>(diff).count() >= time_threshold_;
    }
    // 経過時間をミリ秒で記録する
    ll elapsedMS() const
    {
        auto diff = chrono::high_resolution_clock::now() - start_time_;
        return chrono::duration_cast<chrono::milliseconds>(diff).count();
    }
};

//入力を引数として問題を解く
void solve(Input &input){
    
}

int main() {
    Input input;
}
