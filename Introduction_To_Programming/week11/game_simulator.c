#include<stdio.h> 
#include<time.h> 
#include<stdlib.h>

struct player { 
    char name[100]; 
    float str,spd,hp; 
    // strength,speed,health point; 
}; 

void input(int i,struct player *Player){
    printf("====================The information of the player %d====================\n",i); 
    printf("Enter the name of player %d: ",i);
    scanf("%s",(Player -> name)); 
    getchar(); 
    printf("Enter the strength of player %d (250 <= index <= 300): ",i);
    scanf("%f",(&Player -> str)); 
    printf("Enter the speed of player %d: ",i);
    scanf("%f",(&Player -> spd)); 
    printf("Enter the health point of player %d (1500 <= index <= 2000): ",i);
    scanf("%f",(&Player -> hp)); 
    printf("\n"); 
}

int first_attack(float spd_a,float spd_b){
    if(spd_a > spd_b){
        return 1; 
    } 
    else if (spd_a < spd_b){
        return 0; 
    }
    else{
        int k = rand() % 2 + 1; 
        if(k == 1){
            return 1; 
        }
        else return 0; 
    }
}

void result(struct player *p1,struct player *p2,int end_turn){
    printf("====================RESULT====================\n");
    printf("%s is the winner!\n",p1 -> name);
    float bonus = 0;  
    if(end_turn <= 5){
        bonus = 0.1;
    }
    else if (end_turn > 10){
        bonus = 0.05;
    }
    else{
        bonus = 0.025; 
    } 
    printf("%s is added 2%% (fixed) + %.1f %% bonus\n",p1 -> name,bonus * 100); 
    bonus += 0.02;
    p1 -> str *= (1 + bonus); 
    p1 -> spd *= (1 + bonus); 
    p1 -> hp *= (1 + bonus);
    printf("%s after match: Strength: %.0f | Speed: %.0f | Health point: %.0f\n",p1 -> name,p1 -> str,p1 -> spd,p1 -> hp);
    printf("%s is added 1%%\n",p2 -> name); 
    p2 -> str *= 1.01; 
    p2 -> spd *= 1.01; 
    p2 -> hp *= 1.01; 
    printf("%s after match: Strength: %.0f | Speed: %.0f | Health point: %.0f\n",p2 -> name,p2 -> str,p2 -> spd,p2 -> hp); 
    return;   
}

void arena(int match,struct player *p1,struct player *p2){
    printf("========================================MATCH %d========================================\n",match); 
    printf("This is the match between %s and %s!\n",p1 -> name,p2 -> name); 
    int cnt = 0,fi_atk = 1; 
    struct player fi,se;
    if(first_attack(p1 -> spd,p2 -> spd)){  
        fi = *p1;
        se = *p2; 
        fi_atk = 1; 
    }
    else{
        fi = *p2;
        se = *p1; 
        fi_atk = 2; 
    }
    while(fi.hp > 0 && fi.hp > 0){ 
        printf("====================TURN %d====================\n",++cnt); 
        printf("%s inflicts %.0f HP damage to the enemy. %s has %.0f HP left\n",fi.name,fi.str,se.name,se.hp - fi.str);
        se.hp -= fi.str;
        if(se.hp <= 0){
            if(fi_atk == 1){
                result(p1,p2,cnt); 
            }
            else{
                result(p2,p1,cnt); 
            }
            break; 
        }
        printf("%s executes a counter attack dealing %.0f HP damage to the enemy. %s has %.0f HP left\n",se.name,se.str,fi.name,fi.hp - se.str);
        fi.hp -= se.str; 
        if(fi.hp <= 0){
            if(fi_atk == 1){
                result(p2,p1,cnt); 
            }
            else{
                result(p1,p2,cnt); 
            }
            break; 
        }
    }
}

int main()
{
    int match = 0; 
    srand(time(NULL)); 
    struct player p1,p2,p3; 
    input(1,&p1); 
    input(2,&p2); 
    input(3,&p3);
    arena(++match,&p1,&p2);
    ++match;  
    arena(++match,&p2,&p3);
    ++match; 
    arena(++match,&p3,&p1); 
}