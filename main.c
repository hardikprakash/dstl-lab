#include <stdio.h>
#include <stdlib.h>

int checkInSet(int val, int * setPointer, int setLength){
    int *endPointer = setPointer+setLength;

    for (int *ptr=setPointer; ptr<endPointer; ptr++){
        if (*ptr==val){
            return 1;
        }
    }
    return 0;
};

void printSet(int * set_ptr, int setLength){
    int *endPointer = set_ptr+setLength;
    printf("\n");
    for (int *ptr=set_ptr; ptr<endPointer; ptr++){
        printf("%d, ", *ptr);
    }
}

int input(int *set, int setLength){
    int count=0, temp, tempElement;
    printf("Enter first element: ");
    scanf("%d", &tempElement);
    *set = tempElement;
    tempElement=0;

    while (1){
        printf("Enter more elements? [0 for N, else 1]: ");
        scanf("%d", &temp);

        if (temp==0){
            break;
        }

        else{
            printf("Enter new element: ");
            scanf("%d", &tempElement);
            if (checkInSet(tempElement, set, setLength)){
                printf("Element already in set, skipped. \n");
                continue;
            }
            setLength++;
            set = realloc(set, setLength*sizeof(int));
            *(set+(setLength-1))=tempElement;
        }

    }
    return setLength;
}

void setIntersection(int * set1,  int * set2 ,int set1_len,int set2_len){
   int *intersectSet;
   int counter = 0;
   intersectSet = (int*)calloc(counter, sizeof(int));
   
   for(int *ptr = set1; ptr<set1+set1_len; ++ptr){
        if ((checkInSet(*ptr, set2, set2_len))) {
            ++counter;
            intersectSet = realloc(intersectSet, counter*sizeof(int));
            *(intersectSet+(counter-1)) = *ptr;
        }
   }
   
   printSet(intersectSet, counter);
}

void setSubtract(int *set1, int *set2, int set1_len, int set2_len){
    int* differenceSet; int counter = 0;
    differenceSet = (int*)calloc(counter, sizeof(int));
    for(int *ptr = set1; ptr<set1+set1_len; ++ptr){
        if(!checkInSet(*ptr, set2, set2_len)){
            ++counter;
            differenceSet = realloc(differenceSet, counter*sizeof(int));
            *(differenceSet+(counter-1)) = *ptr;
        }
    }

    printSet(differenceSet, counter);
}

void setSymmDifference(int *set1, int *set2, int set1_len, int set2_len){

    int* symmetricDifferenceSet; int counter = 0;
    symmetricDifferenceSet = (int*)calloc(counter, sizeof(int));
    for(int *ptr = set1; ptr<set1+set1_len; ++ptr){
        if(!checkInSet(*ptr, set2, set2_len)){
            ++counter;
            symmetricDifferenceSet = realloc(symmetricDifferenceSet, counter*sizeof(int));
            *(symmetricDifferenceSet+(counter-1)) = *ptr;
        }
    }

    for(int *ptr = set2; ptr<set2+set2_len; ++ptr){
        if(!checkInSet(*ptr, set1, set1_len)){
            ++counter;
            symmetricDifferenceSet = realloc(symmetricDifferenceSet, counter*sizeof(int));
            *(symmetricDifferenceSet+(counter-1)) = *ptr;
        }
    }

    printSet(symmetricDifferenceSet, counter);
}

void setUnion(int *set1, int *set2, int set1_len, int set2_len){
    int* unionSet;int counter = 0;
    unionSet = (int*)calloc(counter, sizeof(int));

    for(int *ptr = set1; ptr<set1+set1_len; ++ptr){
        ++counter;
        unionSet = realloc(unionSet, counter*sizeof(int));
        *(unionSet+(counter-1)) = *ptr;
    }
    for(int *ptr2 = set2; ptr2<set2+set2_len; ++ptr2){
        if(!checkInSet(*ptr2, unionSet, counter)){
            ++counter;
            unionSet = realloc(unionSet, counter*sizeof(int));
            *(unionSet+(counter-1)) = *ptr2;
        }
    }

    printSet(unionSet, counter);

}

int main(){
    int set1_len=1, set2_len=1;
    int * set1, * set2;
    
    
    set1 = (int*)calloc(1, sizeof(int));
    set2 = (int*)calloc(1, sizeof(int));
    printf("\n Input the first set... \n");

    set1_len = input(set1, set1_len);
    printSet(set1,set1_len);
    printf("\n Input the second set... \n");
    set2_len = input(set2, set2_len);
    printSet(set2,set2_len);

    printf("\n Set 1 union Set 2: ");
    setUnion(set1, set2, set1_len, set2_len);
    printf("\n Set 1 intersection Set 2: ");
    setIntersection(set1, set2, set1_len, set2_len);
    printf("\n Set 1 - Set 2: ");
    setSubtract(set1, set2, set1_len, set2_len);
    printf("\n Set 2 - Set 1: ");
    setSubtract(set2, set1, set2_len, set1_len);
    printf("\n Set 1 symmetric difference Set 2: ");
    setSymmDifference(set1, set2, set1_len, set2_len);
    printf("\n Set 2 symmetric difference Set 1: ");
    setSymmDifference(set2, set1, set2_len, set1_len);

    return 0;
}
