/**
 * author: xmmmmmovo
 * generation time: 2019/05/22
 * filename: MR.LiBeatMonstor.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Monstor
{
private:
    string name;
    int hp;
public:
    Monstor(string n, int h)
            : name(n), hp(h){}
    void Hurt(int decrease_hp) {
        cout << name << " hurt!";
        if (decrease_hp >= hp) {
            Killed();
            return;
        }
        
        this->hp -= decrease_hp;
        cout << name << " now HP : " << hp << endl;
    }

    void Killed() {
        cout << name << " was killed !" << endl;
    }

    int GetHp() {
        return hp;
    }
};

class Weapons
{
private:
    int attack_damage = 1;
public:
    Weapons(){}
    void SetAttackDamage(int d) {
        attack_damage = d;
    }

    int GetAttackDamage() {
        return attack_damage;
    }

    virtual void AttackTarget(Monstor &mon) = 0;

};

class WoodSword : public Weapons 
{
public:
    WoodSword() {
        SetAttackDamage(50);
    }

    void AttackTarget(Monstor &mon) override {
        mon.Hurt(GetAttackDamage());
    }
};
class IronSword: public Weapons
{
public:
    IronSword() {
        SetAttackDamage(100);
    }

    void AttackTarget(Monstor &mon) override {
        mon.Hurt(GetAttackDamage());
    }
};
class MagicSword : public Weapons
{
public:
    MagicSword(){
        SetAttackDamage(200);
    }

    void AttackTarget(Monstor &mon) override {
        mon.Hurt(GetAttackDamage());
    }
};

/**
 * 小李类
 * 未作线程安全的一个单例设计模式
*/
class LiPlayer
{
private:
    LiPlayer() {}
    LiPlayer(const LiPlayer &);
    LiPlayer & operator= (const LiPlayer &);

    string name = "xiaoli";
public:
    Weapons *weapon;

    static LiPlayer * GetInstance() {
        static LiPlayer li_instance;
        return &li_instance;
    }

    void Attack(Monstor &mon) {
        weapon->AttackTarget(mon);
    }
};

int main(int argc, char const *argv[]) {
    Monstor m1("Slime", 100);
    Monstor m2("Slime2", 150);
    Monstor m3("demo", 250);
    LiPlayer *player = LiPlayer::GetInstance();
    player->weapon = new WoodSword();
    player->Attack(m1);
    player->Attack(m1);
    player->weapon = new IronSword();
    player->Attack(m2);
    player->Attack(m2);
    player->weapon = new MagicSword();
    player->Attack(m3);
    player->Attack(m3);
    // cout << m1.GetHp() << endl;
    // player->Attack(m1);

    system("pause");
    return 0;
}