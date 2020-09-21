#include<stdio.h>
#include<stdlib.h>

//Global variable count comparisons
int count_compare = 0;

//Binary search
int binary_search(int array[],int n,int key){
    int Low,High,Mid;
    int boolean = 0;
    Low = 0;
    High = n-1;
    while (Low <= High)
    {
        count_compare ++;
        Mid = (Low + High)/2;
        if(key == array[Mid]){
            boolean = 1;
            count_compare ++;
            return Mid;
            break;
        }else if(key < array[Mid]){
            High = Mid - 1;
            count_compare ++;
        }else{
            Low = Mid + 1;
            count_compare ++;
        }
    }
    if(boolean == 0){
        return -1;
    }
    
}

int main(void){
    static int array[10]={1,3,5,6,7,8,9,10,12,15};
    int key,index;
    printf("Enter the key you want to find:");
    scanf("%d",&key);
    index = binary_search(array,10,key);
    printf("The position of the key in the array:%d\n",index);
    printf("The number of comparisons:%d",count_compare);
    return 0;

}