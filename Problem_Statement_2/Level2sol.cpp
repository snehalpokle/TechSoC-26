# include <iostream>
# include <string>
# include <array>
# include <cmath>
# include <algorithm>
int m=0;//To count number of super effective hits
struct Move{
    std :: string name;
    int power;
};
class Bender{
    std::string name,element;
    int hp,hpOrg,attack,defence,speed,elementid;
    std :: array<Move,4>move;
    public:
    Bender(std :: string n,std::string e, int h, int a, 
        int d, int s,std::array<Move,4>m):
            name(n),element(e),hp(h),attack(a),defence(d),speed(s),move(m){
                 hpOrg=hp;
                 if(element=="Water")
                 elementid=0;
                 else if(element=="Earth")
                 elementid=1;
                 else if(element=="Air")
                 elementid=2;
                 else if(element=="Fire")
                 elementid=3;
            }

            // int get_speed(){
            //     return speed;
            // }
            // std::string getName(){
            //     return name;
            // }
            // std::string getElement(){
            //     return element;
            // }
            friend class Duel;
    Bender(){}
    /*
    if we don't make a default constructor for Bender then we would get error
    as when we create Duel duel(Kael,Mira); in line 55 first duel is constructed then Kael is constructed
    and then Mira. So, when constructor would be called for Kael it exists in a form with no parameter
    passed , so a default constructor would be needed for that.
    */
};
class Duel{
    Bender attacker, defender;
    public:
        Duel(Bender b1, Bender b2){
            if(b1.speed>b2.speed){
                attacker=b1;
                defender=b2;
            }
            else if(b1.speed<b2.speed){
                attacker=b2;
                defender=b1;
            }
            else{}
        }
        void start_duel(){
            std::cout<<"=== DUEL BEGINS! ===\n";
            std::cout<<attacker.name<<"("<<attacker.element<<", HP:"<<attacker.hpOrg<<"/"<<attacker.hpOrg
            <<") VS "<<defender.name<<"("<<defender.element<<", HP:"<<defender.hpOrg<<"/"<<defender.hpOrg
            <<")\n";
        }
        double multiplier;
         void check_effectiveness(){
            if((attacker.elementid-defender.elementid)%4==1 || (attacker.elementid-defender.elementid)%4==-3){
            multiplier=2.0;
            std::cout<<"Super Effective!!!\n";
            ++m;
            }
            else if((attacker.elementid-defender.elementid)%4==-1 || (attacker.elementid-defender.elementid)%4==3){
            multiplier=0.5;
            std::cout<<"Not very Effective!!!!\n";
            }
            else{
            multiplier=1.0;
            std::cout<<"Neutral...\n";
            }
        }
        int calculate_criticalHit(){
            int criticl_multiplier;
            return 1;
        }
        double calculate_damage(int k){
            double base_damage=(static_cast<double>(attacker.attack)*attacker.move[k].power)/defender.defence;
            double final_damage=base_damage*multiplier*calculate_criticalHit();
            final_damage=std::max(1.0,std::round(final_damage));//both the arguments should be of the
            //same type(double in this case) or else we would get error
            return final_damage;
        }
        int i;
        void Turn(){
            i=1;
            while(attacker.hp>0 && defender.hp>0){
                std::cout<<"Select power move(0-3) for "<<attacker.name;
                int j;
                std::cin>>j;
                std :: cout<<"Turn "<<i<<": "<<attacker.name<<" goes first!! (Speed:"<<
                attacker.speed<<" VS "<<defender.speed<<")\n";
                std::cout<<attacker.name<<" used "<<attacker.move[j].name<<"!!\n";
                check_effectiveness();
                defender.hp-=calculate_damage(j);
                if(defender.hp<=0)
                defender.hp=0;
                std::cout<<defender.name<<" took "<<calculate_damage(j)<< " damages!!\n"
                <<defender.name<<" HP:"<<defender.hp<<"/"<<defender.hpOrg<<"\n";
                if(defender.hp==0){
                    std::cout<<"\n"<<defender.name<<" fainted!!!\n"
                    <<attacker.name<<" wins the duel!!!\n";
                    break;
                }
                Bender Temp;
                Temp=attacker;
                attacker=defender;
                defender=Temp;
                ++i;
            }
        }
        void Summary(){
            std ::cout<<"Duel Summary:\n"
            <<"-Winner:"<<attacker.name<<"\n"
            <<"-Turns:"<<i<<"\n"
            <<"-Critical Hits:"<<0<<"\n"
            <<"-Super Effective Hits:"<<m<<"\n";
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
    duel.start_duel();
    duel.Turn();
    duel.Summary();
}