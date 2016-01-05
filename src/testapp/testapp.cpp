#include <iostream>
#include <string>
#include <ctime>
#include <KLKeetchi.h>

int main(){
    std::cout << "Testme" << std::endl;

    int cachePolicy;
    int cacheSize;
    string ownAddr ="TEST";
    int ret;

    double time = static_cast<double>(std::time(NULL));

    KLKeetchi *keetchi = new KLKeetchi(cachePolicy, cacheSize, ownAddr);
    ret = keetchi->registerApplication("MyApp", "dede", time);
    std::cout << "Return value: " << ret << std::endl;
    ret = keetchi->registerApplication("MyApp", "dede", time);
    std::cout << "Return value: " << ret << std::endl;



}
