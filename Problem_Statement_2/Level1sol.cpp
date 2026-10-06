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

    void display_stats(){
        std :: cout<<name<<"("<<element<<")"<<" -HP :"<<hp<<"/"<<hpOrg<<","
        <<"Attack:"<<attack<<",Defence:"<<defence<<",Speed:"<<speed<<"\n"
        <<"Moves:";
        for(int i=0;i<move.size();++i){
            std :: cout<<move[i].name<<"("<<move[i].power<<"),  ";
        }
        std :: cout<<"\n";
    }
    void attacker_attack(Bender& obj1,int index){
        std :: cout<<name<<" used "<<move[index].name<<"!\n";
        int damage=std :: round((static_cast<double>(attack)*move[index].power)/obj1.defence);
        //We apply ststic cast to only one term and not all as C++ does implicit type conversion
        //of other terms to double since int is being multiplied /divided with double 
        std :: cout<<obj1.name<<" took "<<damage<<" damages!\n";
        obj1.hp-=damage;
        if(obj1.hp<=0)
        obj1.hp=0;
        obj1.display_stats();
    }
    bool is_fainted(){
        if(hp==0)
            return true;
        return false;
    }
};

int main(){
    //Create Kael(Attacker)
    Bender Kael("Kael","Fire",100, 58, 38, 88,
             {{{"Ember Slash", 40}, {"Quick Jab", 30}, {"Focus", 0}, {"Flame Surge", 70}}});

    //Create Mira(Defender)
    Bender Mira("Mira", "Water", 92, 50, 45, 60,
             {{{"Water Whip", 35}, {"Tide Push", 25}, {"Mist Veil", 0}, {"Tidal Wave", 60}}});

    //Display initial stats
    Kael.display_stats();
    Mira.display_stats();
    //Attack result
    Kael.attacker_attack(Mira,0);
    std :: cout<<"\n";
    //Checking if defender fainted
    std :: cout<<"Mira fainted:"<<Mira.is_fainted();
}