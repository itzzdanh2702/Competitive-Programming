#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chuanHoa(char s[]) {
    int n = strlen(s);
    int j = 0;
    int i = 0; 

    while (i < n) {
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i == n) break;
        if (j > 0) {
            s[j++] = ' ';
        }
        s[j++] = toupper(s[i++]);
        while (i < n && s[i] != ' ') {
            s[j++] = tolower(s[i++]);
        }
    }
    s[j] = '\0';
}

int main() {
    char dsSinhVien[5][50]; 

    printf("--- NHAP DANH SACH 5 SINH VIEN ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Nhap ho ten sinh vien thu %d: ", i + 1);
        fgets(dsSinhVien[i], sizeof(dsSinhVien[i]), stdin);
        size_t len = strlen(dsSinhVien[i]);
        if (len > 0 && dsSinhVien[i][len - 1] == '\n') {
            dsSinhVien[i][len - 1] = '\0';
        }
    }
    for (int i = 0; i < 5; i++) {
        chuanHoa(dsSinhVien[i]);
    }
    printf("\n--- DANH SACH SAU KHI CHUAN HOA ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Sinh vien %d: %s\n", i + 1, dsSinhVien[i]);
    }

    return 0;
}