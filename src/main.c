#include <GL/gl.h>
#include "../kerep/src/base/base.h"

int main(){
    setlocale(LC_ALL, "en-US.Unicode");
    ktDescriptors_beginInit();
    ktDescriptors_initKerepTypes();
    ktDescriptors_endInit();
    printf("hello!\n");
    ktDescriptor desc=ktDescriptor_get(ktId_Bool);
    printf("name: %s id: %u size: %u\n", desc.name, desc.id, desc.size);
    return 0;
}
