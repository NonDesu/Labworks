#include <iostream>
#include <cstdlib>

using namespace std;
struct Coin{
    char country[15];
    char met[15];
    float denom;
    int amount;
    int date;
    int value;
    Coin *nxt, *prv;  
};
/*
class Coin{
    public:
        char country[15];
        char met[15];
        float denom;
        int amount;
        int date;
        int value;
        Coin *nxt, *prv;
        Coin(){
            strcpy(country, "");
            strcpy(met, "");
            denom = 0;
            amount = 0;
            date = 0;
            value = 0;
        }        
};
*/

class Collection{
    public:
        Coin *bgn, *end, *tmp;
        int count;        
        Collection(){
            bgn = end = tmp = 0;
            count = 0;
        }
        ~Collection(){
            while(bgn){
                tmp = bgn;
                bgn = bgn->nxt;
                delete tmp;
            }
            bgn = end = tmp = NULL;
        }
        void ShowColNxt(void);
        void ShowColPrv(void);
        void CheckValue(void);
        void ShowAC(void);
        void AddCoin(void);
        void DeleteCoin(void);
        void FileLoad(void);
        void FileSave(void);        
};
                
void Menu(void){
    Collection C;
    int key = 0;
    cout << "Create list from file? [y/n]\nPress Any Key..." << endl;
    key = _getch();
    if (key == 121)
        C.FileLoad();
    key = 0;
    while (key != 27){
        system("cls");
        cout << "Menu:" << endl;
        cout << "\t1-Show Collection ->\n\t2-Show Collection <-\n\t3-Add Coin\n\t4-Delete Coin\n\t5-Show Value\n\t6-Show All coins made after date" << endl;
        cout << "Esc - exit" << endl;
        cout << "\n Press Any Key..." << endl;
        key = _getch();
        if (key == 49)
            C.ShowColNxt();
        if (key == 50)
            C.ShowColPrv();
        if (key == 51)
            C.AddCoin();
        if (key == 52)
            C.DeleteCoin();
        if (key == 53)
            C.CheckValue();
        if (key == 54)
            C.ShowAC();
    }
    system("cls");
    cout << "Save changes to file? [y/n]\nPress Any Key..." << endl;
    key = _getch();
    if (key == 121)
        C.FileSave();
    else
        return;
}

void Collection::FileLoad(void){
    FILE *f = fopen("Collection.txt", "r");
    if(!f) return;
    while(!feof(f)){
        //ifstream in("C://1.txt",std::ios::binary);
        tmp = new Coin;
        fscanf(f, "%s", &tmp->country);
        fscanf(f, "%g", &tmp->denom);
        fscanf(f, "%s", &tmp->met);
        fscanf(f, "%d", &tmp->date);
        fscanf(f, "%d", &tmp->value);
        fscanf(f, "%d", &tmp->amount);
        if(!bgn)
            bgn = end = tmp;
        else{
            end->nxt = tmp;
            tmp->prv = end;
        }
        end = tmp;
        count++;
    }
    fclose(f);
    //in.close();
}
void Collection::FileSave(void){
    FILE *f = fopen("Collection.txt", "w");
    if(!f) return;
    tmp = bgn;
    //ofstream out("C://1.txt",std::ios::binary);
    while(tmp!=NULL){
        //out.write((char*)tmp,sizeof tmp);
        fprintf(f, "%s ", tmp->country);
        fprintf(f, "%g ", tmp->denom);
        fprintf(f, "%s ", tmp->met);
        fprintf(f, "%d ", tmp->date);
        fprintf(f, "%d ", tmp->value);
        fprintf(f, "%d", tmp->amount);
        if(tmp != end)
            fprintf(f, "\n");
        tmp = tmp->nxt;
    }
    fclose(f);
    //out.close();
}
void Collection::AddCoin(void){
    system("cls");
    int x,i=1;
    
    Coin *add = bgn;  
    Coin *tmp = new Coin;
    if(!tmp) exit(1);
    cout << "\tEnter the following info: " << endl;
    cout << "\tCountry: "; cin >> tmp->country;
    cout << "\tDenomination: "; cin >> tmp->denom;
    cout << "\tMetal: "; cin >> tmp->met;
    cout << "\tDate: "; cin >> tmp->date;
    cout << "\tValue: "; cin >> tmp->value;
    cout << "\tAmount: "; cin >> tmp->amount;
    if(count){
        cout << "\tAdd coin to position [out of " << count+1 << "]: "; cin >> x;
        if(x <= count){
            while(i<x){
                add = add->nxt;
                i++;
            }      
            if(add == bgn){//Adding to the begining of the list
                tmp->nxt = bgn;
                tmp->prv = NULL;
                tmp->nxt->prv = tmp;
                bgn = tmp;
            }
            else{//Adding to the list
                add->prv->nxt = tmp;
                tmp->nxt = add;
                tmp->prv = add->prv;
                add->prv = tmp;
            }
        }
        else{//Adding to the end of the list
            tmp->nxt = NULL;
            tmp->prv = end;
            tmp->prv->nxt = tmp;
            end = tmp;
        }
    }
    else{//If the list is empty
        bgn = end = tmp;
        tmp->nxt = NULL;
        tmp->prv = NULL;
    }    
    count++;
}
void Collection::DeleteCoin(void){
    system("cls");
    int x,i=1;
    int key=0;
    Coin *del = bgn;
    if(count > 1){
        while(key!=121){
            cout << "\tDelete coin from position[out of " << count << "]: "; cin >> x;
            cout << "\tAre you sure? [y/n] "; key = _getch();
            if(key == 110) return;
        }
        while(i<x){
            del = del->nxt;
            i++;
        }  
        if(del == bgn){
            del = bgn;
            bgn = bgn->nxt;
            bgn->prv = NULL;
            delete del;
        }
        else if(del == end){
                del = end;
                end = end->prv;
                end->nxt = NULL;
                delete del;
            }
            else{
                del->prv->nxt = del->nxt;
                del->nxt->prv = del->prv;
                delete del;
            }
    }
    else{
        while(key!=121){
        system("cls");
        cout << "\tAre you sure? [y/n] "; key = _getch();
        if(key == 110) return;
        }
        del = bgn;
        bgn = end = NULL;
        delete del;
    }
    count--;
}
void Collection::ShowColNxt(void){
    system("cls");
    cout << "Showing Collection: " << endl;
    if(!bgn){
        cout << "\tList is empty!" << endl;
        cout << "\nPress any key..." << endl;
        _getch();
        return;
    }
    cout << "\t+-----------------------+-------+---------------+-------+-------+-------+" << endl;
    cout << "\t|Country\t\t|Denom\t|Metal\t\t|Date\t|Value\t|Amount\t|" << endl;
    cout << "\t+-----------------------+-------+---------------+-------+-------+-------+" << endl;
    int j=0;
    do{
        tmp = ((j++==0) ? bgn : tmp->nxt);
        cout << "\t|" << tmp->country << "\t\t|" << tmp->denom << "\t|" << tmp->met << "\t|" << tmp->date << "\t|" << tmp->value << "\t|" << tmp->amount << "\t|" <<endl;        
    }while(tmp!=end);
    cout << "\t+-----------------------+-------+---------------+-------+-------+-------+" << endl;
    cout << "\nPress any key..." << endl;
    _getch();
}
void Collection::ShowColPrv(void){
    system("cls");
    cout << "Showing Collection: " << endl;
    if(!bgn){
        cout << "\tList is empty!" << endl;
        cout << "\nPress any key..." << endl;
        _getch();
        return;
    }
    cout << "\t+-----------------------+-------+---------------+-------+-------+-------+" << endl;
    cout << "\t|Country\t\t|Denom\t|Metal\t\t|Date\t|Value\t|Amount\t|" << endl;
    cout << "\t+-----------------------+-------+---------------+-------+-------+-------+" << endl;
    int j=0;
    do{
        tmp = ((j++==0) ? end : tmp->prv);
        cout << "\t|" << tmp->country << "\t\t|" << tmp->denom << "\t|" << tmp->met << "\t|" << tmp->date << "\t|" << tmp->value << "\t|" << tmp->amount << "\t|" <<endl;
    }while(tmp!=bgn);
    cout << "\t+-----------------------+-------+---------------+-------+-------+-------+" << endl;
    cout << "\nPress any key..." << endl;
    _getch();
}
void Collection::CheckValue(void){
    system("cls");
    float sum=0;
    cout << "Checking value..." << endl;
    tmp = bgn;
    int j=0;
    do{
        tmp = ((j++==0) ? bgn : tmp->nxt);
        sum+=(tmp->value)*(tmp->amount);
    }while(tmp != end);
    system("cls");
    cout << "Total value of the current collection is " << sum << endl;
    cout << "\nPress any key..." << endl;
    _getch();
}
void Collection::ShowAC(void){
    system("cls");
    int x;
    cout << "Enter date restriction: "; cin >> x;
    cout << "Showing Collection starting from " << x << "\n" << endl;
    if(!bgn){
        cout << "\tList is empty!" << endl;
        cout << "\nPress any key..." << endl;
        _getch();
        return;
    }
    tmp = bgn;
    cout << "\t+-----------------------+-------+---------------+-------+-------+-------+" << endl;
    cout << "\t|Country\t\t|Denom\t|Metal\t\t|Date\t|Value\t|Amount\t|" << endl;
    cout << "\t+-----------------------+-------+---------------+-------+-------+-------+" << endl;
    int j=0;
    do{
        tmp = ((j++==0)?bgn:tmp->nxt);
        if((tmp->date)>=x)
            cout << "\t|" << tmp->country << "\t\t|" << tmp->denom << "\t|" << tmp->met << "\t|" << tmp->date << "\t|" << tmp->value << "\t|" << tmp->amount << "\t|" <<endl;        
    }while(tmp!=end);
    cout << "\t+-----------------------+-------+---------------+-------+-------+-------+" << endl;
    cout << "\nPress any key..." << endl;
    _getch();
}   
