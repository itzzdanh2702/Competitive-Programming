#include<stdio.h>
#include<string.h>
#include<ctype.h>

const int num_of_question = 5;
const int num_of_Candidate = 5;

typedef struct{
    char statement[50];
    char first_choice[50],second_choice[50],third_choice[50];
    int correct_ans;
}question;

typedef struct{
    int choice_question_1,choice_question_2,choice_question_3,choice_question_4,choice_question_5;
}answer;

typedef struct{
    int order,point;
}result;

result res[5];
question quest[5];
answer ans[5];

int main(){
    printf("==============================QUESTION==============================\n");
    for(int i = 0 ; i < num_of_question ; ++i){
        printf("QUESTION %d:",i + 1);
        fgets(quest[i].statement,sizeof(quest[i].statement),stdin);
        quest[i].statement[strcspn(quest[i].statement,"\r\n")] = '\0';
        printf("1)");
        fgets(quest[i].first_choice,sizeof(quest[i].first_choice),stdin);
        quest[i].first_choice[strcspn(quest[i].first_choice,"\r\n")] = '\0';
        printf("2)");
        fgets(quest[i].second_choice,sizeof(quest[i].second_choice),stdin);
        quest[i].second_choice[strcspn(quest[i].second_choice,"\r\n")] = '\0';
        printf("3)");
        fgets(quest[i].third_choice,sizeof(quest[i].third_choice),stdin);
        quest[i].third_choice[strcspn(quest[i].third_choice,"\r\n")] = '\0';
        scanf("%d",&quest[i].correct_ans);
        getchar();
    }
    int point[5];
    printf("==============================ANSWER==============================\n");
    for(int i = 0 ; i < num_of_Candidate ; ++i){
        printf("The answer of candidate %d:", i + 1);
        scanf("%d %d %d %d %d",&ans[i].choice_question_1,&ans[i].choice_question_2,&ans[i].choice_question_3,&ans[i].choice_question_4,&ans[i].choice_question_5);
        if(ans[i].choice_question_1 == quest[0].correct_ans){
            ++res[i].point;
        }
        if(ans[i].choice_question_2 == quest[1].correct_ans){
            ++res[i].point;
        }
        if(ans[i].choice_question_3 == quest[2].correct_ans){
            ++res[i].point;
        }
        if(ans[i].choice_question_4 == quest[3].correct_ans){
            ++res[i].point;
        }
        if(ans[i].choice_question_5 == quest[4].correct_ans){
            ++res[i].point;
        }
    }
    printf("==============================RESULT==============================\n");
    for(int i = 0 ; i < num_of_Candidate ; ++i){
        res[i].order = i + 1;
    }
    for(int i = 1 ; i < num_of_Candidate ; ++i){
        for(int j = 0 ; j < i ; ++j){
            if(res[i].point < res[j].point){
                result tmp;
                tmp = res[i];
                res[i] = res[j];
                res[j] = tmp;
            }
        }
    }
    printf("The result of the exam: \n");
    for(int i = 0 ; i < num_of_Candidate ; ++i){
        printf("Rank %d:",i + 1);
        printf("Candidate %d with %d/5 correct answer(s)\n",res[i].order,res[i].point);
    }
    return 0;
}
