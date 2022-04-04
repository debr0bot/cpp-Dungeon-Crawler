
#include<bits/stdc++.h>
using namespace std;
int
X=0,Y=0,exitX=0,exitY=0,enemy1X=0,enemy1Y=0,enemy2X=0,enemy2Y=0,enemy3X=0,enemy3Y=0;
int prevX,prevY;
bool GWYNDead=1,ABYSSwalkerDead=1,TARKUSdemonDead=1;
bool Gameover=1;
bool PlayerDead=1;
void Input();
void updateGround();
void ABYSSwalkercombat();
void GWYNcombat();
void TARKUSdemoncombat();
class User{public:
string name;
string race;
int health;
int attack;
int arrows;
int attackbonus;
int rangedattack;
int Souls;
} _player;
class R1{public:
int health=50;
int attack=2;
int arrows=5;
int attackbonus=1;
int rangedattack=4;
int Souls=150;
;
} KNIGHT;
class R2{public:
int health=100;
int attack=4;
int arrows=4;
int attackbonus=1;
int rangedattack=2;
int Souls=150;
} WARRIOR;
class R3{public:
int health=50;
int attack=5;
int arrows=3;
int attackbonus=2;
int rangedattack=1;
int Souls=150;
} HUNTER;
class Enemy1{public:
int health=20;
char icon='Y';
int attack=3;
int arrows=0;
int rangedattack=0;
int attackbonus=0;
int Souls=0;
} GWYN;
class Enemy2{public:
int health=50;
char icon='O';
int attack=5;
int arrows=0;
int rangedattack=0;
int attackbonus=0;
int Souls=0;
} ABYSSwalker;
class Enemy3{public:
int health=30;
char icon='P';
int attack=4;
int arrows=0;
int rangedattack=0;
int attackbonus=0;
int Souls=0;
} TARKUSdemon;
const char BREADTH=21,LENGTH=41;
const char player='X';
const char Exit='E';
char GWYNicon='Y';
char ABYSSwalkericon='O';
char TARKUSdemonicon='P';
char deadicon=' ';
unsigned char ground[BREADTH][LENGTH]={
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#','#','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#','#',' ','#',' ','#',' ','#','#'},
{'#',' ','#',' ','#',' ','#','#',' ',' ','#','#',' ','#',' ',' ','#','#','#',' ',' ','#','#',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ','#'},
{'#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#'},
{'#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ','#'},
{'#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#','#',' ','#','#',' ','#'},
{'#',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#','#'},
{'#','#','#','#',' ','#',' ','#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#','#',' ',' ','#','#','#',' ',' ',' ','#',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ','#'},
{'#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ','#',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#'},
{'#',' ','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#'},
{'#',' ','#','#',' ',' ',' ','#','#','#',' ',' ','#','#','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' ','#'},
{'#',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#',' ',' ','#',' ',' ','#','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ','#'},
{'#',' ','#',' ','#','#','#','#','#','#','#',' ','#','#',' ','#','#','#','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ','#','#'},
{'#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#'},
{'#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ','#','#',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ','#','#','#',' ','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};
int main(){
string name;
char chooseRace;
X=19;
Y=7;
exitX=19;
exitY=39;
enemy1X=10;
enemy1Y=23;
enemy2X=5;
enemy2Y=3;
enemy3X=9;
enemy3Y=13;
GWYNDead=false;
TARKUSdemonDead=false;
ABYSSwalkerDead=false;
Gameover=false;
PlayerDead=false;
ground[enemy1X][enemy1Y]=GWYNicon;
ground[enemy2X][enemy2Y]=ABYSSwalkericon;
ground[enemy3X][enemy3Y]=TARKUSdemonicon;
ground[exitX][exitY]='!';
cout<<"#########################################################################";
cout<<" ";
cout<<" DUNK SOULS ";
cout<<" [A DEBTIRTHA SAHA GAME] ";
cout<<"####################################################################";
cout<<endl;
cout<<"Enter name: ";
cin>>name;
_player.name=name;
cout<<"WELCOME"<<endl<<_player.name<<' ';
cout<<"Choose your class: "<<endl;
cout<<"{k}-KNIGHT,{w}=WARRIOR,{h}=HUNTER"<<endl;
cin>>chooseRace;
switch(chooseRace){
case 'k':
_player.health=KNIGHT.health;
_player.Souls=KNIGHT.Souls;
_player.arrows=KNIGHT.arrows;
_player.attack=KNIGHT.attack;
_player.attackbonus=KNIGHT.attackbonus;
_player.rangedattack=KNIGHT.rangedattack;
_player.race="KNIGHT";
break;
case 'w':
_player.health=WARRIOR.health;
_player.Souls=WARRIOR.Souls;
_player.arrows=WARRIOR.arrows;
_player.attack=WARRIOR.attack;
_player.attackbonus=WARRIOR.attackbonus;
_player.rangedattack=WARRIOR.rangedattack;
_player.race="WARRIOR";
break;
case 'h':
_player.health=HUNTER.health;
_player.Souls=HUNTER.Souls;
_player.arrows=HUNTER.arrows;
_player.attack=HUNTER.attack;
_player.attackbonus=HUNTER.attackbonus;
_player.rangedattack=HUNTER.rangedattack;
_player.race="HUNTER";
break;
default:
break;
}
cout<<"Chose to play as: "<<_player.name<<' '<<"the"<<' '<<_player.race<<endl;
cout<<"Your stats are: "<<endl;
cout<<"Health: "<<_player.health<<endl;
cout<<"Souls(USED to HEAL,1 HEAL=10 souls ): "<<_player.Souls<<endl;
cout<<"Damage: "<<_player.attack<<endl;
cout<<"Range attack: "<<_player.rangedattack<<endl;
cout<<"Arrows: "<<_player.arrows<<endl;
cout<<"Attack bonus: "<<_player.attackbonus<<endl;
cout<<endl;
cout<<"YOU wake up in a dark,dreary dungeon"<<endl<<"You are 'X' and you NEED to reach your goal (!)"<<endl;
cout<<" ATTENTION!!! UNAVOIDABLE HIT:An unavoidable ATTACK hits you when your opponent dies!!"<<endl;
cout<<endl;
cout<<"YOU ARE READY TO PLAY!(PRESS 'w'(or)'s'(or)'a'(or)'d' to reveal the dungeon)";
while(!PlayerDead){
Input();
updateGround();
if(ground[X][Y]==ground[exitX][exitY]){
break;
}
if((ground[X][Y]==ground[enemy1X][enemy1Y])&(!GWYNDead)){
cout<<endl<<"You found the lord of Cinder-GWYN ";
GWYNcombat();}
if((ground[X][Y]==ground[enemy2X][enemy2Y])&(!ABYSSwalkerDead)){
cout<<endl<<"You found the ABYSSwalker ";
ABYSSwalkercombat();}
if((ground[X][Y]==ground[enemy3X][enemy3Y])&(!TARKUSdemonDead)){
cout<<endl<<"You found the TARKUSdemon ";
TARKUSdemoncombat();}
}
if(PlayerDead){cout<<endl<<"GAME OVER!"<<endl<<"YOU FAILED"<<endl<<"TRY AGAIN";}else{
cout<<endl<<"YOU SUCCESSFULLY CROSSED THE DUNGEON!!!"<<endl;
Gameover=true;
PlayerDead=false;
}
return 0;
}
void GWYNcombat(){
cout<<endl;
cout<<"Your stats are"<<" "<<"GWYN stats are"<<endl;
cout<<"Health: "<<_player.health<<" "<<"Health: "<<GWYN.health<<endl;
cout<<"Souls: "<<_player.Souls<<" "<<"Souls: "<<GWYN.Souls<<endl;
cout<<"Damage: "<<_player.attack<<" "<<"Damage: "<<GWYN.attack<<endl;
cout<<"Arrows: "<<_player.arrows<<" "<<"Arrows: "<<GWYN.arrows<<endl;
cout<<"Ranged attack: "<<_player.rangedattack<<" "<<"Ranged attack: "<<GWYN.rangedattack<<endl;
cout<<"Attack bonus: "<<_player.attackbonus<<" "<<"Attack bonus: "<<GWYN.attackbonus<<endl;
cout<<endl;
cout<<"What would you like to do ?"<<endl<<"Press (1) to attack"<<endl<<"Press (2) to fire arrow"<<endl<<"Press (3) to heal"<<endl;
while(GWYN.health>0){
int GWYNcombatoptions;
cin>>GWYNcombatoptions;
switch(GWYNcombatoptions){
case 1:{
int doeshitdamage=rand()%4;
int meleedamage=_player.attack;
if(doeshitdamage==0){
cout<<endl<<_player.name<<" MISSES "<<"GWYN"<<endl;}
else{
meleedamage *=_player.attackbonus;
GWYN.health -=meleedamage;
if(GWYN.health<0){GWYN.health=0;}
cout<<endl<<_player.name<<" hits "<<"GWYN"<<"for"<<meleedamage<<" damage "<<endl;
cout<<endl<<" GWYN'S HEALTH drops TO "<<GWYN.health<<endl;
}
break;
}
case 2:{
if(_player.arrows>0){
_player.arrows -=1;
int doesarrowdamage=rand()%5;
int rangedamage=_player.rangedattack;
if(doesarrowdamage==0){cout<<endl<<_player.name<<" MISSES "<<"GWYN"<<endl;}
else{
rangedamage *=_player.attackbonus;
GWYN.health -=rangedamage;
if(GWYN.health<0){GWYN.health=0;}
cout<<endl<<_player.name<<" shoots GWYN causing "<< rangedamage<<" Damage "<<endl;
cout<<endl<<" GWYN'S HEALTH drops TO "<<GWYN.health<<endl;
cout<<endl<<_player.name<<" now has "<<_player.arrows<<" arrows left "<<endl;
}}else{cout<<endl<<_player.name<<" is out of arrows "<<endl;}
break;
}
case 3:{
if(_player.Souls >0){
_player.Souls -=10;
int heal=rand()%10+15;
_player.health +=heal;
cout<<endl<<_player.name<<" gains "<<heal<<endl;
cout<<endl<<_player.name<<" has "<<_player.health<<" HEALTH and"<<_player .Souls<<" Souls"<<endl;
}else{cout<<endl<<_player.name<<" is out of Souls!!"<<endl;}
break;
}
default:{
break;
}}
if(GWYN.health<=0){
GWYNDead=true;
cout<<endl<<_player.name<<" killed "<<" GWYN "<<endl;
}
int doesGWYNdamage=rand()%8;
int GWYNdamage=GWYN.attack;
if(doesGWYNdamage==0){cout<<endl<<" GWYN misses "<<_player.name<<endl;}
else{
_player.health-=GWYNdamage;
if(_player.health<0){_player.health=0;
}
cout<<endl<<"GWYN strikes "<<_player.name<<" resulting in "<<GWYNdamage<<"damage "<<endl;
cout<<endl<<_player.name<<"'s HEALTH drops down to "<<_player.health<<endl;
}
if(_player.health<=0){
cout<<endl<<" GWYN killed "<<_player.name<<endl;
cout<<"YOU DIED!!"<<endl;
cout<<"Press 'y' to continue"<<endl;
char _continue;
cin>>_continue;
if(_continue=='y'){
PlayerDead=true;
Gameover=true;
break;
}
}
}
}
void ABYSSwalkercombat(){
cout<<endl;
cout<<"Your stats are"<<" "<<"ABYSSwalker stats are"<<endl;
cout<<"Health: "<<_player.health<<" "<<"Health: "<<ABYSSwalker.health<<endl;
cout<<"Souls: "<<_player.Souls<<" "<<"Souls: "<<ABYSSwalker.Souls<<endl;
cout<<"Damage: "<<_player.attack<<" "<<"Damage: "<<ABYSSwalker.attack<<endl;
cout<<"Arrows: "<<_player.arrows<<" "<<"Arrows: "<<ABYSSwalker.arrows<<endl;
cout<<"Ranged attack: "<<_player.rangedattack<<" "<<"Ranged attack:"<<ABYSSwalker.rangedattack<<endl;
cout<<"Attack bonus: "<<_player.attackbonus<<" "<<"Attack bonus:"<<ABYSSwalker.attackbonus<<endl;
cout<<endl;
cout<<"What would you like to do ?"<<endl<<"Press (1) to attack"<<endl<<"Press (2) to fire arrow"<<endl<<"Press (3) to heal"<<endl;
while(ABYSSwalker.health>0){
int ABYSSwalkercombatoptions;
cin>>ABYSSwalkercombatoptions;
switch(ABYSSwalkercombatoptions){
case 1:{
int doeshitdamage=rand()%4;
int meleedamage=_player.attack;
if(doeshitdamage==0){
cout<<endl<<_player.name<<" MISSES "<<"ABYSSwalker"<<endl;}
else{
meleedamage *=_player.attackbonus;
ABYSSwalker.health -=meleedamage;
if(ABYSSwalker.health<0){ABYSSwalker.health=0;}
cout<<endl<<_player.name<<" hits "<<"ABYSSwalker"<<"for"<<meleedamage<<" damage "<<endl;
cout<<endl<<" ABYSSwalker'S HEALTH drops TO "<<ABYSSwalker.health<<endl;
}
break;
}
case 2:{
if(_player.arrows>0){
_player.arrows -=1;
int doesarrowdamage=rand()%5;
int rangedamage=_player.rangedattack;
if(doesarrowdamage==0){cout<<endl<<_player.name<<" MISSES"<<"ABYSSwalker"<<endl;}
else{
rangedamage *=_player.attackbonus;
ABYSSwalker.health -=rangedamage;
if(ABYSSwalker.health<0){ABYSSwalker.health=0;}
cout<<endl<<_player.name<<" shoots ABYSSwalker causing "<< rangedamage<<"Damage "<<endl;
cout<<endl<<" ABYSSwalker'S HEALTH drops TO "<<ABYSSwalker.health<<endl;
cout<<endl<<_player.name<<" now has "<<_player.arrows<<" arrows left "<<endl;
}}else{cout<<endl<<_player.name<<" is out of arrows "<<endl;}
break;
}
case 3:{
if(_player.Souls >0){
_player.Souls -=10;
int heal=rand()%10+15;
_player.health +=heal;
cout<<endl<<_player.name<<" gains "<<heal<<endl;
cout<<endl<<_player.name<<" has "<<_player.health<<" HEALTH and"<<_player.Souls<<" Souls "<<endl;
}else{cout<<endl<<_player.name<<" is out of Souls!!"<<endl;}
break;
}
default:{
break;
}}
if(ABYSSwalker.health<=0){
ABYSSwalkerDead=true;
cout<<endl<<_player.name<<" killed "<<" ABYSSwalker "<<endl;
}
int doesABYSSwalkerdamage=rand()%8;
int ABYSSwalkerdamage=ABYSSwalker.attack;
if(doesABYSSwalkerdamage==0){cout<<endl<<" ABYSSwalker misses"<<_player.name<<endl;}
else{
_player.health-=ABYSSwalkerdamage;
if(_player.health<0){_player.health=0;
}
cout<<endl<<"ABYSSwalker strikes "<<_player.name<<" resulting in"<<ABYSSwalkerdamage<<" damage "<<endl;
cout<<endl<<_player.name<<"'s HEALTH drops down to "<<_player.health<<endl;
}
if(_player.health<=0){
cout<<endl<<" ABYSSwalker killed "<<_player.name<<endl;
cout<<"YOU DIED!!"<<endl;
cout<<"Press 'y' to continue"<<endl;
char _continue;
cin>>_continue;
if(_continue=='y'){
PlayerDead=true;
Gameover=true;
break;
}
}
}
}
void TARKUSdemoncombat(){
cout<<endl;
cout<<"Your stats are"<<" "<<"TARKUSdemon stats are"<<endl;
cout<<"Health: "<<_player.health<<" "<<"Health: "<<TARKUSdemon.health<<endl;
cout<<"Souls: "<<_player.Souls<<" "<<"Souls: "<<TARKUSdemon.Souls<<endl;
cout<<"Damage: "<<_player.attack<<" "<<"Damage: "<<TARKUSdemon.attack<<endl;
cout<<"Arrows: "<<_player.arrows<<" "<<"Arrows: "<<TARKUSdemon.arrows<<endl;
cout<<"Ranged attack: "<<_player.rangedattack<<" "<<"Ranged attack:"<<TARKUSdemon.rangedattack<<endl;
cout<<"Attack bonus: "<<_player.attackbonus<<" "<<"Attack bonus:"<<TARKUSdemon.attackbonus<<endl;
cout<<endl;
cout<<"What would you like to do ?"<<endl<<"Press (1) to attack"<<endl<<"Press (2) to fire arrow"<<endl<<"Press (3) to heal"<<endl;
while(TARKUSdemon.health>0){
int TARKUSdemoncombatoptions;
cin>>TARKUSdemoncombatoptions;
switch(TARKUSdemoncombatoptions){
case 1:{
int doeshitdamage=rand()%4;
int meleedamage=_player.attack;
if(doeshitdamage==0){
cout<<endl<<_player.name<<" MISSES "<<"TARKUSdemon"<<endl;}
else{
meleedamage *=_player.attackbonus;
TARKUSdemon.health -=meleedamage;
if(TARKUSdemon.health<0){TARKUSdemon.health=0;}
cout<<endl<<_player.name<<" hits "<<"TARKUSdemon"<<"for"<<meleedamage<<" damage "<<endl;
cout<<endl<<" TARKUSdemon'S HEALTH drops TO "<<TARKUSdemon.health<<endl;
}
break;
}
case 2:{
if(_player.arrows>0){
_player.arrows -=1;
int doesarrowdamage=rand()%5;
int rangedamage=_player.rangedattack;
if(doesarrowdamage==0){cout<<endl<<_player.name<<" MISSES "<<"TARKUSdemon"<<endl;}
else{
rangedamage *=_player.attackbonus;
TARKUSdemon.health -=rangedamage;
if(TARKUSdemon.health<0){TARKUSdemon.health=0;}
cout<<endl<<_player.name<<" shoots TARKUSdemon causing "<< rangedamage<<"Damage "<<endl;
cout<<endl<<" TARKUSdemon's HEALTH drops TO "<<TARKUSdemon.health<<endl;
cout<<endl<<_player.name<<" now has "<<_player.arrows<<" arrows left "<<endl;
}}else{cout<<endl<<_player.name<<" is out of arrows "<<endl;}
break;
}
case 3:{
if(_player.Souls >0){
_player.Souls -=10;
int heal=rand()%10+15;
_player.health +=heal;
cout<<endl<<_player.name<<" gains "<<heal<<endl;
cout<<endl<<_player.name<<" has "<<_player.health<<" HEALTH and "<<_player.Souls<<" Souls"<<endl;
}else{cout<<endl<<_player.name<<" is out of Souls!!"<<endl;}
break;
}
default:{
break;
}}
if(TARKUSdemon.health<=0){
TARKUSdemonDead=true;
cout<<endl<<_player.name<<" killed "<<" TARKUSdemon "<<endl;
}
int doesTARKUSdemondamage=rand()%8;
int TARKUSdemondamage=TARKUSdemon.attack;
if(doesTARKUSdemondamage==0){cout<<endl<<" TARKUSdemon misses "<<_player.name<<endl;}
else{
_player.health-=TARKUSdemondamage;
if(_player.health<0){_player.health=0;
}
cout<<endl<<"TARKUSdemon strikes "<<_player.name<<" resulting in "<<TARKUSdemondamage<<" damage "<<endl;
cout<<endl<<_player.name<<"'s HEALTH drops down to "<<_player.health<<endl;
}
if(_player.health<=0){
cout<<endl<<" TARKUSdemon killed "<<_player.name<<endl;
cout<<"YOU DIED!!"<<endl;
cout<<"Press 'y' to continue"<<endl;
char _continue;
cin>>_continue;
if(_continue=='y'){
PlayerDead=true;
Gameover=true;
break;
}
}
}
}
void Input(){
cout<<endl<<"Your GOAL is to find and reach THE '!' marker";
cout<<endl<<"COMMAND:(Use the letters 'w','s','a','d' and then hit 'ENTER' to move) ";
unsigned char MOVE;
cin>>MOVE;
switch(MOVE)
{
case 'a':
if(ground[X][Y-1] !='#'){
Y--;
ground[prevX][prevY]=' ';
}
system("cls");
break;
case 'd':
if(ground[X][Y+1] !='#'){
Y++;
ground[prevX][prevY]=' ';
}
system("cls");
break;
case 'w':
if(ground[X-1][Y] !='#'){
X--;
ground[prevX][prevY]=' ';
}
system("cls");
break;
case 's':
if(ground[X+1][Y] !='#'){
X++;
ground[prevX][prevY]=' ';
}
system("cls");
break;
default:
cout<<"INVALID ACTION !"<<endl;
break;
}
}
void updateGround(){
unsigned char ground[BREADTH][LENGTH]={
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#','#','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#','#',' ','#',' ','#',' ','#','#'},
{'#',' ','#',' ','#',' ','#','#',' ',' ','#','#',' ','#',' ',' ','#','#','#',' ',' ','#','#',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ','#'},
{'#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#'},
{'#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ','#'},
{'#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#','#',' ','#','#',' ','#'},
{'#',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#','#'},
{'#','#','#','#',' ','#',' ','#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#','#',' ',' ','#','#','#',' ',' ',' ','#',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ','#'},
{'#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ','#',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#'},
{'#',' ','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#'},
{'#',' ','#','#',' ',' ',' ','#','#','#',' ',' ','#','#','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' ','#'},
{'#',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#',' ',' ','#',' ',' ','#','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ','#'},
{'#',' ','#',' ','#','#','#','#','#','#','#',' ','#','#',' ','#','#','#','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ','#','#'},
{'#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#'},
{'#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ','#','#',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ','#','#','#',' ','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};
if(!GWYNDead){ground[enemy1X][enemy1Y]=GWYNicon;
}else{
ground[enemy1X][enemy1Y]=deadicon;
}
if(!ABYSSwalkerDead){ground[enemy2X][enemy2Y]=ABYSSwalkericon;
}else{
ground[enemy2X][enemy2Y]=deadicon;
}
if(!TARKUSdemonDead){ground[enemy3X][enemy3Y]=TARKUSdemonicon;
}else{
ground[enemy3X][enemy3Y]=deadicon;
}
ground[X][Y]=player;
ground[exitX][exitY]='!';
for(int y=0;y<BREADTH;y++){
cout<<endl;
for(int x=0;x<LENGTH;x++){cout<<ground[y][x];}
}
}
