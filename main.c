#include <stdio.h>
#include <stdlib.h>

int pow(int inVal, int exponent){
    for (int i=0; i<exponent; i++){
    inVal*=inVal;
    }
    return inVal;
}

int check_in_set(int val, int * set_ptr, int set_len){
    int *end_ptr = set_ptr+set_len;

    for (int *ptr=set_ptr; ptr<end_ptr; ptr++){
        if (*ptr==val){
            return 1;
        }
    }
    return 0;
}

void print_set(int * set_ptr, int set_len){
    int *end_ptr = set_ptr+set_len;
    for (int *ptr=set_ptr; ptr<end_ptr; ptr++){
        printf("%d ", *ptr);
    }
}

int input(int *set, int set_len){
    int temp, temp_elem;
    printf("Enter first element:\n");
    scanf("%d", &temp_elem);
    *set = temp_elem;
    temp_elem=0;

    while (1){
        printf("Enter more elements? [0/1] \n");
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
            printf("The set length is: %d; with the current element being :%d \n", set_len, temp_elem);
            *(set+(set_len-1))=temp_elem;
        }

    }
    return set_len;
}

void set_intersection(int * set1, int set1_len, int * set2, int set2_len){
    int set3_len, set3_count=0, final_set3_len=0;
    if (set1_len>set2_len){
        set3_len=set2_len;
    }
    else{
        set3_len=set1_len;
    }
    int * set3 = (int*)calloc(set3_len, sizeof(int));
    int * set1_end = set1+set1_len;
    int * set2_end = set2+set2_len;

    for (int*ptr=set1; ptr<set1_end; ptr++){
        if (check_in_set(*ptr, set2,set2_len)){
            *(set3+set3_count)=*ptr;
            set3_count++;
            final_set3_len++;
        }
        else{
            continue;
        }
    }

    set3=realloc(set3, final_set3_len*sizeof(int));

    print_set(set3, final_set3_len);
}

void set_subtract(int* set1, int set1_len, int* set2, int set2_len){
    //set1 - set2
    int final_set3_len=0;
    int * set3 = (int*) calloc(set1_len, sizeof(int));
    for (int* ptr= set1; ptr<(set1+set1_len); ptr++){
        if (!(check_in_set(*ptr, set2, set2_len))) {
            *(set3 + final_set3_len) = *ptr;
            final_set3_len++;
        }
    }

    set3=realloc(set3, final_set3_len * sizeof(int));
    print_set(set3, final_set3_len);
}

void symmDifference(int *set1, int set1_len, int *set2, int set2_len){
    //union-intersection

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

void unionOfSet(int *set1, int set1_len, int *set2, int set2_len){
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

void power_set(int * set, int set_len){
    int power_set_len;
    power_set_len= pow(2, set_len);
    int power_arr[power_set_len];

}

int main(){
    int set1_len=1;
    int * set1;
    printf("Currently Entering SET 1 \n \n");
    set1 = (int*)calloc(1, sizeof(int));
    set1_len = input(set1, set1_len);

    int set2_len=1;
    int * set2;
    printf("\n \n Currently Entering SET 2 \n \n");
    set2 = (int*)calloc(1, sizeof(int));
    set2_len = input(set2, set2_len);
    printf("\n \n SET 1: \t");
    print_set(set1, set1_len);
    printf("SET 2: \t");
    print_set(set2, set2_len);

    printf("\n \n Set1 - Set2: ");
    set_subtract(set1, set1_len, set2, set2_len);

    printf("\n \n Set2 - Set1: ");
    set_subtract(set2, set2_len, set1, set1_len);

    printf("\n \n Set1 intersection Set2: ");
    set_intersection(set1, set1_len, set2, set2_len);

    printf("\n \n Set1 symmdiff Set2: ");
    symmDifference(set1, set1_len, set2, set2_len);

    printf("\n \n Set1 union Set2: ");
    unionOfSet(set1, set1_len, set2, set2_len);


    return 0;
}