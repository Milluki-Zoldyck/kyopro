// Introduction to Heuristic Contestの回答
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = (1<<30);

struct Input {
    int D;
    vector<vector<ll>> s; //[D][26]
    vector<ll> c; //[26]
};

struct BeamState {
    vector<int> Out;   // 0..25
    int width;
    int depth;
    ll eval = 0;       // compute_score の値
    int first_action=-1;
    // priority_queue用（evalが大きいほど優先）
    bool operator<(const BeamState& other) const {
        return eval < other.eval;
    }
};

// 選んだ会場によるスコアを計算する
ll compute_score(Input &input, vector<int> &out){
    ll score = 0;
    vector<int> last(26, 0); //最後に開催した日

    for (int d = 0; d < (int)out.size(); d++) {
        last[out[d]] = d + 1; // outの中にあった開催を反映する
        //以下スコア計算
        for (int i = 0; i < 26; i++) {
            score -= (long long)(d + 1 - last[i]) * input.c[i];
        }
        score += input.s[d][out[d]];
    }
    return score;
}

int beam_compute_score(Input& input, BeamState& state) {
    priority_queue<BeamState> now_beam;
    BeamState best_state;
    now_beam.push(state);

    for (int i = 0; i < state.depth; i++) {
        priority_queue<BeamState> next_beam;
        for (int j = 0; j < state.width; j++){
            if (now_beam.empty()) break;
            BeamState now_state = now_beam.top();
            now_beam.pop();
            for(int k = 0; k < 26; k++){
                BeamState next_state = now_state; 
                next_state.Out.push_back(k);
                next_state.eval = compute_score(input,next_state.Out); //その行動の評価値を貪欲法で計算
                if(i == 0) next_state.first_action=k; //もし最初の深さだったらactionを記録する
                next_beam.push(next_state);
            }
        }
        now_beam = next_beam;
        best_state = now_beam.top();
        if(best_state.Out.size()==input.D) break;
    }
    // 最後に一番良いもの（top）を返す
    return best_state.first_action;
}

//入力を引数として問題を解く
vector<int> solve(Input &input){
    BeamState state;
    vector<int>& out=state.Out;
    state.width=5;
    state.depth=2;

    for(int day=0;day<input.D;day++){
        int best_day = beam_compute_score(input, state);
        out.push_back(best_day);
    }
    return out;
}

int main() {
    Input input;
    cin >> input.D;
    input.c.assign(26, 0);
    for (int i = 0; i < 26; i++) cin >> input.c[i];
    input.s.assign(input.D, vector<ll>(26, 0));
    for (int d = 0; d < input.D; d++) {
        for (int i = 0; i < 26; i++) cin >> input.s[d][i];
    }

    int k=26;
    vector<int> out = solve(input);

    for (int d = 0; d < (int)out.size(); d++) {
        cout << (out[d] + 1) << "\n";
    }

    return 0;
}
