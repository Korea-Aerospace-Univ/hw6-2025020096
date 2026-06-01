#include <stdio.h>

int main(void) {
    //변수 선언 
    char arr[10];    // 영문자 10개를 저장할 배열
    char *p = nullptr; // 외부 for문에서 사용할 포인터를 선언하고 초기화,배열의 각 문자를 기준 문자로 하나씩 가리킴
    char *q = nullptr;  // 내부 for문에서 사용할 포인터를 선언하고 초기화,배열 전체를 돌면서 기준 문자와 비교할 때 사용
    int maxCount = 0;   // 지금까지 발견한 최대 빈도수 저장할 변수 선언(처음엔 0으로 초기화)
    char maxChar;      // 최대 빈도수를 가진 문자를 저장할 변수 선언(최종적으로 이 문자를 출력함)

    //문자 입력
    // 포인터 p를 배열 시작 주소(arr)부터 시작해서
    // arr+10 (배열 끝 다음 주소) 직전까지 p를 1칸씩 이동
    // p가 arr[0]부터  arr[9]까지를 차례로 가리킴
    for (p = arr; p < arr + 10; p++) {

        scanf("%c", p);
        // scanf는 원래 주소를 받아야 하는데 &arr[i] 와 같은 역할인 p 자체가 이미 주소이므로 p를 씀
    }


    //빈도수 계산
   
    // 외부 for문: p가 arr[0]부터 arr[9]까지 이동
    // p가 가리키는 문자(*p)를 기준 문자로 설정
    for (p = arr; p < arr + 10; p++) {

        int count = 0;
        // 기준 문자(*p)가 배열 전체에서 몇 번 나오는지 셀 임시 카운터를 지역변수로 선언 
        // p가 바뀔 때마다 새로 세야 하므로 매번 0으로 초기화해야 함

        // 내부 for문: q가 arr[0]부터 arr[9]까지 이동
        // 배열 전체를 돌면서 *p 와 *q 를 비교
        for (q = arr; q < arr + 10; q++) {

            if (*p == *q) {
                // *p : p가 현재 가리키는 문자 (기준 문자)
                // *q : q가 현재 가리키는 문자 (비교 문자)
                // 두 문자가 같으면 count를 1 증가
                count++;
            }
        }
        // 내부 for문이 끝나면 count에는
        // 기준 문자(*p)가 배열에서 총 몇 번 나왔는지 저장됨

        // count > maxCount : 초과일 때만 갱신
        // 먼저 나타난 문자(앞쪽 인덱스)가 우선순위를 가짐
        // 나중에 같은 빈도의 다른 문자가 와도 갱신 안 함
        if (count > maxCount) {
            maxCount = count;   // 최대 빈도수 업데이트
            maxChar = *p;       // 해당 문자 저장
        }

    } // 외부 for문 종료
    // 모든 문자를 기준으로 비교가 끝나면
    // maxChar = 가장 많이 나온 문자 (동일하면 먼저 나온 것)
    // maxCount = 그 문자의 빈도수


   
    //출력

    printf("%c %d", maxChar, maxCount);
    // %c : 문자 출력 → maxChar 
    // %d : 정수 출력 → maxCount 
   

    return 0;
}
