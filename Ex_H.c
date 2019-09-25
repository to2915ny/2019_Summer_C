#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void H01()
{
    int answer;     // 컴퓨터가 만들어 낸 1부터 100사이의 임의의 숫자
    int number_try; // 사용자가 제시한 숫자
    int count = 0;  // 사용자가 맞추려고 시도한 횟수

    int i;
    srand(time(0));

    answer = rand() % 100 + 1;

    while (1)
    {
        count += 1;
        printf("1부터 100까지 숫자 하나를 맞춰보세요.");
        scanf("%d", &number_try);
        if (number_try < answer)
            printf("좀 더 큰 수입니다.\n");
        else if (number_try > answer)
            printf("좀 더 작은 수입니다.\n");
        else
        {
            printf("%d 번만에 숫자를 맞추셨습니다.\n", count);
            return;
        }
    }
}

void H02()
{
    int lotto[6]; // 컴퓨터가 만들어 낸 로또 번호
    int count;    // 현재 만들어지고 있는 로또 번호의 순서(0, 1, 2, 3, 4, 5)
    int onemore;  // 반복여부 입력 (1:Yes, 2:No)
    int i, j;     // 반복문을 위한 변수

    srand(time(0));
    while (1)
    {
        for (i = 0; i < 6; i++)
        {

            lotto[i] = rand() % 45 + 1;
        }

        for (i = 0; i < 6; i++)
        {
            for (j = i + 1; j < 6; j++)
            {
                if (lotto[i] == lotto[j])
                    lotto[i] = rand() % 45 + 1;
            }
        }

        printf("생성된 로또 번호는");
        for (i = 0; i < 6; i++)
        {
            printf("%d ", lotto[i]);
        }

        printf("더 만드시겠습니까? (1:Yes, 2:No) >> ");
        scanf("%d", &onemore);
        if (onemore == 2)
            break;
    }

    return;
}

void H03()
{   
    srand(time(0));
    int my_finger;   // 컴퓨터가 낸 가위(1), 바위(2), 보(3)
    int com_finger;  // 사용자가 낸 가위(1), 바위(2), 보(3)
    int score[2][3]={0}; // 결과 횟수 (1행 : 컴퓨터의 승, 무, 패, 2행 : 사용자의 승, 무, 패)
    int i, j;        // 반복문을 위한 변수
    char *a[] = {"trash","가위", "바위", "보"};
    while (1)
    {
        com_finger = rand() % 3 + 1;
        printf("가위(1), 바위(2), 보(3)를 입력하세요. ");
        scanf("%d", &my_finger);

        if(my_finger == 0)
            break;

        for (i = 1; i < 4; i++)
        {
            if (com_finger == i)
            {
                printf("컴퓨터가 낸 것은 %s입니다.",a[i]);

            }
        }

        if (my_finger == com_finger){
            printf(" ---> 비김~\n\n");
            score[0][2]++; //사용자 비김 스코어
            score[1][2]++;

        }
        else if(my_finger==1 && com_finger ==2){
            printf(" ---> 컴퓨터 승!\n\n");
            score[1][0]++;
            score[0][1]++;
        }
         else if(my_finger==2 && com_finger ==1){
            printf(" ---> 사용자 승!\n\n");
            score[0][0]++;
            score[1][1]++;
        }
         else if(my_finger==2 && com_finger ==3){
            printf(" ---> 컴퓨터 승!\n\n");
            score[1][0]++;
            score[0][1]++;
        }
         else if(my_finger==3 && com_finger ==2){
            printf(" ---> 사용자 승!\n\n");
            score[0][0]++;
            score[1][1]++;
        }
           else if(my_finger==1 && com_finger ==3){
            printf(" ---> 사용자 승!\n\n");
            score[0][0]++;
            score[1][1]++;
        }
         else if(my_finger==3 && com_finger ==1){
            printf(" ---> 컴퓨터 승!\n\n");
            score[1][0]++;
            score[0][1]++;
        }
    }
    printf("컴퓨터: 이긴 횟수는 %d회, 진 횟수 %d회, 비긴횟수는 %d회 입니다.\n",score[1][0],score[1][1],score[1][2]);
	printf("사용자: 이긴 횟수는 %d회, 진 횟수 %d회, 비긴횟수는 %d회 입니다.\n",score[0][0],score[0][1],score[0][2]);
}
int main(void)
{

    int no;
    printf("Q No? > ");
    scanf("%d", &no);
    switch (no)
    {
    case 1:
        H01();
        break;
    case 2:
        H02();
        break;
    case 3:
        H03();
        break;
    default:
        break;
    }

    return 0;
}