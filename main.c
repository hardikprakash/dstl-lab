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
    if(setLength==0){
        printf("NULL");
    }
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

void setIntersection(int * set1,  int * set2 ,int set1Len,int set2Len){
   int *intersectSet;
   int counter = 0;
   intersectSet = (int*)calloc(counter, sizeof(int));
   
   for(int *ptr = set1; ptr<set1+set1Len; ++ptr){
        if ((checkInSet(*ptr, set2, set2Len))) {
            ++counter;
            intersectSet = realloc(intersectSet, counter*sizeof(int));
            *(intersectSet+(counter-1)) = *ptr;
        }
   }
   
   printSet(intersectSet, counter);
}

void setSubtract(int *set1, int *set2, int set1Len, int set2Len){
    int* differenceSet; int counter = 0;
    differenceSet = (int*)calloc(counter, sizeof(int));
    for(int *ptr = set1; ptr<set1+set1Len; ++ptr){
        if(!checkInSet(*ptr, set2, set2Len)){
            ++counter;
            differenceSet = realloc(differenceSet, counter*sizeof(int));
            *(differenceSet+(counter-1)) = *ptr;
        }
    }

    printSet(differenceSet, counter);
}

void setSymmDifference(int *set1, int *set2, int set1Len, int set2Len){

    int* symmetricDifferenceSet; int counter = 0;
    symmetricDifferenceSet = (int*)calloc(counter, sizeof(int));
    for(int *ptr = set1; ptr<set1+set1Len; ++ptr){
        if(!checkInSet(*ptr, set2, set2Len)){
            ++counter;
            symmetricDifferenceSet = realloc(symmetricDifferenceSet, counter*sizeof(int));
            *(symmetricDifferenceSet+(counter-1)) = *ptr;
        }
    }

    for(int *ptr = set2; ptr<set2+set2Len; ++ptr){
        if(!checkInSet(*ptr, set1, set1Len)){
            ++counter;
            symmetricDifferenceSet = realloc(symmetricDifferenceSet, counter*sizeof(int));
            *(symmetricDifferenceSet+(counter-1)) = *ptr;
        }
    }

    printSet(symmetricDifferenceSet, counter);
}

void setUnion(int *set1, int *set2, int set1Len, int set2Len){
    int* unionSet;int counter = 0;
    unionSet = (int*)calloc(counter, sizeof(int));

    for(int *ptr = set1; ptr<set1+set1Len; ++ptr){
        ++counter;
        unionSet = realloc(unionSet, counter*sizeof(int));
        *(unionSet+(counter-1)) = *ptr;
    }
    for(int *ptr2 = set2; ptr2<set2+set2Len; ++ptr2){
        if(!checkInSet(*ptr2, unionSet, counter)){
            ++counter;
            unionSet = realloc(unionSet, counter*sizeof(int));
            *(unionSet+(counter-1)) = *ptr2;
        }
    }

    printSet(unionSet, counter);

}

int main(){
    int set1Len=1, set2Len=1;
    int * set1, * set2;
    set1 = (int*)calloc(1, sizeof(int));
    set2 = (int*)calloc(1, sizeof(int));
    printf("\n Input the first set... \n");

    set1Len = input(set1, set1Len);
    printSet(set1,set1Len);
    printf("\n Input the second set... \n");
    set2Len = input(set2, set2Len);
    printSet(set2,set2Len);

    printf("\n Set 1 union Set 2: ");
    setUnion(set1, set2, set1Len, set2Len);
    printf("\n Set 1 intersection Set 2: ");
    setIntersection(set1, set2, set1Len, set2Len);
    printf("\n Set 1 - Set 2: ");
    setSubtract(set1, set2, set1Len, set2Len);
    printf("\n Set 2 - Set 1: ");
    setSubtract(set2, set1, set2Len, set1Len);
    printf("\n Set 1 symmetric difference Set 2: ");
    setSymmDifference(set1, set2, set1Len, set2Len);

    return 0;
}
