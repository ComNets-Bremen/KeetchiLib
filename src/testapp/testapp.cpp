#include <iostream>
#include <string>
#include <ctime>
#include <KLKeetchi.h>
#include <config.h>

int main(){
    std::cout << "Testapp for \"" << PACKAGE_NAME << "\"" << std::endl;

    int cachePolicy;
    int cacheSize;
    string ownAddr ="TEST";
    int ret;

    double time = static_cast<double>(std::time(NULL));

    KLKeetchi *keetchi = new KLKeetchi(cachePolicy, cacheSize, ownAddr);
    ret = keetchi->registerApplication("MyApp", "myAddress", time);
    std::cout << "Return value: " << ret << std::endl;
    ret = keetchi->registerApplication("MyApp", "myAddress", time);
    std::cout << "Return value: " << ret << std::endl;
}
