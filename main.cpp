
/* Simple Fight
 * File:   main.cpp
 * Author: David Au
 *
 * Created on April 21, 2018, 9:01 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Soldier{
private:
    int dmgValue;
    int defValue;
public:
    std::string name;
    int healthValue;
    
    // Sets the name, amount of health, attack value, and defense value
    Soldier(std::string name, int healthValue, int dmgValue, int defValue){
        this->name = name;
        this->healthValue = healthValue;
        this->dmgValue = dmgValue;
        this->defValue = defValue;
    }
    
    // Randomly generates an attack value based on the soldier's given damage value
    int Attack(){
        return std::rand() % this->dmgValue;
    }
    
    // Randomly generates a defense value based on the soldier's given defense value
    int Defend(){
        return std::rand() % this->defValue;
    }
};

class Battle{
public:
    /*
     Pass soldiers in by reference in order to keep track of continued damage to each
     * Continues looping as each soldier takes turns battling until one soldier health reaches 0
     */
    static void StartFight(Soldier& soldier1, Soldier& soldier2){
        while (true){
            if(Battle::GetDamageResult(soldier1, soldier2).compare("GG") == 0){
                std::cout << "GG\n";
                break;
            }
            if(Battle::GetDamageResult(soldier2, soldier1).compare("GG") == 0){
                std::cout << "GG\n";
                break;
            }
        }
    }
    
    static std::string GetDamageResult(Soldier& soldier1, Soldier& soldier2){
        int soldier1DmgValue = soldier1.Attack();
        int soldier2DefValue = soldier2.Defend();
        int damageToSoldier2 = ceil(soldier1DmgValue - soldier2DefValue);
        
        // Changes health values if it is above 0 and outputs the changes
        damageToSoldier2 = (damageToSoldier2 <= 0) ? 0 : damageToSoldier2;
        soldier2.healthValue = soldier2.healthValue - damageToSoldier2;
        printf("%s attacks %s and deals %d damage\n", soldier1.name.c_str(), soldier2.name.c_str(), damageToSoldier2);
        printf("%s is down to %d health\n", soldier2.name.c_str(), soldier2.healthValue);
        
        // Once health reaches 0, battle ends and returns a GG
        if(soldier2.healthValue <= 0){
            printf("%s has died and %s is the Lord of Chaos\n", soldier2.name.c_str(), soldier1.name.c_str());
            return "GG";
        }else {
            return "RE";
        }
    }
};

/*
 * 
 */
int main() {
    
    srand(time(NULL));
    Soldier daoist1("Darknorth", 100, 35, 15);
    Soldier daoist2("Lyerre", 150, 25, 10);
    
    Battle::StartFight(daoist1, daoist2);

    return 0;
}

