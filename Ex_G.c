#include <stdio.h>

void G01()
{
    int birth_year;      // 입력받은 태어난 년도
    int age[100];        // 나이
    int count_person[6]={0}; // 6종류 연령대별 인원수
    int total = 0;       // 입력된 총 인원 수
    int i;               // 반복문을 위한 변수

    for (i = 0; i < 100; i++)
    {
        printf("%d번째 사람의 태어난 년도를 입력하시오.", i + 1);
        scanf("%d", &birth_year);
        if (birth_year > 2019)
            break;
        age[i] = 2019 - birth_year + 1;
        total++;
    }
    for (i = 0; i < 100; i++)
    {   
         if (age[i] <= 0)
            break;
        printf("%d번째 사람의나이는 %d입니다.\n", i + 1, age[i]);
       
        if (age[i] < 7)
            count_person[0]++;
        else if (age[i] >= 7 && age[i] < 13)
            count_person[1]++;
        else if (age[i] >= 13 && age[i] < 20)
            count_person[2]++;
        else if (age[i] >= 20 && age[i] < 30)
            count_person[3]++;
        else if (age[i] >= 30 && age[i] < 60)
            count_person[4]++;
        else
        {
            count_person[5]++;
        }
    }
    printf("유아는 %d명 입니다\n", count_person[0]);
    printf("어린이는 %d명 입니다\n", count_person[1]);
    printf("청소년은 %d명 입니다\n", count_person[2]);
    printf("청년은 %d명 입니다\n", count_person[3]);
    printf("중년은 %d명 입니다\n", count_person[4]);
    printf("노년은 %d명 입니다\n", count_person[5]);
     printf("총 %d명 입니다\n", total);
}

void G02()
{
    int jumsu[5][3]={0};          // 5명의 3과목 점수를 저장하고 있는 2차원 배열
    int sum_student[5]={0};       // 학생별 총점
    float average_student[5]={0}; // 학생별 평균
    char grade[5]={0};            // 학생별 등급
    int sum_class[3]={0};         // 과목별 총점
    float average_class[3]={0};   // 과목별 평균
    int i, j;                 // 반복문을 위한 변수

    for (i = 0; i < 5; i++)
    {
        printf("%d 번 학생 국어, 영어, 수학 점수를 입력하시오.", i + 1);
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &jumsu[i][j]);
            sum_student[i] = sum_student[i] + jumsu[i][j];
            sum_class[j] = sum_class[j] + jumsu[i][j];
            average_class[j] = sum_class[j] / 5.0;
        }
    }
    printf("1) 각 과목별 총점과 평균 점수\n");
    printf("국어 점수의 총점은 %d 이고, 평균 점수는 %.1f 입니다.\n", sum_class[0], average_class[0]);
    printf("영어 점수의 총점은 %d 이고, 평균 점수는 %.1f 입니다.\n", sum_class[1],
           average_class[1]);
    printf("수학 점수의 총점은 %d 이고, 평균 점수는 %.1f 입니다.\n", sum_class[2],
           average_class[2]);
    printf("2) 각 학생별 총점과 평균 점수, 평균에 따른 등급\n");
    for (i = 0; i < 5; i++)
    {
        average_student[i] = sum_student[i] / 3.0;
        if (average_student[i] >= 90)
            grade[i] = 'A';
        else if (average_student[i] >= 80 && average_student[i] < 90)
            grade[i] = 'B';
        else if (average_student[i] >= 70 && average_student[i] < 80)
            grade[i] = 'C';
        else if (average_student[i] >= 60 && average_student[i] < 70)
            grade[i] = 'D';
        else if (average_student[i] < 60)
            grade[i] = 'F';
        printf("%d 번 학생의 총점은 %d 이고, 평균은 %.1f (등급 %c)입니다.\n", i + 1,
               sum_student[i], average_student[i], grade[i]);
    }
    return;
}

void G03()
{
    int hour, minute; // 이용한 시간, 분
    int charge;       // 이용료
    int total_charge; // 이용료 총액

    while (1)
    {
        printf("사용한 시간을 시간과 분으로 입력하세요 : ");
        scanf("%d %d", &hour, &minute);
        if (hour == 0 && minute == 0)
            break;
        if (0 < minute && minute <= 30)
            minute = 30;
        else if (minute > 30 && minute <= 60)
            minute = 60;
        charge = hour * 2 * 1000 + minute / 30 * 1000;
        if (hour >= 2 && hour < 3)
            charge = charge * 95 / 100;
        else if (hour >= 3 && hour < 5)
            charge = charge * 90 / 100;
        else if (hour >= 5)
            charge = charge * 80 / 100;
        printf("고객님의 이용료는 %d 원입니다.\n", charge);
        total_charge = total_charge + charge;
    }
    printf("\n 지금까지의 이용료 총금액은 %d 원입니다.", total_charge);
    return ;
}

void G04()
{
    int order[3];       // 입력받는 구매 제품 개수 (가죽장갑, 털장갑, 비닐장갑)
    int sale;           // 계산한 판매금액
    int total_sale=0;     // 총 매출액 총액
    int total_order[3]={0}; // 총 판매 개수 (가죽장갑, 털장갑, 비닐장갑)
    int i;              // 반복문을 위한 변수

    printf("세 종류의 제품(1.가죽장갑 1 만원, 2.털장갑 6 천원, 3.비닐장갑 3 천원)이 있습니다.\n\n");
    while (1)
    {
        for (i = 0; i < 3; i++)
        {
            printf("%d 번 제품은 몇 개를 구입하실래요?", i + 1);
            scanf("%d", &order[i]);
            if (order[i] == 0)
                continue;
            total_order[i] = total_order[i] + order[i];
            if (i == 0)
                sale = sale + 10000 * order[i];
            else if (i == 1)
                sale = sale + 6000 * order[i];
            else if (i == 2)
                sale = sale + 3000 * order[i];
        }
        if (order[0] == 0 && order[1] == 0 && order[2] == 0)
            break;
        total_sale = total_sale + sale;
        printf("판매 금액은 %d 원 입니다.\n", sale);
        sale = 0;
    }
    printf("지금까지 판매한 가죽장갑은 %d 개입니다.\n", total_order[0]);
    printf("지금까지 판매한 털장장갑은 %d 개입니다.\n", total_order[1]);
    printf("지금까지 판매한 비닐장갑은 %d 개입니다.\n", total_order[2]);
    printf("지금까지의 총 매출금액은 %d 원입니다.\n", total_sale);
    return ;
}

void G05()
{
    int team_count;                             // 방문한 팀수
    int charge[4] = {5000, 10000, 15000, 3000}; // 연령별 수
    int count[4]={0};                               // 입력받은 연령별 인원 수
    int v_count[4]={0};                             // 연령별 방문자 합계
    int total_count = 0;                        // 총 방문자 수
    int sum=0;                                    // 팀별 계산한 요금
    int total_sum = 0;                          // 총 요금
    int membership = 0;                         // 할인카드 종류(카드없음:0, 일반등급 카드 : 1, VIP 등급 카드 : 2)
    int i, j;                                   // 반복문을 위한 변수

    printf("오늘 방문한 팀 수를 입력하세요.");
    scanf("%d", &team_count);
    for (i = 0; i < team_count; i++)
    {
        printf("%d 번팀 인원수(초등학생, 청소년, 일반, 경로대상)를 입력하세요.", i + 1);
        scanf("%d %d %d %d", &count[0], &count[1], &count[2], &count[3]);
        for (j = 0; j < team_count; j++)
        {
            v_count[j] = v_count[j] + count[j];
            sum = sum + count[j] * charge[j];
            total_count = total_count + count[j];
        }
    printf("%d 번 팀 할인카드 종류(카드없음:0, 일반등급 : 1, VIP 등급 : 2)를입력하세요.", i+1); 
    scanf("%d", &membership);
    if(membership == 1) 
        sum = sum /100 *90;
    else if(membership==2) 
        sum = sum /100 *80;
    total_sum = total_sum + sum;
    printf("%d 번팀 입장료는 %d 입니다.\n", i+1, sum);
    sum=0;
    }
    printf("\n 오늘 총 방문자 수는 %d 명입니다.\n", total_count);
    printf("초등학생 수는 %d 명입니다.\n", v_count[0]);
    printf("청소년 수는 %d 명입니다.\n", v_count[1]);
    printf("일반인 수는 %d 명입니다.\n", v_count[2]);
    printf("경로대상 수는 %d 명입니다.\n\n", v_count[3]);
    printf("총 입장료는 %d 원입니다.", total_sum);
    return ;
}

int main(void)
{

    int no;
    printf("Q No? > ");
    scanf("%d", &no);
    switch (no)
    {
    case 1:
        G01();
        break;
    case 2:
        G02();
        break;
    case 3:
        G03();
        break;
    case 4:
        G04();
        break;
    case 5:
        G05();
        break;
    default:
        break;
    }

    return 0;
}