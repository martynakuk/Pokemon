
#include "Pokemon.h"
#include "Gracz.h"
#include "Walka.h"
using namespace std;

int main(){
   // Gracz ja("Gracz");
   // Walka walka(ja);
   // walka.start();

    int a = 3;
    int b =4;
    auto result = [=](int c, int d){
        return c + d;
    };
    std::cout<<result(a,b);
}
