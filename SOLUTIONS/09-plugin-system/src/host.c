#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void) {
    printf("Plugin Host\n");
    void *handle = dlopen("./bin/plugin.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Cannot open plugin: %s\n", dlerror());
        return 1;
    }
    
    void (*plugin_hello)(void) = (void (*)(void))dlsym(handle, "plugin_hello");
    if (!plugin_hello) {
        fprintf(stderr, "Cannot find symbol: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }
    
    plugin_hello();
    dlclose(handle);
    return 0;
}
