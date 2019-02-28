/*
** EPITECH PROJECT, 2019
** main
** File description:
** by oriol
*/
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "list.hpp"

void  my_putstr(std::string str);
/*
int main()
{
    void *handle;
    void (*func)(std::string);
    std::string a = "damama";

    handle = dlopen("./liball.so", RTLD_LAZY);
    *(void**)(&func) = dlsym(handle, "my_putstr");
    std::cout << "enter\n";
    func(a);
    if (!func)
        std::cout << "ERROR\n";
    func(a);
    std::cout << "out\n";
    // my_putstr("damama");
    dlclose(handle);
}
*/

#include <iostream>
#include <dlfcn.h>

int main() {
    using std::cout;
    using std::cerr;

    cout << "C++ dlopen demo\n\n";

    // open the library
    cout << "Opening hello.so...\n";
    void* handle = dlopen("./liball.so", RTLD_LAZY);
    
    if (!handle) {
        cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    
    // load the symbol
    cout << "Loading symbol hello...\n";
    typedef void (*hello_t)();

    // reset errors
    dlerror();
    hello_t hello = (hello_t) dlsym(handle, "hello");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol 'hello': " << dlsym_error <<
            '\n';
        dlclose(handle);
        return 1;
    }
    
    // use it to do the calculation
    cout << "Calling hello...\n";
    hello();
    
    // close the library
    cout << "Closing library...\n";
    dlclose(handle);
}