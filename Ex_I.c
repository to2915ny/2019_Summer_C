#include <stdio.h>

void print_line(int size) { 
	int i;
    for(i=0;i<size;i++){
        printf("#");
    }
    printf("\n");
	
} 

void print_star(int size){
    int i;
    for(i=0;i<size;i++){
        printf("*");
    }
     printf("\n");
	
	
}

void print_char(int size, char ch){
	int i;
    for(i=0;i<size;i++){
        printf("%c",ch);
    }
    printf("\n");

	
}

int ask_biman(int height, int weight){

	float biman = weight / (    (float)(height)/100 * (float)(height)/100   )  ;

    if(biman<18.5)
        printf("저체중 입니다\n");
    else if(biman>18.5 && biman<23)
        printf("정상체중 입니다\n");
    else if(biman>23 && biman<25)
        printf("과체중 입니다\n");
    else if(biman>25 && biman<30)
        printf("경도비만 입니다\n");
    else
    {
        printf("고도비만 입니다\n");
    }
    
	return 0;
}

void I01(){
	print_line(5);
	print_line(10);
}

void I02(){
	int i;
	for (i=0;i<10;i++)
		print_star(i);
}

void I03(){
	int i;
	int number[10];	

    for(i=0;i<10;i++){
        printf("숫자를 입력해주세요.");
        scanf("%d",&number[i]);
    }
    for(i=0;i<10;i++){
        print_star(number[i]);
    }
	
}

void I04(){
	int i;
	char ch;
	int number[10];	
    printf("사용할 문자를 입력하세요");
    scanf("%c",&ch);
    scanf("%c",&ch);

    for(i=0;i<10;i++){
        printf("숫자를 입력해주세요.");
        scanf("%d",&number[i]);
    }
    for(i=0;i<10;i++){
        print_char(number[i],ch);
    }
}

void I05(){
	int i;
	int height, weight;	

    for(i=0;i<10;i++){
        printf("%d번째 사람의 신장(cm)과 체중(kg)을 입력하시오. ",i+1);
        scanf("%d %d",&height,&weight);
        ask_biman(height,weight);
    }
}

int main(void) {

	 int no;
    printf("Q No? > ");
    scanf("%d", &no);
    switch (no)
    {
    case 1:
        I01();
        break;
    case 2:
        I02();
        break;
    case 3:
        I03();
        break;
    case 4:
        I04();
        break;
    case 5:
        I05();
        break;
    default:
        break;
    }

   
	
	return 0;
}