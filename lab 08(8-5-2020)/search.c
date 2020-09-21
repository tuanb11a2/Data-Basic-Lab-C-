#include<stdio.h>
#include<string.h>

//Sequential searching in array
int sequential_search(char* name,int i,char key){
    int t = 0;
    while (key != name[t])
    {
        if(t < i){
            if(key == name[t]){
                break;
            }else{
                t++;
        }}else{
            t = -1;
            break;
        }
        
    }
    return t;
    
}

//Move to front search algorithms
int move_to_front_search(int* array,int n,int key){
    int i,j;
    int tmp = -1;
    for(i=0;i<n && array[i] != key ;i++){
        if(array[i] == key){
            tmp = array[i];
            for(j=i;j>=0;j--){
                array[j]=array[j-1];
            }
            array[0]=tmp;
            return tmp;
        }
    }
    
}

int main(void){
    int i;
    int array[10]={1,3,5,7,9,10,123,6,8,10};
    int index = move_to_front_search(array,10,7);
    //char* name = "abcd";
    //int index = sequential_search(name,strlen(name),'b');
    printf("%d\n",index);
    for(i =0 ;i<10;i++){
        printf("%d -",array[i]);
    }
    
}