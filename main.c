#include <stdio.h>

int check_in_set(int val, int * set_ptr, int set_len){
    int *end_ptr = set_ptr+set_len;

    for (int *ptr=set_ptr; ptr<end_ptr; ptr++){
        if (*ptr==val){
            return 1;
        }
    }
    return 0;
};

void print_set(int * set_ptr, int set_len){
    int *end_ptr = set_ptr+set_len;
    printf("\n");
    for (int *ptr=set_ptr; ptr<end_ptr; ptr++){
        printf("%d, ", *ptr);
    }
}

int input(int *set, int set_len){
    int count=0, temp, temp_elem;
    printf("Enter first element:\n");
    scanf("%d", &temp_elem);
    *set = temp_elem;
    temp_elem=0;

    while (1){
        printf("Enter more elements? [0 for N, else 1] \n");
        scanf("%d", &temp);

        if (temp==0){
            break;
        }

        else{
            printf("Enter new element: \n");
            scanf("%d", &temp_elem);
            if (check_in_set(temp_elem, set, set_len)){
                printf("Element already in set, skipped. \n");
                continue;
            }
            set_len++;
            set = realloc(set, set_len*sizeof(int));
            *(set+(set_len-1))=temp_elem;
        }

    }
    return set_len;
}

void set_intersection(int * set1,  int * set2 ,int set1_len,int set2_len){
   int *interSecSet;
   int counter = 0;
   interSecSet = (int*)calloc(counter, sizeof(int));
   
   for(int *ptr = set1; ptr<set1+set1_len; ++ptr){
        if ((check_in_set(*ptr, set2, set2_len))) {
            ++counter;
            interSecSet = realloc(interSecSet, counter*sizeof(int));
            *(interSecSet+(counter-1)) = *ptr;
        }
   }
   
   print_set(interSecSet, counter);
}

void set_subtract(int *set1, int *set2, int set1_len, int set2_len){
    int* diffSet; int counter = 0;
    diffSet = (int*)calloc(counter, sizeof(int));
    for(int *ptr = set1; ptr<set1+set1_len; ++ptr){
        if(!check_in_set(*ptr, set2, set2_len)){
            ++counter;
            diffSet = realloc(diffSet, counter*sizeof(int));
            *(diffSet+(counter-1)) = *ptr;
        }
    }

    print_set(diffSet, counter);
}

void set_symm_difference(int *set1, int *set2, int set1_len, int set2_len){

    int* symmDiffSet; int counter = 0;
    symmDiffSet = (int*)calloc(counter, sizeof(int));
    for(int *ptr = set1; ptr<set1+set1_len; ++ptr){
        if(!check_in_set(*ptr, set2, set2_len)){
            ++counter;
            symmDiffSet = realloc(symmDiffSet, counter*sizeof(int));
            *(symmDiffSet+(counter-1)) = *ptr;
        }
    }

    for(int *ptr = set2; ptr<set2+set2_len; ++ptr){
        if(!check_in_set(*ptr, set1, set1_len)){
            ++counter;
            symmDiffSet = realloc(symmDiffSet, counter*sizeof(int));
            *(symmDiffSet+(counter-1)) = *ptr;
        }
    }

    print_set(symmDiffSet, counter);
}

void set_union(int *set1, int *set2, int set1_len, int set2_len){
    int* unionSet;int counter = 0;
    unionSet = (int*)calloc(counter, sizeof(int));

    for(int *ptr = set1; ptr<set1+set1_len; ++ptr){
        ++counter;
        unionSet = realloc(unionSet, counter*sizeof(int));
        *(unionSet+(counter-1)) = *ptr;
    }
    for(int *ptr2 = set2; ptr2<set2+set2_len; ++ptr2){
        if(!check_in_set(*ptr2, unionSet, counter)){
            ++counter;
            unionSet = realloc(unionSet, counter*sizeof(int));
            *(unionSet+(counter-1)) = *ptr2;
        }
    }

    print_set(unionSet, counter);

}

int main(){
    int set1_len=1, set2_len=1;
    int * set1, * set2;
    
    
    set1 = (int*)calloc(1, sizeof(int));
    set2 = (int*)calloc(1, sizeof(int));
    printf("Input the first set... \n");

    set1_len = input(set1, set1_len);
    print_set(set1,set1_len);
    printf("Input the second set... \n");
    set2_len = input(set2, set2_len);
    print_set(set2,set2_len);

    set_intersection(set1,set2, set1_len ,set2_len);

    return 0;
}
