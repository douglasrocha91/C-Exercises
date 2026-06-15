#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("FSM Compiler\n");
    printf("Generating dummy C code for FSM...\n");
    
    FILE *f = fopen("fsm_out.c", "w");
    if (!f) return 1;
    
    fprintf(f, "#include <stdio.h>\n");
    fprintf(f, "typedef enum { STATE_A, STATE_B } State;\n");
    fprintf(f, "void run_fsm() { printf(\"FSM running\\n\"); }\n");
    fclose(f);
    
    printf("Generated fsm_out.c\n");
    return 0;
}
