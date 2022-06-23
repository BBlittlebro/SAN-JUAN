#include "card.h"

void player_select(int governor){       //每個角色選擇動作
    int _option = 0;

    if(governor == 0){      //第一個抽(0123)
        while(1){           
            show_role(role);
            scanf("%d", &_option);
            if(_option >= 6){
                action(_option, players[0].id);
            }else{
                action(_option, players[0].id);            
                break;
            }
        }
        for(int i = 1; i < 4; i++){
            srand(time(NULL));
            while(1){
                int x = (rand() % 5 );      //0~4
                if(role[x] == 1){
                    action(x+1, players[i].id);            //1~5
                    break;
                }
            }
        }
    }
    else if(governor == 1){        //最後一個抽(1230)
        for(int i = 1; i < 4; i++){
            srand(time(NULL));
            while(1){
                int x = (rand() % 5 );      //0~4
                if(role[x] == 1){
                    action(x+1, players[i].id);            //1~5
                    break;
                }
            }
        }
        while(1){           
            show_role(role);
            scanf("%d", &_option);
            if(_option >= 6){
                action(_option, players[0].id);
            }else{
                action(_option, players[0].id);            
                break;
            }
        }
    }
    else if(governor == 2){         //(2301)
        for(int i = 2; i < 4; i++){
            srand(time(NULL));
            while(1){
                int x = (rand() % 5 );      //0~4
                if(role[x] == 1){
                    action(x+1, players[i].id);            //1~5
                    break;
                }
            }
        }
        while(1){           
            show_role(role);
            scanf("%d", &_option);
            if(_option >= 6){
                action(_option, players[0].id);
            }else{
                action(_option, players[0].id);            
                break;
            }
        }
        srand(time(NULL));
        while(1){
            int x = (rand() % 5 );      //0~4
            if(role[x] == 1){
                action(x+1, players[1].id);            //1~5
                break;
            }
        }
    }
    else if(governor == 3){         //(3012)
        srand(time(NULL));
        while(1){
            int x = (rand() % 5 );      //0~4
            if(role[x] == 1){
                action(x+1, players[3].id);            //1~5
                break;
            }
        }
        while(1){           
            show_role(role);
            scanf("%d", &_option);
            if(_option >= 6){
                action(_option, players[0].id);
            }else{
                action(_option, players[0].id);            
                break;
            }
        }
        for(int i = 1; i < 3; i++){
            srand(time(NULL));
            while(1){
                int x = (rand() % 5 );      //0~4
                if(role[x] == 1){
                    action(x+1, players[i].id);            //1~5
                    break;
                }
            }
        }
    }
}

int main(){

    printf("~~~ San Juan ~~~\n");
    while(1){
        int start = 0;
        printf("1: Start Game, 2: Exit\n");
        scanf("%d", &start);
        if(start == 1){
            break;
        }else if (start == 2){
            printf("Thanks for your gaming.\n");
            return 0 ;
        }else{
            printf("What you entered wrong!\n");
        }
    }

    init_card_stack(card_stack);
    init_player(players);
    init_product_value(product_value);

    int governor = 0;       //0號玩家先當
    int gameover = 0;

    while(!gameover){
        for(int i = 0; i < 4; i++){
            printf("======New round!!!======\n");
            memset(role, 1, 5);                         //初始化角色
            for(int j = 0; j < 4; j++){                 //確認手排是否超過上限 & 是否遊戲結束
                gameover = check_win(j);
                int temp = count_cards_inhand(j);
                int _tower = Tower(j);
                if(_tower == 1){
                    if(temp > 12){
                        discard(j, temp - 12);
                    }
                }else{
                    if(temp > 7){
                        discard(j, temp - 7);
                    }
                }
            }
            if(gameover == 1){
                break;        
            }
            player_select(governor);
            governor++;
        }
        governor = 0;
    }

    int winner = 0;
    int max = 0;
    int grade = 0;
    printf("======GAME OVER=======\n");
    for(int i = 0; i < 4; i++){
        grade = count_point(i);
        printf("Player%d has %d point.\n", i+1, grade);
        if(grade > max){
            max = grade;
            winner = i+1;
        }
    }
    printf("\n");
    printf("Winner is Player%d!!!!!!\n", winner);
    

    return 0;
}