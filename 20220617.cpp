/*
Пользователь определяет символ, которым будет заполнятся фигура
Выбирает длину и ширину прямоугольника
На выбор пользователя : заполнять полностью или только края
напечатать прямоугольник
*/

#include <iostream>
#include <vector>


using namespace std;

struct REC {
    int length;
    int heigth;
    char userSimvol = 'R';
    vector< vector<char> > inRec;
};

enum IN_REC {
    ALL_REC = 1,
    BORD_REC,
};





void printRec(const REC& rec) {
    for (int i = 0; i < rec.heigth; i++) {
        for (int j = 0; j < rec.length; j++) {
            cout << rec.inRec[i][j];
        };
        cout << endl;
    }
}

void fillRec(REC& user1) {

    
    int useUser = 0;
    // Заполняем прямоугольник
    cout << "Выберите команду заполняем полностью - 1 или по краям - 2" << endl;
    cin >> useUser;

    switch (useUser) {
    case ALL_REC:
        cout << endl;
        for (int i = 0; i < user1.heigth; i++) {
            vector<char> temp;
            for (int j = 0; j < user1.length; j++) {
                temp.push_back(user1.userSimvol);
            }
            user1.inRec.push_back(temp);
        }
        cout << endl;
        break;
    case BORD_REC:
        cout << endl;
        for (int i = 0; i < user1.heigth; i++) {
            vector<char> temp;
            
            for (int j = 0; j < user1.length; j++) {
                // Заполняем верхнию и нижнию границу
                if (i == 0 || i == user1.heigth - 1) {
                    temp.push_back(user1.userSimvol);                   
                } else
                    // Заполняем левую и правую границу
                   if (j == 0 || j == user1.length - 1) {                    
                        temp.push_back(user1.userSimvol);
                        continue;
                   } else {
                        temp.push_back('-');
                    }
            }

            user1.inRec.push_back(temp);
        }
        cout << endl;
        break;
    default:
        cout << "Такой команды нет!" << endl;
        break;
    }
}

int main(){
    setlocale(LC_ALL, "RUS");
    REC user1;

    cout << "Введите длину прямоугольника: ";
    cin >> user1.length;
    
    cout << "Введите ширину прямоугольника: ";
    cin >> user1.heigth;

    cout << "Введите символ заполнения: ";
    cin >> user1.userSimvol;



    fillRec(user1);

    printRec(user1);

}
