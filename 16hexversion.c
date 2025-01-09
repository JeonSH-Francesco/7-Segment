#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 7-세그먼트의 16진수 매핑 (a-g, dp 비트 포함)
const int segment_map[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

// 특정 비트를 확인하는 매크로
#define CHECK_BIT(value, bit) ((value >> bit) & 1)

// 7-세그먼트를 콘솔로 출력
void print_segment(int digit) {
    if (digit < 0 || digit > 9) return;
    int code = segment_map[digit];

    printf(" %c \n", CHECK_BIT(code, 6) ? '_' : ' '); // a
    printf("%c%c%c\n",
           CHECK_BIT(code, 5) ? '|' : ' ', // f
           CHECK_BIT(code, 6) ? '_' : ' ', // g
           CHECK_BIT(code, 1) ? '|' : ' '); // b
    printf("%c%c%c\n",
           CHECK_BIT(code, 4) ? '|' : ' ', // e
           CHECK_BIT(code, 3) ? '_' : ' ', // d
           CHECK_BIT(code, 2) ? '|' : ' '); // c
}

int main() {
    int number;
    printf("0-9 사이의 숫자를 입력하세요: ");
    scanf("%d", &number);

    if (number >= 0 && number <= 9) {
        print_segment(number);
    } else {
        printf("0-9 사이의 숫자만 입력하세요.\n");
    }

    return 0;
}
