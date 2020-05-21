#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
string data[17]=
{
"####################",
"# #   #    #P # B  #",
"# #  ## #  #  #    #",
"# ## ##  # O#  # # #",
"# #  B#    ##    # #",
"#   #  #   ##      #",
"# ###  O   #   # # #",
"# #    #   #  #    #",
"#   #  #  #  #  B  #",
"# P#   B   #      ##",
"###O ##### O     - #",
"#    #       ##### #",
"#  ##  ## # #P     #",
"#  #  B   #  #  ####",
"#  #  #####  #  -  #",
"#      #     #  # G#",
"####################"
};
string Winner_gift="Hbrs} Ckuxhec|%!\".#M iqsi ujlw ngvwahg#gao\"sest\"ws zqx$oo\"wmmf0#M iqsi xjhr zqx$rfcg$tikv$mfuvegf\"L$wbu#wtjno$nfcu$ypw#sr!kq$cppwicu\"zmti\"|su/\"Lx ju#qy!jrros\"wlau\"L$cbp#qefv#e hkup mkni zqx2 Jh#ynmwfolz\"L$djf#rou\"pekf\"wlovik$tig#trpehws/\"L$hprh$ypw#gao\"imne\"d$bfvwir!rhvspp#xhbp#qe/\"Ws cg#loogvx,!kw$it\"qst!wvyamn|$a!ilvl!cvo ng#xo!vheci\"kir!cesuu\"F/+!qu$oujhv ujlrgt\"dfovv#goekqk.!Gyin!vksuhj#mn!vki dndws!yh$hbxh$ffodpe!eoestodxe-\"eyt!vkiy!jdze!pr$iovhvetv#xoxcuh dqptuugu2 J\"kspf\"|su!edr ncgi jv#mn!vki fpg$aof#M dcq$bf\"wle!rhvspp#wtb{#{iuj#}ov0Rret\"dkajp/$Hbrs} ckuxhec|%!\"";
int Answer=1;
int sectryNumber =9923;
int LevelOne(){
    cout << "Welcome to Level 1"<< endl;
    cout << "In this level, you need to type in the number. Only the correct number you type in will be allow you to pass this level." << endl;
    try
    {
        string input="";
        while(input==""){
            cout << "Try to type in a number: ";
            cout.flush();
            cin >> input;
            int inputNumber = stoi(input);
            if(inputNumber==sectryNumber){
                //break;
            }else{
                cout << "You did not input the current one" << endl;
            }
            input="";
        }
    }
    catch(const std::exception& e)
    {
    }
     return 2;   
}
int LevelTwo(){
    cout << "Welcome to Level 2"<< endl;
    cout << "In this level, you need to find the letter that match with your birth day." << endl;
    for(int i=0;i<26;i++){
        cout << (char)('A'+i)<<" - " << i+1<< endl;
    }
    string input="";
    srand(time(NULL));
    int count=0;
    while(input==""){
        try
        {
            cout << "Try to type in a number: ";
            cout.flush();
            cin>>input;
            if(input=="ILY"){
                count++;
            }else if(input=="ET"){
                Answer=1102;
                count+=10;
            }
            if(rand()%200==5){
                cout << "You input the correct one" << endl;
                return 1;
            }
            if(count==20)
                return 3;
            
        }
        catch(const std::exception& e)
        {
            cout << "Not this one, Try Again"<< endl;

        }
        input="";
    }
}
int LevelThree(){
    int px=1;
    int py=1;
    cout << "Welcome to Level 3" << endl;
    sleep(1);
    while (true)
    {
        system("clear");
        cout << "You need to move you charactor to find the gold. You can type in WASD to move the charactor." << endl;
        cout << "Be careful, the maze have some trap that will stop you to get to the target." << endl;
        for(int x=0;x<17;x++){
            for(int y=0;y<20;y++){
                if(px==x&&py==y)
                    cout << "@";
                else if(data[x][y]=='-')
                    cout << "#";
                else if(data[x][y]!='#'&&data[x][y]!='G')
                    cout << " ";
                else
                    cout << data[x][y];
            }
            cout << endl;
        }
        string in;
        cin >> in;
        int nx=px;
        int ny=py;
        if(in=="W")
            nx=px-1;
        else if(in=="A")
            ny=py-1;
        else if(in=="S")
            nx=px+1;
        else if(in=="D")
            ny=py+1;
        else{
            cout << "Please Type WASD"<<endl;
            sleep(1);
        }
        if(data[nx][ny]!='#'){
            px=nx;
            py=ny;
        }if(data[nx][ny]=='B'){
            system("clear");
            cout << "Sorry, You trigger a bomb. Please start from Level 1"<< endl;
            return 1;
        }
        if(data[nx][ny]=='G'){
            system("clear");
            for (int i = 0; i < Winner_gift.length(); i++)
            {
                cout << (char)((Winner_gift[i]-31-i%(sectryNumber%Answer))+31);
            }
            cout << endl;
            return 4;
        }
        if(data[nx][ny]=='P'){
            while(data[nx][ny]!=' '){
                nx=rand()%17;
                ny=rand()%20;
            }
            px=nx;
            py=ny;
        }
        if(data[nx][ny]=='O'){
            px=1;
            py=1;
        }
    }
    return 4;
}

int main(){
    int stage=1;
    while(stage!=4){
        if(stage==1)stage=LevelOne();
        if(stage==2)stage=LevelTwo();
        if(stage==3)stage=LevelThree();
    }
}
