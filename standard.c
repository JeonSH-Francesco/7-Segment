#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 3

// 7-segment 디스플레이를 위한 문자 매핑
const char* seven_segment[] = {
    " _ | ||_|", // 0
    "     |  |", // 1
    " _  _||_ ", // 2
    " _  _| _|", // 3
    "   |_|  |", // 4
    " _ |_  _|", // 5
    " _ |_ |_|", // 6
    " _   |  |", // 7
    " _ |_||_|", // 8
    " _ |_| _|", // 9
};

void print_7_segment(const char* input) {
    char line1[50] = { 0 }, line2[50] = { 0 }, line3[50] = { 0 };

    // 입력된 숫자에 따라 7-segment 형태로 출력 줄 생성
    for (int i = 0; input[i] != '\0'; i++) {
        int digit = input[i] - '0';
        const char* segment = seven_segment[digit];

        // 각 줄에 해당하는 부분 추가
        strncat(line1, segment, 3); // 윗줄
        strcat(line1, " ");        // 간격
        strncat(line2, segment + 3, 3); // 중간줄
        strcat(line2, " ");        // 간격
        strncat(line3, segment + 6, 3); // 아랫줄
        strcat(line3, " ");        // 간격
    }

    // 결과 출력
    printf("%s\n%s\n%s\n", line1, line2, line3);
}

int main() {
    char input[MAX_DIGITS + 1];

    printf("0-9 사이의 숫자 최대 세 개를 입력하세요: ");
    scanf("%3s", input);

    // 입력 검증 (숫자인지 확인)
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] < '0' || input[i] > '9') {
            printf("잘못된 입력입니다. 숫자만 입력해주세요.\n");
            return 1;
        }
    }

    // 7-세그먼트 출력
    print_7_segment(input);

    return 0;
}
