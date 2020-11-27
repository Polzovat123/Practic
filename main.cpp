#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;



void draw_header(string text){
    int right, left;
    int all = 73;
    all-=4;
    all-=text.length();
    if(all%2!=0){
        right = all/2;
        left = all - right;
    }else{
        right = left = all/2;
    }
    for(int i=0;i<left;i++)printf("-");
    cout<<"< "<<text<<" >";
    for(int i=0;i<right;i++)printf("-");
}

void draw_header(string text, char tabs){
    int right, left;
    int all = 73;
    all-=4;
    all-=text.length();
    if(all%2!=0){
        right = all/2;
        left = all - right;
    }else{
        right = left = all/2;
    }
    for(int i=0;i<left;i++)printf("%c", tabs);
    cout<<"< "<<text<<" >";
    for(int i=0;i<right;i++)printf("%c", tabs);
}

void sign(){
    string login, password;
    draw_header("Вход");
    cout<<endl;
    draw_header("Логин", ' ');
    cout<<endl;
    cin>>login;
    draw_header("Пароль", ' ');
    cout<<endl;
    cout<<"";
    cin>>password;
}

bool show_monitor(int itt, int number){
    int answer;
    cout<<itt<<".) "<<" 2 * "<<number<<"  = ";
    cin>>answer;
    return answer == number * 2;
}

bool show_monitor_del(int itt, int number){
    int answer;
    cout<<itt<<".) "<<number<<"  / 2 = ";
    cin>>answer;
    return answer * 2== number;
}

int ss(int num){
    int i = 0;
    for(i=0; num>0; num/=10){i++;}
    return i;
}

void finish_console(int score_n, string name, int best_score, string best_name ){
    draw_header("результат");
    cout<<"                                                                         "<<endl;
    cout<<" Ваш результат: "<<score_n;
    cout<<endl;
    cout<<"                                                                         "<<endl;
    cout<<" Лучший игрок: "<<best_name;
    cout<<endl;
    cout<<"                                                                         "<<endl;
    cout<<" Лучший результат: "<<best_score;
    cout<<endl;
    cout<<"                                                                         "<<endl;
    draw_header("Конец");
}

void finish_monitor(int user_score){
    string my_name;
    string best_name;
    int best_score;
    cout<<"Напишите ваш ник : ";
    cin>>my_name;
    fstream in("save.txt");
    in>>best_score>>best_name;
    finish_console(user_score, my_name, best_score, best_name);
    if(user_score > best_score){
        ofstream out("save.txt");
        out<<user_score<<" "<<my_name;
    }else{
        ofstream out("save.txt");
        out<<best_score<<" "<<best_name;
    }
}

void math_test(){
    cout<<"Сейчас будет тест по математике по теме умножения и деления."<<endl;
    cout<<"Сколько вопросов : ";
    int siz = 50;
    cin>>siz;
    int score = 0;
    srand(time(0));
    for(int i=0; i<siz/2;i++){
        int number = rand()%10+1;
        score+=show_monitor(i+1, number);
        if((i+1)%24 == 0){
                system("cls");
                cout<<"Лист "<<(i+1)/24<<endl;
        }
    }
    system("cls");
    cout<<"Теперь деление)"<<endl;
    for(int i=0; i<siz - siz/2;i++){
        int number = rand()%11;
        score+=show_monitor_del(i+1, number*2);
        if((i+1)%24 == 0){
                system("cls");
                cout<<"Лист "<<(i+1)/24<<endl;
        }
    }

    finish_monitor(score);
}

int show_menu(){
    draw_header("Меню");
    int answer;
    cout<<"                                                                         "<<endl;
    draw_header("1. Математический тест ");//
    cout<<"                                                                         "<<endl;
    draw_header("2. Вход ");//
    cout<<"                                                                         "<<endl;
    draw_header("3. Авторизация");
    cout<<endl;
    cin>>answer;
    return answer;
}

void mind(int answer){
    switch (answer){
    case 1:
        system("cls");
        math_test();
        break;
    case 2:
        system("cls");
        sign();
    default:
        cout<<"Need_you_help"<<" "<<answer<<endl;
        int a;
        cin>>a;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int answer;
    while(true){
        system("cls");
        int answer = show_menu();
        mind(answer);
    }
    return 0;
}
