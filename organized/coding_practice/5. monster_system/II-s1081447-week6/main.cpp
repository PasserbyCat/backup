#include <iostream>
#include "monster.h"

int main(int argc, const char *argv[])
{
    Dragon m1(0.6);
    Unicorn m2;

    int cnt = 1;
    while(true){
        std::cout << "Round " << cnt << std::endl;
        m1.attack(m2);
        m2.showStats();
        if( m2.getHP() <= 0 ){
            std::cout << ">>> Unicorn died, Dragon win! <<<" << std::endl;
	    m1.showStats();
            break;
        }
        m2.attack(m1);
        m1.showStats();
        if( m1.getHP() <= 0 ){
            std::cout << ">>> Dragon died, Unicorn win <<<" << std::endl;
	    m2.showStats();
            break;
        }
        std::cout << "===============================" << std::endl;
        cnt++;
    }
    return 0;
}
