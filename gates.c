#include <stdio.h>
#include <stdlib.h>


void arrayPrinter(int *inp1, int* inp2, int* out, int len){
    printf("\n");
    printf("A   B   X\n\n");
    for(int i = 0; i < len; ++i){
        printf("%d   %d   %d \n", inp1[i], inp2[i], out[i]);
    }
    printf("\n");
}

int* andCalc(int *inp1, int *inp2, int len){
    int out[len];
    for(int i = 0; i < len; ++i){
        if((inp1[i] == 1 && inp2[i] == 1)){
            out[i] = 1;
        }else{
            out[i] = 0;    
        }
    }
    arrayPrinter(inp1, inp2 ,out, len);
}

int* orCalc(int *inp1, int *inp2, int len){
    int out[len];
    for(int i = 0; i < len; ++i){
        if(inp1[i] == 1 || inp2[i] == 1){
            out[i] = 1;
        }else{
            out[i] = 0;    
        }
    }
   arrayPrinter(inp1, inp2 ,out, len);
}

int* xorCalc(int *inp1, int *inp2, int len){
    int out[len];
    for(int i = 0; i < len; ++i){
        if((inp1[i] == 1 && inp2[i] == 1) || (inp1[i] == 0 && inp2[i] == 0)){
            out[i] = 0;
        }else{
            out[i] = 1;    
        }
    }
    arrayPrinter(inp1, inp2 ,out, len);
}

int* norCalc(int *inp1, int *inp2, int len){
   int out[len];
    for(int i = 0; i < len; ++i){
        if(inp1[i] == 1 || inp2[i] == 1){
            out[i] = 0;
        }else{
            out[i] = 1;    
        }
    }
   arrayPrinter(inp1, inp2 ,out, len);
}

int* xnorCalc(int *inp1, int *inp2, int len){
  int out[len];
    for(int i = 0; i < len; ++i){
        if((inp1[i] == 1 && inp2[i] == 1) || (inp1[i] == 0 && inp2[i] == 0)){
            out[i] = 1;
        }else{
            out[i] = 0;    
        }
    }
    arrayPrinter(inp1, inp2 ,out, len);
}

int main(){
    
    int len;
    
    printf("Please enter the size of the inputs \n");
    scanf("%d", &len);
    
    
    int inp1[len], inp2[len];
    int i = 0;
    printf("Input for the first input.... \n");
    while(i < len){
        int temp_elem;
        printf("Please enter the %d input \n", i+1);
        scanf("%d", &temp_elem);
        if (temp_elem != 0 && temp_elem != 1){
            printf("Only Binary Allowed! \n");
        }else{
            inp1[i] = temp_elem;
            ++i;
        }
        
    }
    
    i = 0;
    printf("Input for the second input.... \n");
    while(i < len){
        int temp_elem;
        printf("Please enter the %d input \n", i+1);
        scanf("%d", &temp_elem);
        if (temp_elem != 0 && temp_elem != 1){
            printf("Only Binary Allowed! \n");
        }else{
            inp2[i] = temp_elem;
            ++i;
        }
        
    }
    printf("AND-");
    andCalc(inp1, inp2, len);
    printf("\n");
    printf("OR-");
    orCalc(inp1, inp2, len);
    printf("\n");
    printf("XOR-");
    xorCalc(inp1, inp2, len);
    printf("\n");
    printf("NOR-");
    norCalc(inp1, inp2, len);
    printf("\n");
    printf("XNOR-");
    xnorCalc(inp1, inp2, len);
    printf("\n");
}

