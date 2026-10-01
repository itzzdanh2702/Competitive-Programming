#include <stdio.h>
#include <string.h>
#include <ctype.h>

void maHoa(char s[], int k) {
    int n = strlen(s);
    
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) {
            char base = isupper(s[i]) ? 'A' : 'a';
            
            int currentIndex = s[i] - base;
            
            int newIndex = (currentIndex + k) % 26;
            if (newIndex < 0) {
                newIndex += 26;
            }
            
            s[i] = base + newIndex;
        }
    }
}

int main() {
    char vanBan[100];
    int k;

    printf("Nhap doan van ban can ma hoa: ");
    fgets(vanBan, sizeof(vanBan), stdin);

    size_t len = strlen(vanBan);
    if (len > 0 && vanBan[len - 1] == '\n') {
        vanBan[len - 1] = '\0';
    }
    printf("Nhap buoc dich chuyen k: ");
    scanf("%d", &k);

    maHoa(vanBan, k);
    printf("\n--- KET QUA MA HOA ---\n");
    printf("Van ban sau khi ma hoa: %s\n", vanBan);

    maHoa(vanBan, -k);
    printf("\n--- KET QUA GIAI MA (NGUOC LAI) ---\n");
    printf("Van ban sau khi giai ma: %s\n", vanBan);

    return 0;
}   