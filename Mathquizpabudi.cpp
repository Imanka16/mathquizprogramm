#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100
#define SHIFT 3
#define NUM_QUESTIONS 5   // versi sederhana 5 soal

// Fungsi untuk membuat soal matematika random
void generateQuestion(int *answer) {
    int a = rand() % 20 + 1;
    int b = rand() % 20 + 1;
    int op = rand() % 3; // 0:+ 1:- 2:*

    if(op == 0){
        *answer = a + b;
        printf("Soal: %d + %d = ?\n", a, b);
    } else if(op == 1){
        *answer = a - b;
        printf("Soal: %d - %d = ?\n", a, b);
    } else {
        *answer = a * b;
        printf("Soal: %d * %d = ?\n", a, b);
    }
}

// Fungsi Caesar cipher untuk enkripsi jawaban (angka saja)
void encryptAnswer(char str[], int shift){
    int i;
    for(i=0; str[i] != '\0'; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            str[i] = ((str[i]-'0'+shift)%10)+'0';
        }
    }
}

// Fungsi dekripsi untuk pengecekan jawaban
void decryptAnswer(char str[], int shift){
    int i;
    for(i=0; str[i] != '\0'; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            str[i] = ((str[i]-'0'-shift+10)%10)+'0';
        }
    }
}

// Fungsi main untuk kuis
int main(){
    char name[MAX];
    int choice;
    srand(time(NULL));

    printf("Masukkan nama: ");
    scanf("%s", name);

    do{
        printf("\n=== Math Quiz Game ===\n");
        printf("1. Mulai Kuis\n2. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        if(choice == 1){
            int score = 0;
            int correctAnswer;
            char userAnswer[MAX];
            int i;
            for(i=0; i<NUM_QUESTIONS; i++){
                generateQuestion(&correctAnswer);
                printf("Jawabanmu: ");
                scanf("%s", userAnswer);

                encryptAnswer(userAnswer, SHIFT);
                char temp[MAX];
                strcpy(temp, userAnswer);
                decryptAnswer(temp, SHIFT);

                if(atoi(temp) == correctAnswer){
                    printf("Jawaban benar!\n");
                    score++;
                } else {
                    printf("Jawaban salah. Jawaban benar: %d\n", correctAnswer);
                }
            }
            printf("Kuis selesai! Skor kamu: %d/%d\n", score, NUM_QUESTIONS);
        } else if(choice == 2){
            printf("Terima kasih telah bermain!\n");
        } else {
            printf("Pilihan tidak valid.\n");
        }

    } while(choice != 2);

    return 0;
	}

 

