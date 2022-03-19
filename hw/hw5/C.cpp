//我慢は要らない、壊し尽くす
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 100000 + 100;
const db pi = acos(-1.0);
#define lowbit(x) ((x) & (-x))
#define sqr(x) (x) * (x)
#define rep(i,a,b) for (int i = a; i <= b;i++)
#define per(i,a,b) for (int i = a; i >= b;i--)
#define go(u,i) for (register int i = head[u], v = sq[i].to; i; i = sq[i].nxt, v=sq[i].to)
#define fir first
#define sec second
#define mkp make_pair
#define pb push_back
#define maxd 998244353
#define eps 1e-8

string warriorName[] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string weaponName[] = {"sword" , "bomb" , "arrow"};
int warriorLife[5];
//blue: lion、dragon、ninja、iceman、wolf
// 1 4 3 0 2

class headQuarter;

class warrior{
    protected:
        headQuarter *myHeadQuarter;
        int num; 
        int life;  
        double morale;
        int nameId;
    public: 
    	friend class headQuarter;
        warrior(headQuarter* h, int nowId, int name);
};

class headQuarter{
    private:
        int totalLife;
        int totWarrior;
        string color;
        int nowWarriorId;
        warrior* nowWarrior[N];
        bool canProduce;
        int warriorNum[5];
        int order[5];
    public:
    	friend class warrior;
    	friend class dragon;
    	friend class lion;
        headQuarter(string col, int m);
        void produceWarrior(int nowTime);
        bool canProduceWarrior();
};


warrior::warrior(headQuarter* h, int nowId, int name) {
    myHeadQuarter = h;
    num = nowId;
    nameId = name;
    h->warriorNum[nameId]++;
    cout << h->color << " " << warriorName[nameId] << " " << nowId << " born with strength " << warriorLife[nameId];
    cout << "," << h->warriorNum[nameId] << " " << warriorName[nameId] << " in " << h->color << " headquarter" << endl;
}

class iceman: public warrior{
    private:
        int weaponId;
    public:
        iceman(headQuarter *h, int nowId, int name): warrior(h, nowId, name) {
            weaponId = nowId % 3;
            cout << "It has a " << weaponName[weaponId] << endl;
        }
};

class dragon: public warrior{
    private: 
        int weaponId;
        double morale;
    public:
        dragon(headQuarter *h, int nowId, int name): warrior(h, nowId, name) {
            weaponId = nowId % 3;
            morale = 1.0 * h->totalLife / warriorLife[name];
            cout << "It has a " << weaponName[weaponId] << ",and it's morale is " << fixed << setprecision(2) << morale << endl;
        }
}; 

class ninja: public warrior{
    private:
        int weaponId1, weaponId2;
    public:
        ninja(headQuarter *h, int nowId, int name): warrior(h, nowId, name) {
            weaponId1 = nowId % 3;
            weaponId2 = (nowId + 1) % 3;
            cout << "It has a " << weaponName[weaponId1] << " and a " << weaponName[weaponId2] << endl;
        }
};

class lion: public warrior{
    private: 
        int loyal;
    public: 
        lion(headQuarter *h, int nowId, int name): warrior(h, nowId, name) {
            loyal = h->totalLife;
            cout << "It's loyalty is " << loyal << endl;
        }
};

class wolf: public warrior{
    public:
        wolf(headQuarter *h, int nowId, int name): warrior(h, nowId, name) {}
};

bool headQuarter::canProduceWarrior() {
    return this->canProduce;
}

//dragon 、ninja、iceman、lion、wolf
//read: iceman、lion、wolf、ninja、dragon
//2 3 4 1 0
//blue: lion、dragon、ninja、iceman、wolf
//3 0 1 2 4 

headQuarter::headQuarter(string col, int m) {
    color = col;
    totalLife = m;
    totWarrior = 0;
    nowWarriorId = -1;
    canProduce = 1;
    rep(i, 0, 4) {
        warriorNum[i] = 0;
    }
    if (col == "red") {
        order[0] = 2; order[1] = 3; order[2] = 4; order[3] = 1; order[4] = 0;
    } else {
        order[0] = 3; order[1] = 0; order[2] = 1; order[3] = 2; order[4] = 4;
    }
    //rep(i, 0, 4) cout << warriorName[order[i]] << " ";cout << endl;
    //rep(i, 0, 4) cout << warriorLife[order[i]] << " ";cout << endl;
}


void headQuarter::produceWarrior(int nowTime) {
    cout << setfill('0') << setw(3) << nowTime << " ";
    rep(i, 0, 4) {
        nowWarriorId++;
        if (nowWarriorId > 4) nowWarriorId -= 5;
        if (totalLife >= warriorLife[order[nowWarriorId]]) {
            totWarrior++;
            totalLife -= warriorLife[order[nowWarriorId]];
            //cout << endl << order[nowWarriorId] << " " << warriorLife[order[nowWarriorId]] << " " << totalLife << endl;
            if (order[nowWarriorId] == 0) nowWarrior[totWarrior] = new dragon(this, totWarrior, 0);
            else if (order[nowWarriorId] == 1) nowWarrior[totWarrior] = new ninja(this, totWarrior, 1);
            else if (order[nowWarriorId] == 2) nowWarrior[totWarrior] = new iceman(this, totWarrior, 2);
            else if (order[nowWarriorId] == 3) nowWarrior[totWarrior] = new lion(this, totWarrior, 3);
            else if (order[nowWarriorId] == 4) nowWarrior[totWarrior] = new wolf(this, totWarrior, 4);
            return;
        }
    }
    if (canProduce) {
        cout << this->color << " headquarter stops making warriors" << endl;
        canProduce = 0;
    }
}

int main() {
    //freopen("a.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    rep(cas, 1, T) {
        int tim = 0, m;
        cin >> m;
        rep(i, 0, 4) cin >> warriorLife[i];
        cout << "Case:" << cas << endl;
        headQuarter red = headQuarter("red", m), blue = headQuarter("blue", m);
        while ((red.canProduceWarrior()) || (blue.canProduceWarrior())) {
            if (red.canProduceWarrior()) red.produceWarrior(tim);
            if (blue.canProduceWarrior()) blue.produceWarrior(tim);
            tim++;
        }
    }
    return 0;
}
/*

2
20
3 4 5 6 7
20
3 4 5 6 7

Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
004 blue headquarter stops making warriors
*/



            
