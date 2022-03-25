//花は見上げの地にて咲く
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
#define mkp make_pair
#define pb push_back
#define maxd 998244353
#define eps 1e-8

void outTime(int nowHour, int nowMinute) {
    cout << setfill('0') << setw(3) << nowHour << ":";
    cout << setfill('0') << setw(2) << nowMinute << " ";
}

string warriorName[] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string weaponName[] = {"sword" , "bomb" , "arrow"};
string colorName[] = {"red", "blue"};
int warriorLife[5], warriorAtk[5];
int n, m, k, t;

class headQuarter;

class warrior{
    protected:
        headQuarter *myHeadQuarter;
        int warriorId;
        int warriorKind;
        int warriorColor;
        int weaponNum[4];
        int weaponLength;
        int nowAtk;
        int nowLife;
        int weaponPtr;
        int arrow1;
    public:
        friend class headQuarter;
        friend class wolf;
        warrior(headQuarter *h, int Id, int Kind);
        int getId() {
            return warriorId;
        }

        int getKind() {
            return warriorKind;
        }

        int getColor() {
            return warriorColor;
        }

        int getLife() {
            return nowLife;
        }
        
        int getAtk() {
            return nowAtk;
        }
        void reportMove() {
            cout << nowLife << " elements and force " << nowAtk;
        }

        void reportName(char endChar) {
            cout << colorName[warriorColor] << " " << warriorName[warriorKind] << " " << warriorId << endChar;
        }
        bool canDamage();
        void fight(warrior* oppo);  
        void getDamage(int nowDamage);
        bool isDead(); 
        void setWeaponReady();
        void getRewardWeapon(warrior *p);
        void reportState(int nowHour);
};

class headQuarter{
    private:
        int totalLife;
        int totWarrior;
        int colorId;
        int nowProduceWarrior;
        warrior* nowWarrior;
        bool canProduce;
        int order[5];
        int position;
    public:
    	friend class warrior;
    	friend class lion;
        headQuarter(int col, int m);
        void produceWarrior(int nowTime);
        bool canProduceWarrior();  
        void reportTotalLife(int nowHour);
         
};

warrior::warrior(headQuarter* h, int Id, int Kind): myHeadQuarter(h), warriorId(Id), warriorKind(Kind) {
    nowLife = warriorLife[Kind];
    nowAtk = warriorAtk[Kind];
    warriorColor = h->colorId;
    weaponLength = 0;
    arrow1 = 0;
    rep(i, 0, 3) weaponNum[i] = 0;
    arrow1 = 0;
    reportName(' ');
    cout << "born" << endl;
}

headQuarter::headQuarter (int col, int m) {
    colorId = col;
    totalLife = m;
    totWarrior = 0;
    nowProduceWarrior = -1;
    canProduce = 1;
    if (col == 0) {
        order[0] = 2; order[1] = 3; order[2] = 4; order[3] = 1; order[4] = 0;
        position = 0; 
    } else {
        order[0] = 3; order[1] = 0; order[2] = 1; order[3] = 2; order[4] = 4;
        position = n + 1;
    }
}

void headQuarter::reportTotalLife(int nowHour) {
    outTime(nowHour, 50);
    cout << totalLife << " elements in " << colorName[colorId] << " headquarter" << endl;
}

bool warrior::canDamage() {
    if (weaponNum[0]) {
        if (nowAtk * 2 / 10 > 0) return 1;
    }
    if ((weaponNum[1]) || (weaponNum[2])) {
        return 1;
    }
    return 0;
}

void warrior::getDamage(int nowDamage) {
    nowLife -= nowDamage;
}

bool warrior::isDead() {
    return nowLife <= 0;
}

void warrior::fight(warrior* oppo) {
    if (!weaponLength) return;
    if (weaponPtr > weaponLength) {
        weaponPtr = 1;
        weaponNum[3] = arrow1;
        arrow1 = 0;
    }
    if (weaponPtr <= weaponNum[0]) {
        int nowDamage = nowAtk * 2 / 10;
        oppo->getDamage(nowDamage);
        weaponPtr++;
    }
    else if (weaponNum[1]) {
        int nowDamage = nowAtk * 4 / 10;
        oppo->getDamage(nowDamage);
        if (warriorKind != 1) getDamage(nowDamage >> 1);
        weaponNum[1]--; weaponLength--;
    }
    else if (weaponNum[2]) {
        int nowDamage = nowAtk * 3 / 10;
        oppo->getDamage(nowDamage);
        if (weaponNum[3]) {
            weaponNum[3]--; weaponNum[2]--;
            weaponLength--;
        }
        else {
            arrow1++; weaponPtr++;
        }
    }
    else {
        cout << "weaponerror!";
        assert(1 == 0);
    }
}

void warrior::setWeaponReady() {
    weaponPtr = 1;
    weaponNum[3] += arrow1;
    arrow1 = 0;
}

void warrior::getRewardWeapon(warrior *p) {
    rep(i, 0, 3) {
        weaponNum[i] += p->weaponNum[i];
    }
    weaponLength += p->weaponLength;
}

void warrior::reportState(int nowHour) {
    outTime(nowHour, 55);
    reportName(' ');
    cout << "has " << weaponNum[0] << " sword " << weaponNum[1] << " bomb " << weaponNum[2] << " arrow and ";
    cout << nowLife << " elements" << endl;
}

class dragon: public warrior{
    public:
        dragon(headQuarter *h, int Id, int Kind): warrior(h, Id, Kind) {
            weaponNum[Id % 3]++;
            weaponLength = 1;
            nowAtk = warriorAtk[Kind];
        }

        void hooray(int nowHour, int cityNum) {
            outTime(nowHour, 40);
            reportName(' ');
            cout << "yelled in city " << cityNum << endl;
        }
};

class ninja: public warrior{
    public:
        ninja(headQuarter *h, int Id, int Kind): warrior(h, Id, Kind) {
            weaponNum[Id % 3]++;
            weaponNum[(Id + 1) % 3]++;
            weaponLength = 2;
            nowAtk = warriorAtk[Kind];
        }
};

class iceman: public warrior{
    public:
        iceman(headQuarter *h, int Id, int Kind): warrior(h, Id, Kind) {
            weaponNum[Id % 3]++;
            weaponLength = 1;
            nowAtk = warriorAtk[Kind];
        }

        void reduceLife() {
            nowLife -= nowLife / 10;
        }
};

class lion: public warrior{
    private:
        int loyal;
    public: 
        lion(headQuarter *h, int Id, int Kind): warrior(h, Id, Kind) {
            weaponNum[Id % 3]++;
            weaponLength = 1;
            nowAtk = warriorAtk[Kind];
            loyal = h->totalLife;
            cout << "Its loyalty is " << loyal << endl;
        }

        bool notLoyal() {
            return loyal <= 0;
        }

        void reduceLoyal() {
            loyal -= k;
        }
};

class wolf: public warrior{
    public:
        wolf(headQuarter *h, int Id, int Kind): warrior(h, Id, Kind) {
            nowAtk = warriorAtk[Kind];
        }

        void robWeapon(warrior *p, int nowHour, int nowCity) {
            if ((p == NULL) || (p->warriorKind == 4)) return;
            if (weaponLength == 10) return;
            p->setWeaponReady();
            rep(i, 0, 2)
            {
                if (p->weaponNum[i]) {
                    int tmp = min(p->weaponNum[i], 10 - weaponLength);
                    weaponNum[i] += tmp; weaponLength += tmp;
                    p->weaponNum[i] -= tmp; p->weaponLength -= tmp;
                    outTime(nowHour, 35);
                    reportName(' ');
                    cout << "took " << tmp << " " << weaponName[i] << " from ";
                    p->reportName(' ');
                    cout << "in city " << nowCity << endl;
                    if (i == 2) {
                        int tmp2 = min(p->weaponNum[3], tmp - p->weaponNum[2]);
                        weaponNum[3] += tmp2; 
                        p->weaponNum[3] -= tmp2; 
                    }
                    return;
                }
            }
        }   
};

warrior* city[25][2];
bool endFlag;

void headQuarter::produceWarrior(int nowHour) {
    if (!canProduce) return;
    nowProduceWarrior++;
    if (nowProduceWarrior > 4) nowProduceWarrior -= 5;
    if (totalLife >= warriorLife[order[nowProduceWarrior]]) {
        totWarrior++;
        totalLife -= warriorLife[order[nowProduceWarrior]];
        warrior* tmpWarrior = NULL;
        outTime(nowHour, 0);
        if (order[nowProduceWarrior] == 0) tmpWarrior= new dragon(this, totWarrior, 0);
        else if (order[nowProduceWarrior] == 1) tmpWarrior = new ninja(this, totWarrior, 1);
        else if (order[nowProduceWarrior] == 2) tmpWarrior = new iceman(this, totWarrior, 2);
        else if (order[nowProduceWarrior] == 3) tmpWarrior = new lion(this, totWarrior, 3);
        else if (order[nowProduceWarrior] == 4) tmpWarrior = new wolf(this, totWarrior, 4);
        city[position][colorId] = tmpWarrior;
        return;
    }
    if (canProduce) {
        canProduce = 0;
    }
}

void lionRunAway(int nowHour) {
    rep(i, 0, n + 1) rep(j, 0, 1) {
        if ((city[i][j] != NULL) && (city[i][j]->getKind() == 3) && (((lion*)city[i][j] )->notLoyal())) {
            outTime(nowHour, 5);
            city[i][j]->reportName(' ');
            cout << "ran away" << endl;
            city[i][j] = NULL;
        }
    }
}

void warriorMove(int nowHour) {
    warrior* tmpCity[25][2];
    rep(i, 0, n + 1) rep(j, 0, 1) tmpCity[i][j] = city[i][j];
    rep(i, 0, n + 1) {
        city[i][0] = NULL;
        if ((i) && (tmpCity[i - 1][0] != NULL)) {
            warrior* tmpWarrior = tmpCity[i - 1][0];
            if (tmpWarrior->getKind() == 2) {
                ((iceman*)tmpWarrior)->reduceLife();
            }
            else if (tmpWarrior->getKind() == 3) {
                ((lion*)tmpWarrior)->reduceLoyal();
            }
            city[i][0] = tmpWarrior;
        }
        city[i][1] = NULL;
        if ((i <= n) && (tmpCity[i + 1][1] != NULL)) {
            warrior* tmpWarrior = tmpCity[i + 1][1];
            if (tmpWarrior->getKind() == 2) {
                ((iceman*)tmpWarrior)->reduceLife();
            }
            else if (tmpWarrior->getKind() == 3) {
                ((lion*)tmpWarrior)->reduceLoyal();
            }
            city[i][1] = tmpWarrior;
        }
    }
    rep(i, 0, n + 1) {
        if (city[i][0]) {
            outTime(nowHour, 10);
            if ((i > 0) && (i <= n)) {
                city[i][0]->reportName(' ');
                cout << "marched to city " << i << " with ";
				city[i][0]->reportMove();
				cout << endl;
            }
            else if (i == n + 1) {
                city[i][0]->reportName(' ');
                cout << "reached blue headquarter with ";
				city[i][0]->reportMove();
				cout << endl;
                outTime(nowHour, 10);
                cout << "blue headquarter was taken" << endl;
                endFlag = 1;
            }
        }
        if (city[i][1]) {
            outTime(nowHour, 10);
            if ((i > 0) && (i <= n)) {
                city[i][1]->reportName(' ');
                cout << "marched to city " << i << " with ";
				city[i][1]->reportMove();
				cout << endl;
            }
            else if (i == 0) {
                city[i][1]->reportName(' ');
                cout << "reached red headquarter with ";
				city[i][1]->reportMove();
				cout << endl;
                outTime(nowHour, 10);
                cout << "red headquarter was taken" << endl;
                endFlag = 1;
            }
        }
    }       
}

void allRobWeapon(int nowHour) {
    rep(i, 1, n) rep(j, 0, 1) {
        if ((city[i][j] != NULL) && (city[i][j]->getKind() == 4) && (city[i][j ^ 1] != NULL)) {
            ((wolf*)city[i][j])->robWeapon(city[i][j ^ 1], nowHour, i);
        }
    }
}

void checkDeath(warrior* &a, warrior* &b,int nowHour,int cityNum) {
    bool op1 = a->isDead(), op2 = b->isDead();
    outTime(nowHour, 40);
    a->setWeaponReady(); b->setWeaponReady();
    if ((op1) && (op2)) {
        cout << "both ";
        a->reportName(' ');
        cout << "and ";
        b->reportName(' ');
        cout << "died in city " << cityNum << endl;
        a = NULL; b = NULL;
    }
    else if ((op1) && (!op2)) {
        b->reportName(' ');
        cout << "killed ";
        a->reportName(' ');
        cout << "in city " << cityNum << " remaining " << b->getLife() << " elements" << endl;
        b->getRewardWeapon(a); a = NULL;
        if (b->getKind() == 0) ((dragon*)b)->hooray(nowHour, cityNum);
    }
    else if ((!op1) && (op2)) {
        a->reportName(' ');
        cout << "killed ";
        b->reportName(' ');
        cout << "in city " << cityNum << " remaining " << a->getLife() << " elements" << endl;
        a->getRewardWeapon(b); b = NULL;
        if (a->getKind() == 0) ((dragon*)a)->hooray(nowHour, cityNum);
    }
    else if ((!op1) && (!op2)) {
        cout << "both ";
        a->reportName(' ');
        cout << "and ";
        b->reportName(' ');
        cout << "were alive in city " << cityNum << endl;
        if (a->getKind() == 0) ((dragon*)a)->hooray(nowHour, cityNum);
        if (b->getKind() == 0) ((dragon*)b)->hooray(nowHour, cityNum);
    }
}

void allBattle(int nowHour) {
    rep(i, 1, n) {
        if ((city[i][0] != NULL) && (city[i][1] != NULL)) {
            int fir = (i & 1) ^ 1, sec = fir ^ 1, flag = 1;
            city[i][0]->setWeaponReady(); city[i][1]->setWeaponReady();
            while (1) {
                if ((!city[i][0]->canDamage()) && (!city[i][1]->canDamage())) break;
                city[i][fir]->fight(city[i][sec]);
                if ((city[i][0]->isDead()) || (city[i][1]->isDead())) {
                    break;
                }
                fir ^= 1;sec ^= 1;
            }
            checkDeath(city[i][0], city[i][1], nowHour, i);
        }
    }
}

void allReportState(int nowHour) {
    rep(i, 0, n + 1) rep(j, 0, 1) {
        if (city[i][j] != NULL) {
            city[i][j]->reportState(nowHour);
        }
    }
}
                    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    rep(cas, 1, T) {
        cin >> m >> n >> k >> t;
        rep(i, 0, 4) cin >> warriorLife[i];
        rep(i, 0, 4) cin >> warriorAtk[i];
        rep(i, 0, n + 1) rep(j, 0, 1) city[i][j] = NULL;
        cout << "Case " << cas << ":" << endl;
        headQuarter red(0, m), blue(1, m);
        int nowHour = 0;endFlag = 0;
        //cout << 'a' << endl;
        while (nowHour * 60 <= t) {
            if (nowHour * 60 + 0 <= t) {
                red.produceWarrior(nowHour);
                blue.produceWarrior(nowHour);
            }
            if (nowHour * 60 + 5 <= t) {
                lionRunAway(nowHour);
            }
            if (nowHour * 60 + 10 <= t) {
                warriorMove(nowHour);
            }
            if (endFlag) break;
            if (nowHour * 60 + 35 <= t) {
                allRobWeapon(nowHour);
            }
            if (nowHour * 60 + 40 <= t) {
                allBattle(nowHour);
            }
            if (nowHour * 60 + 50 <= t) {
                red.reportTotalLife(nowHour);
                blue.reportTotalLife(nowHour);
            }
            if (nowHour * 60 + 55 <= t) {
                allReportState(nowHour);
            }
            nowHour++;
        }
    }
    return 0;
}



