#include <stdio.h> 
#include <string.h> 

#define max(a,b) ((a) > (b) ? (a) : (b)) // Thêm ngoặc để an toàn hơn

struct detail{
    char car_num[15]; 
    char time[50]; 
    int status; 
    int assign; 
} car[100];

// Hàm chuẩn hóa chuỗi (xóa \n cuối dòng)
void standaliseString(char* str){
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == '\r' || str[len - 1] == '\n')) {
        str[len - 1] = '\0';
        len--;
    }
}

int main()
{
    int idx = 0, num = 0; 
    // Khởi tạo mảng đếm bằng 0
    int count[100][2] = {0}; 
    // Sửa thành mảng 2 chiều để lưu danh sách biển số
    char assign[100][15]; 

    while(1){
        // Nhập biển số
        // Lỗi cũ: sizeof(car[idx]) -> Sửa: sizeof(car[idx].car_num)
        if (fgets(car[idx].car_num, sizeof(car[idx].car_num), stdin) == NULL) break;
        standaliseString(car[idx].car_num); 

        // Sửa so sánh chuỗi: dùng strcmp
        if(strcmp(car[idx].car_num, "-1") == 0){
            break; 
        }

        // Nhập thời gian
        fgets(car[idx].time, sizeof(car[idx].time), stdin); 
        standaliseString(car[idx].time); // Sửa lỗi copy-paste: car_num -> time
        
        // Nhập trạng thái
        scanf("%d", &car[idx].status); 
        getchar(); // QUAN TRỌNG: Đọc bỏ ký tự \n thừa sau scanf
        
        int check = 0, pos = -1; 
        
        // Kiểm tra xem xe này đã từng xuất hiện chưa
        // Sửa lỗi cú pháp vòng lặp: i = idx - 1 (không phải i - 1)
        for(int i = idx - 1; i >= 0 ; --i){
            if(strcmp(car[i].car_num, car[idx].car_num) == 0){
                check = 1; 
                pos = i; 
                break; 
            }
        }

        if(!check){
            // Xe mới xuất hiện lần đầu
            ++num; 
            strcpy(assign[num], car[idx].car_num); // Copy chuỗi đúng cách
            car[idx].assign = num; 
            
            // Cập nhật count cho lần đầu tiên
            count[num][car[idx].status]++;
        }
        else{
            // Xe cũ
            car[idx].assign = car[pos].assign; 
            // Cập nhật count dựa trên ID (assign) đã có
            count[car[idx].assign][car[idx].status]++;
        }
        
        ++idx; // Tăng chỉ số mảng lưu trữ
    }
    for(int i = 1 ; i <= num ; ++i){
        // In ra các xe có số lần ra (1) >= số lần vào (0) 
        // (Hoặc tùy logic bài toán của bạn)
        if(count[i][0] <= count[i][1]){
            printf("%s\n", assign[i]); // Sửa assign[num] -> assign[i]
        }
    }

    return 0;
}