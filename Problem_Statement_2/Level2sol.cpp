# include <iostream>
# include <string>
# include <array>
# include <cmath>
struct Move{
    std :: string name;
    int power;
};
class Bender{
    std::string name,element;
    int hp,hpOrg,attack,defence,speed;
    std :: array<Move,4>move;
    public:
    Bender(std :: string n,std::string e, int h, int a, 
        int d, int s,std::array<Move,4>m):
            name(n),element(e),hp(h),attack(a),defence(d),speed(s),move(m){
                 hpOrg=hp;
            }
            int get_speed(){
                return speed;
            }
};
class Duel{
    Bender first, second;
    public:
        Duel(Bender b1, Bender b2){
            if(b1.get_speed()>b2.get_speed()){
                b1=first;
                b2=second;
            }
            else if(b1.get_speed()<b2.get_speed()){
                b2=first;
                b1=second;
            }
        }
        void start_duel(){

        }
};

int main(){
    //Create Kael(Attacker)
    Bender Kael("Kael","Fire",100, 58, 38, 88,
             {{{"Ember Slash", 40}, {"Quick Jab", 30}, {"Focus", 0}, {"Flame Surge", 70}}});

    //Create Mira(Defender)
    Bender Mira("Mira", "Water", 92, 50, 45, 60,
             {{{"Water Whip", 35}, {"Tide Push", 25}, {"Mist Veil", 0}, {"Tidal Wave", 60}}});
    
    Duel duel(Kael,Mira);
}