#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _player{
    uint8_t id;
    uint8_t building[12];
    uint8_t in_hand[20];
    uint8_t product[5];
    uint8_t point;
} player;

typedef struct _card{
    uint8_t id;
    char name[200];
    uint8_t cost;
    uint8_t point;
    uint8_t use; //if using: 1,  not using: 0, have product: 2 
} card;

player players[4];

card card_stack[110];
uint8_t product_value[5][5] =  {1,2,2,3,3,
                                1,1,2,2,3,
                                1,2,2,2,3,
                                1,1,1,2,2,
                                1,1,2,2,2};
uint8_t governor = 0;
uint8_t role[5] = {1, 1, 1, 1, 1}; // 1:Builder, 2:Producer, 3:Trader, 4:Councilor, 5:Prospector

void Smithy(int id, int *cost);
void Market_stand(int id);
void Well(int id);
int Tower(int id);
void Aquduect(int id, int *total);
void Trading_post(int id, int *total);

void init_card_stack(card card_stack[]){            //0 ~ 109
    int n = 0;
    for(int i = 0; i < 10; i++){            //0-9
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Indigo plant(1/1) - Producer phase: owner produces 1 indigo.");
        card_stack[n].cost = 1;
        card_stack[n].point = 1;
        if(i < 4)       //一開始就發了
            card_stack[n].use = 1;
        else
            card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 8; i++){         //10-17
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Sugar Mill(2/1) - Producer phase: owner produces 1 sugar.");
        card_stack[n].cost = 2;
        card_stack[n].point = 1;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 8; i++){         //18-25
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Tobacco storage(3/2) - Producer phase: owner produces 1 tobacco.");
        card_stack[n].cost = 3;
        card_stack[n].point = 2;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 8; i++){         //26-33
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Coffee roaster(4/2) - Producer phase: owner produces 1 coffee.");
        card_stack[n].cost = 4;
        card_stack[n].point = 2;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 8; i++){         //34-41
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Silver smelter(5/3) - Producer phase: owner produces 1 silver.");
        card_stack[n].cost = 5;
        card_stack[n].point = 3;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //42-44
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Tower(3/2) - Governor phase: owner may have to 12 cards in his hand.");
        card_stack[n].cost = 3;
        card_stack[n].point = 2;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //45-47
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Smithy(1/1) - Builder phase: owner pays 1 card less when building production building.");
        card_stack[n].cost = 1;
        card_stack[n].point = 1;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //48-50
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Gold Mine(1/1) - Prospector phase: owner turns up 4 cards from the supply. If all have different building cost, he may add one to his hand.");
        card_stack[n].cost = 1;
        card_stack[n].point = 1;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //51-53
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Archive(1/1) - Councilor phase: owner may discard hand card in addition to drawn cards.");
        card_stack[n].cost = 1;
        card_stack[n].point = 1;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //54-56
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Poor house(2/1) - Builder phase: owner takes 1 card from supply if he has 0 or 1 card after building.");
        card_stack[n].cost = 2;
        card_stack[n].point = 1;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //57-59
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Black Market(2/1) - Builder phase: owner may discard any 1 or 2 goods and reduce the building cost by 1 or 2 cards.");
        card_stack[n].cost = 2;
        card_stack[n].point = 1;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //60-62
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Trading Post(2/1) - Trader phase: owner may sell 1 additional good.");
        card_stack[n].cost = 2;
        card_stack[n].point = 1;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //63-65
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Well(2/1) - Producer phase: owner takes 1 card from supply when he produces at least 2 goods.");
        card_stack[n].cost = 2;
        card_stack[n].point = 1;
        card_stack[n].use = 0;
        n++;
    }       
    for(int i = 0; i < 3; i++){         //66-68
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Market Stand(2/1) - Trader phase: owner takes 1 card from supply when he sells at least 2 goods.");
        card_stack[n].cost = 2;
        card_stack[n].point = 1;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //69-71
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Crane(2/1) - Builder phase: owner may build over one of his buildings.(and pay the difference.");
        card_stack[n].cost = 2;
        card_stack[n].point = 1;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //72-74
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Chapel(3/2+?) - Governor phase: owner may place 1 hand card under his chapel.(each worth 1 point at game end)");
        card_stack[n].cost = 3;
        card_stack[n].point = 2;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //75-77
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Aquaduct(3/2) - Producer phase: owner produce one good more.");
        card_stack[n].cost = 3;
        card_stack[n].point = 2;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //78-80
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Carpenter(3/2) - Builder phase: owner takes 1 card from supply after he builds a violet building.");
        card_stack[n].cost = 3;
        card_stack[n].point = 2;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //81-83
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Prefecture(3/2) - Councilor phase: owner keeps 1 card more from those drawn.");
        card_stack[n].cost = 3;
        card_stack[n].point = 2;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //84-86
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Market Hall(4/2) - Trader phase: owner takes 1 card more for selling 1 good.");
        card_stack[n].cost = 4;
        card_stack[n].point = 2;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //87-89
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Quarry(4/2) - Builder phase: owner pays 1 card less when building violet building.");
        card_stack[n].cost = 4;
        card_stack[n].point = 2;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //90-92
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Library(5/3) - All phases: owner uses the privilege of his role twice.");
        card_stack[n].cost = 5;
        card_stack[n].point = 3;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //93-95
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Statue(3/3) - Monument");
        card_stack[n].cost = 3;
        card_stack[n].point = 3;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //96-98
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Victory Column(4/4) - Monument");
        card_stack[n].cost = 4;
        card_stack[n].point = 4;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 3; i++){         //99-101
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Hero(5/5) - Monument");
        card_stack[n].cost = 5;
        card_stack[n].point = 5;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 2; i++){         //102-103
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Guild Hall(6/?) - At game end: owner earns 2 additional point for each of his production buildings.");
        card_stack[n].cost = 6;
        card_stack[n].point = 0;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 2; i++){         //104-105
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "City Hall(6/?) - At game end: owner earns 1 additional point for each of his violet building.");
        card_stack[n].cost = 6;
        card_stack[n].point = 0;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 2; i++){         //106-107
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Triumphal Arch(6/?) - At game end: owner earns additional 4-6-8 point for 1-2-3 monuments.");
        card_stack[n].cost = 6;
        card_stack[n].point = 0;
        card_stack[n].use = 0;
        n++;
    }
    for(int i = 0; i < 2; i++){         //108-109
        card_stack[n].id = n;
        strcpy(card_stack[n].name, "Palace(6/?) - At game end: owner earns 1 additional point for every 4 point he has earned.");
        card_stack[n].cost = 6;
        card_stack[n].point = 0;
        card_stack[n].use = 0;
        n++;
    }
}

void init_product_value(uint8_t product_value[][5]){            //還沒寫
    for(int j = 0; j < 5; j++){
        for(int i = 0; i < 5; i++){
            
        }
    }
}

int random_choose(card card_stack[]){
    srand(time(NULL));
    while(1){
        int x = rand() % 110;
        if(card_stack[x].use == 0){
            card_stack[x].use = 1;
            return x;
        }
    }
}

int count_cards_inhand(int id){
    int n = 0;
    for(int i = 0; i < 20; i++){
        if(players[id].in_hand[i] != 255){
            n++;
        }
    }
    return n;
}

void init_player(player players[]){
    for(int i = 0; i < 4; i++){
        players[i].id = i;
        for(int j = 0; j < 20; j++){
            players[i].building[j] = 255;       //用255當不可能
            players[i].in_hand[j] = 255;
        }
        players[i].point = 0;
        for(int j = 0; j < 5; j++){
            players[i].product[j] = 0;
        }
        for(int j = 0; j < 4; j++){             //每位玩家抽4張牌
            players[i].in_hand[j] = random_choose(card_stack);
        }
        players[i].building[0] = i;             //每位玩家一級工廠
    }
}

void show_card(){             //0~20
    printf("You have these card(s): \n");
    for(int i = 0; i < 20; i++){
        if(players[0].in_hand[i] != 255){
            printf("%d: %s\n", i, card_stack[players[0].in_hand[i]].name);
        }
    }
}

void discard(int id, int discard_total){
    int temp = 255;
    if(id == 0){
        printf("You need to discard your cards to keep 7 at most.\n");
        printf("If you have (Tower), you can have 12 cards at most.\n");
        for(int i = 0; i < discard_total; i++){
            printf("Please select the card that you want to discard.\n");
            show_card();
            scanf("%d", &temp);
            for(int j = 0; j < 20; j++){
                if(temp == j){
                    players[0].in_hand[j] = 255;
                    card_stack[players[0].in_hand[j]].use = 0;      //重新放入排堆
                    break;
                }
            }
        }
    }
    else{
        for(int i = 0; i < discard_total; i++){
            for(int j = 19; j >= 0; j--){           //從後面丟牌
                if(players[id].in_hand[j] != 255){
                    players[id].in_hand[j] = 255;
                    card_stack[players[id].in_hand[j]].use = 0;
                    break;
                }
            }
        }
    }
}

int count_point(int id){
    int total = 0;
    for(int i = 0; i < 12; i++){
        total += card_stack[players[id].building[i]].point;
    }
    return total;
}

int check_win(int id){
    for(int i = 0; i < 12; i++){
        if(players[id].building[i] == 255){
            return 0;
        }
    }
    return 1;
}

void show_building(int who){        //1: self,  0: everyone
    if(who == 1){
        printf("You have these building(s): \n");
        for(int i = 0; i < 12; i++){
            if(players[0].building[i] != 255)
                printf("%d: %s\n", i, card_stack[players[0].building[i]].name);
        }
    }else if(who == 0){
        printf("You have these building(s): \n");
        for(int i = 0; i < 12; i++){
            if(players[0].building[i] != 255)
                printf("%d: %s\n", i, card_stack[players[0].building[i]].name);
        }
        printf("Player2 have these building(s): \n");
        for(int i = 0; i < 12; i++){
            if(players[1].building[i] != 255)
                printf("%d: %s\n", i, card_stack[players[1].building[i]].name);
        }
        printf("Player3 have these building(s): \n");
        for(int i = 0; i < 12; i++){
            if(players[2].building[i] != 255)
                printf("%d: %s\n", i, card_stack[players[2].building[i]].name);
        }
        printf("Player4 have these building(s): \n");
        for(int i = 0; i < 12; i++){
            if(players[3].building[i] != 255)
                printf("%d: %s\n", i, card_stack[players[3].building[i]].name);
        }
    }
}

void show_product(int who){         //1: self,  0:everyone
    if(who == 1){
        printf("\n");
        printf("0: You have %d indigo(s).\n", players[0].product[0]);       
        printf("1: You have %d sugar(s).\n", players[0].product[1]);
        printf("2: You have %d tobacco(s).\n", players[0].product[2]);
        printf("3: You have %d coffee(s).\n", players[0].product[3]);    
        printf("4: You have %d silver(s).\n", players[0].product[4]);

    }else if(who == 0){
        printf("\n");
        printf("You have these product(s): \n");
        printf("%d indigo(s).\n", players[0].product[0]);       
        printf("%d sugar(s).\n", players[0].product[1]);
        printf("%d tobacco(s).\n", players[0].product[2]);
        printf("%d coffee(s).\n", players[0].product[3]);    
        printf("%d silver(s).\n", players[0].product[4]);

        for(int i = 1; i < 4; i++){
            printf("\n");
            printf("Player%d has these product(s): \n", i+1);
            printf("%d indigo(s).\n", players[i].product[0]);       
            printf("%d sugar(s).\n", players[i].product[1]);
            printf("%d tobacco(s).\n", players[i].product[2]);
            printf("%d coffee(s).\n", players[i].product[3]);    
            printf("%d silver(s).\n", players[i].product[4]);
        }
    }
    
}

void show_role(uint8_t role[]){
    printf("\n");
    if(role[0] == 1)
        printf("1:Builder, ");
    if(role[1] == 1)
        printf("2:Producer, ");
    if(role[2] == 1)
        printf("3:Trader, ");
    if(role[3] == 1)
        printf("4:Councilor, ");
    if(role[4] == 1)
        printf("5:Prospector, ");
    printf("6:Show hand, ");
    printf("7:Show Building, ");
    printf("8:Show products ");
}

int check_if_repeat(int card_num){          //1: already built, 0: can built
    int temp = 0;
    for(int i = 0; i < 12; i++){
        if(strcmp(card_stack[players[0].building[i]].name, card_stack[card_num].name) == 0){
            printf("You already build this building.\n");
            temp = 1;
            break;
        }
    }
    return temp;
}

void builder(int id){
    int pick = 0;
    int cost = 0;
    int card_num = 255;

    if(role[0] == 1){
        role[0] = 0;
    }else{
        printf("That role has been choosed.\n");
        return;
    }

    if(id == 0){                         //玩家
        while(1){
            cost = -1;
            
            printf("Choose a card that you want to build, ");
            show_card();
            printf("-1: I don't want to build.\n");
            scanf("%d", &pick);

            if(pick == -1){
                return;
            }else if(pick >= 20 || pick < 0){      //強制轉換為錯的
                pick = 20;
            }

            card_num = players[id].in_hand[pick];
            cost += card_stack[card_num].cost;

            if(card_num == 255){
                printf("You can't choose that card.\n");
            }else if(cost >= count_cards_inhand(id)){           //沒有特權，不夠支付。
                printf("You can't pay the cost.\n");
            }else if (card_num > 41){       //檢查工廠以外
                int temp = check_if_repeat(card_num);  
                if(temp == 0)
                    break;
            }else{
                Smithy(id, &cost);
                break;
            }
        }
        if(cost <= 0){
            cost = 0;
        }
        players[id].in_hand[pick] = 255;     //要蓋的從手牌裡消失
        
        for(int i = 0; i < cost; i++){               //可以建造的
            while(1){
                printf("Choose cards that you want to cost, ");
                show_card();
                scanf("%d", &pick);
                if(players[id].in_hand[pick] == 255){
                    printf("You can't choose that card.\n");
                }else{
                    break;
                }
            }
            players[id].in_hand[pick] = 255;
        }
        for(int i = 0; i < 12; i++){            //檢查哪一個建築物是空的
            if(players[id].building[i] == 255){
                players[id].building[i] = card_num;
                break;
            }
        }
    }
    else{                                      
        printf("Players%d select builder.\n", id+1);

        while(1){                   //玩家還是要建造
            printf("Choose a card that you want to build, ");
            show_card();
            printf("-1: I don't want to build.\n");
            scanf("%d", &pick);

            if(pick == -1){
                return;
            }else if(pick >= 20 || pick < 0){      //強制轉換為錯的(不可能拿到20張吧)
                pick = 20;
            }
            cost = 0;
            card_num = players[0].in_hand[pick];
            cost += card_stack[card_num].cost;

            if(card_num == 255){
                printf("You can't choose that card.\n");
            }else if(cost >= count_cards_inhand(0)){           //沒有特權，不夠支付。
                printf("You can't pay the cost.\n");
            }else if (card_num > 41){       //檢查工廠以外
                int temp = check_if_repeat(card_num);  
                if(temp == 0)
                    break; 
            }else{
                break;
            }
        }
        players[0].in_hand[pick] = 255;     //要蓋的從手牌裡消失
        
        for(int i = 0; i < cost; i++){               //可以建造的
            while(1){
                printf("Choose cards that you want to cost, ");
                show_card();
                scanf("%d", &pick);
                if(players[0].in_hand[pick] == 255){
                    printf("You can't choose that card.\n");
                }else{
                    break;
                }
            }
            players[0].in_hand[pick] = 255;
        }
        for(int i = 0; i < 12; i++){            //檢查哪一個建築物是空的
            if(players[0].building[i] == 255){
                players[0].building[i] = card_num;
                break;
            }
        }
    }
    for(int k = 1; k < 4; k++){
        cost = 0;
        if(id == k){
            cost = -1;
        }
        while(1){       //電腦玩家，隨機選牌，不能建就跳過
            srand(time(NULL));
            pick = (rand() % count_cards_inhand(k) );      //0~手牌數  不一定從0開始都有

            if(pick == -1){
                return;
            }else if(pick >= 20 || pick < 0){      //強制轉換為錯的
                pick = 20;
            }

            card_num = players[k].in_hand[pick];
            cost += card_stack[card_num].cost;

            if(card_num == 255){
                return;
            }else if(cost >= count_cards_inhand(k)){           //沒有特權，不夠支付。
                return;
            }else if (card_num > 41){       //檢查工廠以外
                int temp = check_if_repeat(card_num);  
                if(temp == 0)
                    break;
                else
                    return;
            }else{
                break;
            }
        }
        players[k].in_hand[pick] = 255;     //要蓋的從手牌裡消失
        

        for(int i = 0; i < cost; i++){               //花費
            for(int j = 0; j < 20; j++){
                if(players[k].in_hand[j] != 255){
                    players[k].in_hand[j] = 255;
                    break;
                }
            }
        }
        for(int i = 0; i < 12; i++){            //檢查哪一個建築物是空的
            if(players[k].building[i] == 255){
                players[k].building[i] = card_num;
                break;
            }
        }
    }
}

void producer_add(int card_num, int who){           //有消失的牌，先關掉
    if(who == 0){
        switch (card_stack[card_num].cost)
        {
        case 1:
            printf("You produces a indigo.\n");
            //random_choose(card_stack);      //消失的牌，
            players[who].product[0]++;
            break;
        case 2:
            printf("You produces a sugar.\n");
            //random_choose(card_stack);
            players[who].product[1]++;
            break;
        case 3:
            printf("You produces a tobacco.\n");
            //random_choose(card_stack);
            players[who].product[2]++;
            break;
        case 4:
            printf("You produces a coffee.\n");
            //random_choose(card_stack);
            players[who].product[3]++;
            break;
        case 5:
            printf("You produces a silver.\n");
            //random_choose(card_stack);
            players[who].product[4]++;
            break;
        default:
            printf("No factory can produce!!\n");
            break;
        }
    }
    else{
        switch (card_stack[card_num].cost)
        {
        case 1:
            random_choose(card_stack);
            players[who].product[0]++;
            break;
        case 2:
            random_choose(card_stack);
            players[who].product[1]++;
            break;
        case 3:
            random_choose(card_stack);
            players[who].product[2]++;
            break;
        case 4:
            random_choose(card_stack);
            players[who].product[3]++;
            break;
        case 5:
            random_choose(card_stack);
            players[who].product[4]++;
            break;
        default:
            printf("No factory can produce!!\n");
            break;
        }
    }
    
}

void producer(int id){
    int pick = 0;
    int card_num = 255;
    int pro_total = 1;
    int real_total = 0;

    if(role[1] == 1){
        role[1] = 0;
    }else{
        printf("That role has been choosed.\n");
        return;
    }

    if(id == 0){
        pro_total = 2;
        Aquduect(0, &pro_total);
        
        for(int i = 0; i < pro_total; i++){
            while(1){
                printf("Choose a factory that you want to produce, ");      //沒特權，只生產一個
                show_building(1);
                printf("-1: I don't want to produce.\n");
                scanf("%d", &pick);

                if(pick == -1)
                    return;

                card_num = players[id].building[pick];
                if(card_num >= 42){
                    printf("That is not a factory.\n");
                }else if(card_stack[card_num].use == 2){
                    printf("That factory already has a product.\n");
                }else{
                    real_total++;
                    card_stack[card_num].use = 2;   //有貨物中
                    producer_add(card_num, 0);
                    break;
                }
            }
        }
        if(real_total >= 2){
            Well(id);
        }
    }
    else{
        printf("Players%d select producer.\n", id+1);       //玩家還是要生產

        Aquduect(0, &pro_total);
        for(int i = 0; i < pro_total; i++){
            while(1){
                printf("Choose a factory that you want to produce, ");      //沒特權，只生產一個
                show_building(1);
                printf("-1: I don't want to produce.\n");
                scanf("%d", &pick);

                if(pick == -1)
                    return;

                card_num = players[0].building[pick];
                if(card_num >= 42){
                    printf("That is not a factory.\n");
                }else if (card_stack[card_num].use == 2){
                    printf("That factory already has a product.\n");
                }else if (card_stack[card_num].use == 1){
                    card_stack[card_num].use = 2;   //有貨物中
                    producer_add(card_num, 0);
                    break;
                }
            }
        }
    }

    for(int k = 1; k < 4; k++){
        if(id == k){         //有特權
            while(1){                  
                for(int i = 0; i < 12; i++){
                    if(players[k].building[i] != 255 && card_stack[players[k].building[i]].use == 1 && players[k].building[i] <= 41){
                        card_num = players[k].building[i];
                        card_stack[card_num].use = 2;
                        producer_add(card_num, k);
                        break;
                    }
                }
                break;
            }
            while(1){                   
                for(int i = 0; i < 12; i++){
                    if(players[k].building[i] != 255 && card_stack[players[k].building[i]].use == 1 && players[k].building[i] <= 41){
                        card_num = players[k].building[i];
                        card_stack[card_num].use = 2;
                        producer_add(card_num, k);
                        break;
                    }
                }
                break;
            }
        }else{
            while(1){               //沒特權           
                for(int i = 0; i < 12; i++){
                    if(players[k].building[i] != 255 && card_stack[players[k].building[i]].use == 1 && players[k].building[i] <= 41){
                        card_num = players[k].building[i];
                        card_stack[card_num].use = 2;
                        producer_add(card_num, k);
                        break;
                    }
                }
                break;
            }
        }
    }
}

void trader_addcard(int total, int who){
    for(int i = 0; i < total; i++){
        int temp = random_choose(card_stack);
        for(int j = 0; j < 20; j++){
            if(players[who].in_hand[j] == 255){
                players[who].in_hand[j] = temp;
                break;
            }
        }
    }
}

void trader(int id){
    int pick = 0;
    int sell_total = 1;
    int real_total = 0;
    srand(time(NULL));
    int x = (rand() % 5 );      //0~4
                

    if(role[2] == 1){
        role[2] = 0;
    }else{
        printf("That role has been choosed.\n");
        return;
    }

    if(id == 0){
        printf("=> Product Value in this turn.\n");
        for(int i = 0; i < 5; i++){
            printf("Level %d: %d,  ", i+1, product_value[x][i]);
        }
        printf("\n");

        sell_total = 2;         //特權
        Trading_post(id, &sell_total);

        for(int k = 0; k < sell_total; k++){
            while(1){
                printf("You can choose a product to sell.\n");
                show_product(1);
                printf("-1: I don't want to sell.\n");
                scanf("%d", &pick);

                if(pick == -1){
                    return;
                }
                if(players[0].product[pick] == 0){
                    printf("You didn't have this kind of product.\n");
                }else{
                    players[0].product[pick] --;
                    real_total++;
                    for(int i = 0 ;i < 12; i++){
                        if(card_stack[players[0].building[i]].cost == pick+1 && players[0].building[i] <= 41){     //去用花費找牌
                            card_stack[players[0].building[i]].use = 1;        //調回沒貨狀態
                            break;
                        }
                    }
                    break;
                }
            }
            trader_addcard(product_value[x][pick], 0);
        }
        if(real_total >= 2){
            Market_stand(id);
        }
    }
    else{
        printf("Players%d select trader.\n", id+1);     //玩家還是要賣
        printf("=> Product Value in this turn.\n");
        for(int i = 0; i < 5; i++){
            printf("Level %d: %d,  ", i+1, product_value[x][i]);
        }
        printf("\n");

        Trading_post(0, &sell_total);
        for(int k = 0; k < sell_total; k++){
            while(1){
                printf("You can choose a product to sell.\n");
                show_product(1);
                printf("-1: I don't want to sell.\n");
                scanf("%d", &pick);

                if(pick == -1){
                    return;
                }
                if(players[0].product[pick] == 0){
                    printf("You didn't have this kind of product.\n");
                }else{
                    players[0].product[pick] --;
                    for(int i = 0 ;i < 12; i++){
                        if(card_stack[players[0].building[i]].cost == pick+1 && players[0].building[i] <= 41){     //去用花費找牌
                            card_stack[players[0].building[i]].use = 1;        //調回沒貨狀態
                            break;
                        }
                    }
                    break;
                }
            }
            trader_addcard(product_value[x][pick], 0);
        }
    }
    for(int k = 1; k < 4; k++){
        if(id == k){         //  電腦是特權
            for(int i = 0; i < 5; i++){
                if(players[k].product[i] > 0){
                    players[k].product[i] --;
                    for(int j = 0; j < 12; j++){
                        if(card_stack[players[k].building[j]].cost == i+1 && players[k].building[j] <= 41){
                            card_stack[players[k].building[j]].use = 1;
                            break;
                        }
                    }
                    trader_addcard(product_value[x][i], k);
                    break;
                }

            }
            for(int i = 0; i < 5; i++){
                if(players[k].product[i] > 0){
                    players[k].product[i] --;
                    for(int j = 0; j < 12; j++){
                        if(card_stack[players[k].building[j]].cost == i+1 && players[k].building[j] <= 41){
                            card_stack[players[k].building[j]].use = 1;
                            break;
                        }
                    }
                    trader_addcard(product_value[x][i], k);
                    break;
                }
            }
        }
        else{           //電腦不是特權
            for(int i = 0; i < 5; i++){
                if(players[k].product[i] > 0){
                    players[k].product[i] --;
                    for(int j = 0; j < 12; j++){
                        if(card_stack[players[k].building[j]].cost == i+1 && players[k].building[j] <= 41){
                            card_stack[players[k].building[j]].use = 1;
                            break;
                        }
                    }
                    trader_addcard(product_value[x][i], k);
                    break;
                }
            }
        }
    }
}

void councilor(int id){
    int temp_cards[5] = {255};
    int pick = 0;
    int card_total = 2;

    if(role[3] == 1){
        role[3] = 0;
    }else{
        printf("That role has been choosed.\n");
        return;
    }

    if(id == 0){
        card_total = 5;    //特權
        
        for(int i = 0; i < card_total; i++){
            temp_cards[i] = random_choose(card_stack);
            printf("%d: %s\n", i, card_stack[temp_cards[i]].name);
        }
        while(1){
            printf("choose a card that you want.\n");
            scanf("%d", &pick);
            if(pick < 0 || pick > 5){
                printf("Wrong input.\n");
            }else if(temp_cards[pick] == 255){
                printf("wrong input.\n");
            }else{
                break;
            }
        }
        for(int i = 0; i < 20; i++){                    //把挑到的加入手牌
            if(players[id].in_hand[i] == 255){
                players[id].in_hand[i] = temp_cards[pick];
                break;
            }
        }
        for(int i = 0; i < 5; i++){         //不要的牌放回去
            if(i != pick){
                card_stack[temp_cards[i]].use = 0;
            }
        }
    }
    else{       //偷懶 直接拿一張s，玩家也要拿
        printf("Players%d select councilor.\n", id+1);

        for(int i = 0; i < card_total; i++){
            temp_cards[i] = random_choose(card_stack);
            printf("%d: %s\n", i, card_stack[temp_cards[i]].name);
        }
        while(1){
            printf("choose a card that you want.\n");
            scanf("%d", &pick);
            if(pick < 0 || pick > 5){
                printf("Wrong input.\n");
            }else if(temp_cards[pick] == 255){
                printf("wrong input.\n");
            }else{
                break;
            }
        }
        for(int i = 0; i < 20; i++){                    //把挑到的加入手牌
            if(players[0].in_hand[i] == 255){
                players[0].in_hand[i] = temp_cards[pick];
                break;
            }
        }
        for(int i = 0; i < 5; i++){         //不要的牌放回去
            if(i != pick){
                card_stack[temp_cards[i]].use = 0;
            }
        }
    }


    temp_cards[0] = random_choose(card_stack);      //不管怎樣都要拿

    for(int j = 1; j < 4; j++){
        for(int i = 0; i < 20; i++){                    //把挑到的加入手牌
            if(players[j].in_hand[i] == 255){
                players[j].in_hand[i] = temp_cards[0];
                break;
            }
        }
    }
    
}

void prospector(int id){
    int pick = 0;

    if(role[4] == 1){
        role[4] = 0;
    }else{
        printf("That role has been choosed.\n");
        return;
    }

    if(id == 0){
        printf("Add a card in your hand.\n");
    }else{
        printf("Players%d select prospector.\n", id+1);
    }
    int temp = random_choose(card_stack);
    for(int i = 0; i < 20; i++){
        if(players[id].in_hand[i] == 255){
            players[id].in_hand[i] = temp;
            break;
        }
    }
    return;
}

void action(int _option, int id){
    switch (_option)
    {
    case 1:
        builder(id);
        break;
    case 2:
        producer(id);
        break;
    case 3:
        trader(id);
        break;
    case 4:
        councilor(id);
        break;
    case 5:
        prospector(id);
        break;
    case 6:
        show_card();
        break;
    case 7:
        show_building(0);
        break;
    case 8:
        show_product(id);
        break;
    default:
        printf("Wrong input.\n");
        printf("You lose this turn. HAHA!!\n");
        break;
    }
}

void Smithy(int id, int *cost){
    for(int i = 0; i < 12; i++){
        if(45 <= card_stack[players[id].building[i]].id && card_stack[players[id].building[i]].id <= 47){
            *cost -= 1;
        }
    }
}

void Market_stand(int id){
    for(int i = 0; i < 12; i++){
        if(66 <= card_stack[players[id].building[i]].id && card_stack[players[id].building[i]].id <= 68){
            trader_addcard(1, id);
        }
    }
}

void Well(int id){
    for(int i = 0; i < 12; i++){
        if(63 <= card_stack[players[id].building[i]].id && card_stack[players[id].building[i]].id <= 65){
            trader_addcard(1, id);
        }
    }
}

int Tower(int id){
    for(int i = 0; i < 12; i++){
        if(42 <= card_stack[players[id].building[i]].id && card_stack[players[id].building[i]].id <= 44){
            return 1;
        }
    }
    return 0;
}

void Aquduect(int id, int *total){
    for(int i = 0; i < 12; i++){
        if(75 <= card_stack[players[id].building[i]].id && card_stack[players[id].building[i]].id <= 77){
            *total += 1;
        }
    }
}

void Trading_post(int id, int *total){
    for(int i = 0; i < 12; i++){
        if(60 <= card_stack[players[id].building[i]].id && card_stack[players[id].building[i]].id <= 62){
            *total += 1;
        }
    }
}